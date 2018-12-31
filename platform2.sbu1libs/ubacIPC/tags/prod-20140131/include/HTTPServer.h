#ifndef __UBAC_HTTP_SERVER_H__
#define __UBAC_HTTP_SERVER_H__

#include <iostream>
#include "EventFax.h"
#include "TCPServer.h"
#include "TCPClient.h"
#include "Thread.h"
#include "Mutex.h"

#include <ubacsslinterface/Digest.h>
#include <ubacutils/Base64.h>
#include <ubacutils/IFHelper.h>

namespace ubac {

	class HTTPServerRequest {
		public:
			HTTPServerRequest() {}
			~HTTPServerRequest() {}
			map<string, string> headers;
			string sContent;
			string url;
			string peerIP;
			string peerPort;
			string sMethod;
			string sHttpVersion;
	};

	class HTTPResponse {
		public:
			HTTPResponse(const string sStatus);
			~HTTPResponse();

			const static string switching_protocols;
			const static string websocket_protocol_handshake;
			const static string ok;
			const static string created;
			const static string accepted;
			const static string no_content;
			const static string multiple_choices;
			const static string moved_permanently;
			const static string moved_temporarily;
			const static string not_modified;
			const static string bad_request;
			const static string unauthorized;
			const static string forbidden;
			const static string not_found;
			const static string internal_server_error;
			const static string not_implemented;
			const static string bad_gateway;
			const static string service_unavailable;
		
			/// Set content.
			void setContent(string sContent);
			/// Set header.
			void setHeader(string sKey, string sValue);
			/// Set headers.
			void setHeaders(map<string, string> headers);
			/// Make response.
			string toString();

		private:
			/// The headers to be included in the reply.
			map<string, string> headers;
			/// The conten to be sent in the reply.
			string sContent;
			/// The status.
			string sStatus;

	};

	class HTTPParser
	{
		protected:
			HTTPParser();
			~HTTPParser();

		public:
			void handle_packet(void *data, size_t len);
			virtual void onRequest(HTTPServerRequest request) {}
			virtual void onHeaderExpectContinue(string, string, string) {}

		private:
			void parse(string);
			void parseMethod(string);
			void parseOthers(string);

			HTTPServerRequest request;

			int crlf_count;
			int endOfHeader;
			string sBuffer;
	};

	class HTTPConnection ;
	class WebSocketConnection;

	class WebSocketService {
		public:
			WebSocketService(string sProtocol) {};
			virtual ~WebSocketService() {}

			virtual void onHandshakeRequest() {}
			virtual void onHandshakeComplete() {}
			virtual void onMessage(string s, WebSocketConnection *connection) {}
			virtual void onMessage(void *d, size_t len, WebSocketConnection *connection) {}
			virtual void createNewWebsocket( int fd, EventFax *fax) {}
	};

	class WebService {
		public:
			WebService(string sRoot);
			~WebService();

			virtual void onGetRequest(HTTPServerRequest request, HTTPConnection *client) {}
			virtual void onPostRequest(HTTPServerRequest request, HTTPConnection *client) {}
			virtual void onClosingConnection(HTTPConnection *client) {}
			virtual void createNewHttpsocket( int fd, EventFax *fax) {}
			
			void markToDisconnect(HTTPConnection *);
			vector<HTTPConnection *> & getConnectionsToClean();

		private:
			vector<HTTPConnection *>vConnections;
	};

	class WebSocketConnection : 
		public TCPClient,
		public HTTPParser
	{
		public:
			WebSocketConnection(WebSocketService *service, int fd);
			~WebSocketConnection();

			void receive_data(void *ptr, size_t len);
			void onRequest(HTTPServerRequest request);
//			void unbind();
			bool send(string response);
			virtual void onMessageinWebsocket( string data ) {}

			const static string WEBSOCKET_MAGIC_KEY;
			const static uint8_t WebSocket_PROTOCOL_00;
			const static uint8_t WebSocket_PROTOCOL_06;
		private:
			WebSocketService * service;
			bool bMark;
			bool bHandshakeComplete;

			void handle_frame_packet(void *data, size_t len);
			void handle_byte(unsigned char byte);

			uint8_t iWebSocketProtocolVersion;

			struct websocket_frame_t {
				uint8_t fin, rsv1, rsv2, rsv3;
				uint8_t opcode;
				uint8_t isMasked;
				char payload_length[8];
				char c_masking_key[4];
				uint8_t uMaskIndex;
				uint64_t uLengthCopied;
				uint8_t noOfBytesOfPayloadLength;
				char *data;
				uint64_t length;
			};

			struct websocket_frame_t websocket_frame;
			const static uint8_t FRAME_STATE_UNKNOWN;
			const static uint8_t FRAME_STATE_GOT_OPCODE;
			const static uint8_t FRAME_STATE_GOT_READING_LENGTH;
			const static uint8_t FRAME_STATE_GOT_LENGTH;
			const static uint8_t FRAME_STATE_GOT_MASKING_KEY;
			const static uint8_t FRAME_STATE_GOT_COMPLETE_FRAME;

			uint8_t uFrameState;
	};
	class HTTPConnection : 
		public TCPClient,
		public HTTPParser
	{
		public:
			HTTPConnection(WebService *service, int fd, bool bForceHttps = false);
			~HTTPConnection();

			void receive_data(void *ptr, size_t len);
			void onRequest(HTTPServerRequest request);
			void onHeaderExpectContinue(string, string, string);
//			void unbind();
			void markToDisconnect(bool bMark);
//			void send(HTTPResponse response);
			bool send(HTTPResponse response);
			void release();
			virtual void onHTTPConGetRequest( string request ){}
			virtual void onHTTPConPostRequest( string request ) {}

		private:
			WebService * service;
			bool bMark, bForceHttps;
	};

	class HTTPServer :
		public Thread,
		public TCPServer
	{
		public:
			HTTPServer(string sPort, WebService * service, bool bForceHttps = false);
			HTTPServer(string sPort, WebSocketService * service);
			HTTPServer(int iPort);

			~HTTPServer();

			void createNewClient(int fd);
			void run();
			void eraseConnection(HTTPConnection *);
			void cleanupHTTPConnections();

		private:
			EventFax fax;
			WebService * service;
			WebSocketService *wsService;
			bool bForceHttps;
			void eraseConnection(int fd);

			map<int, HTTPConnection *>connectionMap;
	};
};

using namespace ubac;

#endif /* __UBAC_HTTP_SERVER_H__ */
