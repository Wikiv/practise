#include "HTTPClient.h"

HTTPClient::HTTPClient(int fd, bool bForceHttps) : TCPClient(fd)
{
	this->bForceHttps = bForceHttps;
}

HTTPClient::~HTTPClient()
{
}

bool HTTPClient::send(HTTPResponse & response)
{
	string sResponse = response.toString();
	return send( sResponse );
}

bool HTTPClient::send(string & response)
{
	int val = fcntl (this->descriptor, F_GETFL, 0);
	val ^= O_NONBLOCK;
	fcntl (descriptor ,F_SETFL, val);

	int status = this->writen(this->descriptor, response.c_str(),
							  response.length());

	fcntl (descriptor ,F_SETFL, val | O_NONBLOCK);

	return ( status > 0 );
}

void HTTPClient::receive_data(void *ptr, size_t len)
{
	handle_packet(ptr, len);
}

void HTTPClient::onRequest(HTTPServerRequest * request)
{
	if( bForceHttps
			&& (request->headers["X-Forwarded-Proto"].compare("https") != 0) ) {

		HTTPResponse httpResponse(HTTPResponse::not_implemented);
		this->send( httpResponse );
		this->release();
		return;
	}

	if( request->sMethod == "GET" ) {

		onHTTPConGetRequest( request );

	} else if( request->sMethod == "POST" ) {

		onHTTPConPostRequest( request );
	} else  {
        release();
    }
}

void HTTPClient::onHeaderExpectContinue(string sHeaderKey,
										string sHeaderValue, string sHttpVersion)
{
	IFHelper helper;
	helper.gsub(sHeaderKey, "-", " ");
	string sResponse = sHttpVersion + " " + sHeaderValue + "\r\n\r\n";

	this->send( sResponse );
}
