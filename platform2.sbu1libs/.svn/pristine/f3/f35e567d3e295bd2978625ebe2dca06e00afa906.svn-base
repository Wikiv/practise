#ifndef __SBU2_HTTP_SERVER_H__
#define __SBU2_HTTP_SERVER_H__

#include <iostream>

#include <ubacipc/EventFax.h>
#include <ubacipc/TCPServer.h>
#include <ubacipc/TCPClient.h>
#include <ubacipc/Thread.h>
#include <ubacipc/Mutex.h>
#include <ubacsslinterface/Digest.h>
#include <ubacutils/Base64.h>
#include <ubacutils/IFHelper.h>

#include "SBU2MessageQueue.h"


namespace SBU2
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
			virtual void onRequest(HTTPServerRequest *request) {}
			virtual void onHeaderExpectContinue(string, string, string) {}

		private:
			void parse(string);
			void parseMethod(string);
			void parseOthers(string);

			HTTPServerRequest *request;

			int crlf_count;
			int endOfHeader;
			string sBuffer;
	};

	class HTTPConnection ;

	class WebService
	{
		public:
			WebService() {}
			~WebService() {}

			virtual void onGetRequest(HTTPServerRequest *request,
									  HTTPConnection *client) {}
			virtual void onPostRequest(HTTPServerRequest *request,
									   HTTPConnection *client) {}
	};

	class SBU2LoadBalancer;
	class SBU2HTTPServer;

	class HTTPConnection :
		public TCPClient,
		public HTTPParser
	{
		public:
			HTTPConnection(EventFax * fax,
						   SBU2LoadBalancer *lBalancer, int fd,
						   bool bForceHttps = false);
			~HTTPConnection();

			void receive_data(void *ptr, size_t len);
			void onRequest(HTTPServerRequest *request);
			void onHeaderExpectContinue(string, string, string);
			bool send(HTTPResponse response);
			bool isMarkedForDisconnection();
			void release();
			void unbind();
			virtual void onHTTPConGetRequest( string request ) {}
			virtual void onHTTPConPostRequest( string request ) {}

		private:
			bool bForceHttps;
			bool bMarkToDisconnect;
			SBU2LoadBalancer *lBalancer;
			EventFax * fax;
	};

	class SBU2HTTPServer :
		public Thread,
		public TCPServer
	{
		public:
			SBU2HTTPServer(string sPort, WebService * service, bool bForceHttps = false);
			SBU2HTTPServer(string sPort, SBU2LoadBalancer *lBalancer,
						   bool bForceHttps = false);
			SBU2HTTPServer(int iPort);

			~SBU2HTTPServer();

			void createNewClient(int fd);
			void run();
			void cleanupHTTPConnections();

		private:
			EventFax fax;
			SBU2LoadBalancer *lBalancer;
			vector <HTTPConnection *> vConnections;
			bool bForceHttps;
	};

	class SBU2MessageActor :
		public Thread
	{
		public:
			/** Create SBU2MessageActor, which will receive all requests to be handled by the
			  * respective application service */
			SBU2MessageActor(map<string, WebService *> *mJsonWebservice);
			~SBU2MessageActor();

			/// Add message to the queue.
			void addMessage(HTTPServerRequest *message, void *ptr);
			/// Run in loop. Keep waiting for requests and process as and when received.
			void run();

		private:
			MessageQueue< map<HTTPServerRequest *, void *> > *messageQ;
			Mutex *mutex;
			map<string, WebService *> *mJsonWebservice;
	};

	class SBU2LoadBalancer
	{
		public:
			/// Create LoadBalancer.
			SBU2LoadBalancer();
			SBU2LoadBalancer(int poolSize, map<string, WebService *> *mJsonWebservice);
			~SBU2LoadBalancer();

			/** Add Actor, which will be added to the available list for round-robin.
			  * Soon after creating the LoadBalancer, add the available `actor' objects
			  * before starting to handle messages. */
			void addActor(SBU2MessageActor * actor);
			/// Add a request to the next `Actor. `ptr' is the data to be handled after processing the request.
			void addMessage(HTTPServerRequest *message, void *ptr);

		private:
			vector<SBU2MessageActor *>actorList;
			size_t loadItem;
	};

};

#endif /* __SBU2_HTTP_SERVER_H__ */
