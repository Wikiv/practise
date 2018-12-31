#ifndef __UBAC_HTTP_SERVER_H__
#define __UBAC_HTTP_SERVER_H__

#include "HTTPClient.h"

namespace UBACIPC
{

	class HTTPListner;

	class HTTPConnection :
		public HTTPClient
	{
		public:
			HTTPConnection(HTTPListner *httpListner, int fd, bool bForceHttps = false);
			~HTTPConnection();

			bool isMarkedForDisconnection();
			void release();

			void onHTTPConGetRequest( HTTPServerRequest * request ) ;
			void onHTTPConPostRequest( HTTPServerRequest * request ) ;

		private:
			HTTPListner * httpListner;
			bool bMarkToDisconnect;
	};

	class HTTPListner
	{
		public:
			HTTPListner() {}
			~HTTPListner() {}

			virtual void onGetRequest(HTTPServerRequest * request,
									  HTTPConnection *client) {}

			virtual void onPostRequest(HTTPServerRequest * request,
									   HTTPConnection *client) {}

	};

	class HTTPServer :
		public TCPServer
	{
		public:
			HTTPServer(int port, EventFax * fax, HTTPListner * httpListner,
					   bool bForceHttps = false);

			HTTPServer(int port, HTTPListner *httpListner, bool bForceHttps = false);

			void setFax(EventFax *fax);

			~HTTPServer();

			void createNewClient(int fd);
			void cleanupHTTPConnections();

		private:
			EventFax * fax;
			HTTPListner * httpListner;
			bool bForceHttps;
			vector <HTTPConnection *> vConnections;
	};
};

#endif /* __UBAC_HTTP_SERVER_H__ */
