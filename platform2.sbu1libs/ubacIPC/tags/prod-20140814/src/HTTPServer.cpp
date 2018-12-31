#include "HTTPServer.h"

static void cleanupHTTPConnections(void *data)
{
	HTTPServer *httpServer = static_cast<HTTPServer *>(data);
	httpServer->cleanupHTTPConnections();
}


HTTPServer::HTTPServer(int port, EventFax * fax,
					   HTTPListner *httpListner, bool bForceHttps)
	: TCPServer(port)
{
	this->bForceHttps = bForceHttps;
	this->httpListner = httpListner;
	this->fax = fax;

	this->fax->addPeriodicTimer( ::cleanupHTTPConnections, this, 1);
}

HTTPServer::~HTTPServer()
{
}

void HTTPServer::createNewClient(int fd)
{
	HTTPConnection *connection = new HTTPConnection(httpListner, fd, bForceHttps);
	vConnections.push_back( connection );
	fax->addTCPClient( connection );
}



void HTTPServer::cleanupHTTPConnections()
{
	vector<HTTPConnection *>::iterator iConnection;

	for(iConnection = vConnections.begin(); iConnection != vConnections.end();) {

		if ( (* iConnection)->isMarkedForDisconnection()) {
			this->fax->deleteTCPClient( * iConnection);

			(* iConnection)->closeConnection();

			delete (* iConnection);
			iConnection = vConnections.erase( iConnection );

		} else {
			iConnection++;
		}
	}
}
