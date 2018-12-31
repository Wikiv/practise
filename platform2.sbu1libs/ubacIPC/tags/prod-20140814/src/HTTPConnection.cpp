#include "HTTPServer.h"

HTTPConnection::HTTPConnection(HTTPListner *httpListner, int fd,
							   bool bForceHttps) : HTTPClient( fd, bForceHttps)
{
	this->bMarkToDisconnect = false;
	this->httpListner = httpListner;
}

HTTPConnection::~HTTPConnection()
{
}

void HTTPConnection::release()
{
	this->bMarkToDisconnect = true;
}

bool HTTPConnection::isMarkedForDisconnection()
{
	return this->bMarkToDisconnect;
}


void HTTPConnection::onHTTPConGetRequest(HTTPServerRequest * request)
{
	this->httpListner->onGetRequest( request, this );
}

void HTTPConnection::onHTTPConPostRequest(HTTPServerRequest * request)
{
	this->httpListner->onPostRequest ( request, this );
}
