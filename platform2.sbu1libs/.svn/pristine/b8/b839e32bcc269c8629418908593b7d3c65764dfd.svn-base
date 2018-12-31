#ifndef __UBAC_HTTP_CLIENT_H__
#define __UBAC_HTTP_CLIENT_H__

#include <iostream>
#include "EventFax.h"
#include "TCPServer.h"
#include "TCPClient.h"

#include <ubacsslinterface/Digest.h>
#include <ubacutils/Base64.h>
#include <ubacutils/IFHelper.h>

namespace UBACIPC
{

	class HTTPServerRequest
	{
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

	class HTTPResponse
	{
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
			virtual void onRequest(HTTPServerRequest * request) {}
			virtual void onHeaderExpectContinue(string, string, string) {}

		private:
			void parse(string);
			void parseMethod(string);
			void parseOthers(string);

			HTTPServerRequest * request;

			int crlf_count;
			int endOfHeader;
			string sBuffer;
	};

	class HTTPClient :
		public TCPClient,
		public HTTPParser
	{

		public:
			HTTPClient(int fd, bool bForceHttps = false);
			~HTTPClient();

			void receive_data(void *ptr, size_t len);
			void onRequest(HTTPServerRequest * request);
			void onHeaderExpectContinue(string, string, string);

			bool send(HTTPResponse & response);
			bool send(string & response);

			virtual void release() {}
			virtual void onHTTPConGetRequest( HTTPServerRequest * request ) {}
			virtual void onHTTPConPostRequest( HTTPServerRequest * request ) {}

		private:
			bool bForceHttps;
	};

};

#endif /* __UBAC_TCP_CLIENT_H__ */
