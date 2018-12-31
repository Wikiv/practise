#include "SBU2HTTPServer.h"

using namespace SBU2;

const string HTTPResponse::switching_protocols =
	"HTTP/1.1 101 Switching Protocols\r\n";
const string HTTPResponse::websocket_protocol_handshake =
	"HTTP/1.1 101 WebSocket Protocol Handshake\r\n";
const string HTTPResponse::ok = "HTTP/1.1 200 OK\r\n";
const string HTTPResponse::created = "HTTP/1.1 201 Created\r\n";
const string HTTPResponse::accepted = "HTTP/1.1 202 Accepted\r\n";
const string HTTPResponse::no_content = "HTTP/1.1 204 No Content\r\n";
const string HTTPResponse::multiple_choices =
	"HTTP/1.1 300 Multiple Choices\r\n";
const string HTTPResponse::moved_permanently =
	"HTTP/1.1 301 Moved Permanently\r\n";
const string HTTPResponse::moved_temporarily =
	"HTTP/1.1 302 Moved Temporarily\r\n";
const string HTTPResponse::not_modified = "HTTP/1.1 304 Not Modified\r\n";
const string HTTPResponse::bad_request = "HTTP/1.1 400 Bad Request\r\n";
const string HTTPResponse::unauthorized = "HTTP/1.1 401 Unauthorized\r\n";
const string HTTPResponse::forbidden = "HTTP/1.1 403 Forbidden\r\n";
const string HTTPResponse::not_found = "HTTP/1.1 404 Not Found\r\n";
const string HTTPResponse::internal_server_error =
	"HTTP/1.1 500 Internal Server Error\r\n";
const string HTTPResponse::not_implemented =
	"HTTP/1.1 501 Not Implemented\r\n";
const string HTTPResponse::bad_gateway = "HTTP/1.1 502 Bad Gateway\r\n";
const string HTTPResponse::service_unavailable =
	"HTTP/1.1 503 Service Unavailable\r\n";

static void cleanupHTTPConnections(void *data)
{
	SBU2HTTPServer *httpServer = static_cast<SBU2HTTPServer *>(data);
	httpServer->cleanupHTTPConnections();
}

HTTPResponse::HTTPResponse(const string sStatus)
{
	this->sStatus = sStatus;
}

HTTPResponse::~HTTPResponse()
{
}

void HTTPResponse::setContent(string sContent)
{
	this->sContent = sContent;
	stringstream s;
	s << sContent.length();
	setHeader("Content-Length", s.str());
}

void HTTPResponse::setHeader(string sKey, string sValue)
{
	headers[sKey] = sValue;
}

void HTTPResponse::setHeaders(map<string, string> headers)
{
	this->headers = headers;
}

string HTTPResponse::toString()
{
	string sResponse = "";
	sResponse = sResponse + sStatus;

	for(map<string, string>::iterator iHeader = headers.begin();
			iHeader != headers.end(); iHeader++) {
		sResponse = sResponse + iHeader->first + ": " + iHeader->second + "\r\n";
	}

	sResponse = sResponse + "\r\n" + sContent;
	return sResponse;
}


HTTPConnection::HTTPConnection(EventFax * fax,
							   SBU2LoadBalancer *lBalancer,
							   int fd, bool bForceHttps) : TCPClient(fd)
{
	this->bForceHttps = bForceHttps;
	this->lBalancer = lBalancer;
	this->fax  = fax;
	this->bMarkToDisconnect = false;
}

HTTPConnection::~HTTPConnection()
{
}

void HTTPConnection::release()
{
	this->fax->deleteTCPClient(this);
	this->closeConnection();
	this->bMarkToDisconnect = true;
}

void HTTPConnection::unbind()
{
	this->bMarkToDisconnect = true;
}

bool HTTPConnection::isMarkedForDisconnection()
{
	return this->bMarkToDisconnect;
}

bool HTTPConnection::send(HTTPResponse response)
{
	int status;
	string sResponse = response.toString();
	status = this->writen(this->descriptor, sResponse.c_str(), sResponse.length());
	return ( status > 0 );
}

void HTTPConnection::receive_data(void *ptr, size_t len)
{
	handle_packet(ptr, len);
}

void HTTPConnection::onRequest(HTTPServerRequest *request)
{
	if( ( (request->sMethod.compare("POST") == 0)
			&& (request->sContent.length() == 0) )
			|| ( (request->sMethod.compare("GET") == 0)
				 && (request->sContent.compare("/") == 0) ) ) {
		HTTPResponse httpResponse(HTTPResponse::ok);
		this->send(httpResponse);
		this->release();
		return;
	}

	if( bForceHttps
			&& (request->headers["X-Forwarded-Proto"].compare("https") != 0) ) {
		HTTPResponse httpResponse(HTTPResponse::not_implemented);
		this->send( httpResponse );
		return;
	}

	if( request->sMethod == "GET" ) {
		//service->onGetRequest(&request, this);
		onHTTPConGetRequest( request->sContent );

	} else if( request->sMethod == "POST" ) {
		lBalancer->addMessage(request, this);
	}

}

void HTTPConnection::onHeaderExpectContinue(string sHeaderKey,
		string sHeaderValue, string sHttpVersion)
{
	IFHelper helper;
	helper.gsub(sHeaderKey, "-", " ");
	string sResponse = sHttpVersion + " " + sHeaderValue + "\r\n\r\n";
	this->writen(this->descriptor, sResponse.c_str(), sResponse.length());
}

HTTPParser::HTTPParser()
{
	crlf_count = 0;
	endOfHeader = 0;
	request = new HTTPServerRequest();
}

HTTPParser::~HTTPParser()
{
	delete request;
}

void HTTPParser::handle_packet(void *ptr, size_t len)
{
	char *s = (char *)ptr;

	for(size_t i = 0; i < len; i++) {
		char c = *(s + i);

		if (endOfHeader >= 4) {
			// storing message-body
			sBuffer.append(&c, 1);

		} else if(c == '\r') {
			// CR
			endOfHeader++;

		} else if( c == '\n' ) {
			// LF
			endOfHeader++;
			crlf_count++;

			if (sBuffer.length() > 0) {

				// got message-header parse it.
				parse(sBuffer);
				sBuffer.clear();
			}

		} else {
			// storing message-header
			sBuffer.append(&c, 1);

			if( endOfHeader < 4 )
				endOfHeader = 0;
		}
	}

	if( endOfHeader >= 4 ) {
		size_t contentLen = (size_t) atoi(
								request->headers["Content-Length"].c_str() );

		// TODO Should check for contentLen > sBuffer.length() and throw error
		if ( contentLen <= sBuffer.length() ) {
			request->sContent = sBuffer;
			onRequest(request);

			sBuffer.clear();

			crlf_count = 0;
			endOfHeader = 0;

		} 
	}
}

void HTTPParser::parseMethod(string line)
{
	int state = 0;
	string sMethod, sPath, sHTTP;

	for(size_t i = 0; i < line.length(); i++) {
		if( line[i] == ' ' ) {
			state++;

		} else {
			switch(state) {
			case 0:
				sMethod.append(&line[i], 1);
				break;

			case 1:
				sPath.append(&line[i], 1);
				break;

			default:
				sHTTP.append(&line[i], 1);
				break;
			}
		}
	}

	request->sMethod = sMethod;
	request->url = sPath;
	cout << "path = " << sPath << endl;
	cout << "url = " << request->url << endl;
	request->sHttpVersion = sHTTP;
}

void HTTPParser::parseOthers(string line)
{
	int state = 0;
	string sHeaderKey, sHeaderValue;

	for(size_t i = 0; i < line.length(); i++) {
		if( (line[i] == ':') && (state == 0) ) {
			state++;

		} else {
			if( state == 0 ) {
				sHeaderKey.append(&line[i], 1);

			} else {
				if( !((sHeaderValue.length() == 0) && (line[i] == ' ')) )
					sHeaderValue.append(&line[i], 1);
			}
		}
	}

	cout << sHeaderKey << ": " << sHeaderValue << endl;
	request->headers[sHeaderKey] = sHeaderValue;

	if( line == "Expect: 100-continue" ) {
		onHeaderExpectContinue(sHeaderKey, sHeaderValue, request->sHttpVersion);
	}
}

void HTTPParser::parse(string line)
{
	if( crlf_count == 1 ) {
		parseMethod(line);

	} else {
		parseOthers(line);
	}
}

SBU2HTTPServer::SBU2HTTPServer(string sPort, SBU2LoadBalancer *balancer,
							   bool bForceHttps) : TCPServer(atoi(sPort.c_str()))
{
	this->bForceHttps = bForceHttps;
	this->lBalancer = balancer;
}

SBU2HTTPServer::SBU2HTTPServer(int iPort) : TCPServer( iPort)
{
}

SBU2HTTPServer::~SBU2HTTPServer()
{
}

void SBU2HTTPServer::createNewClient(int fd)
{
	cout << "SBU2HTTPServer::createNewClient Fd: " << fd << endl;
	HTTPConnection *connection = new HTTPConnection(&fax, lBalancer, fd,
			bForceHttps);

	vConnections.push_back( connection );
	fax.addTCPClient( connection );
}


void SBU2HTTPServer::cleanupHTTPConnections()
{
	vector<HTTPConnection *>::iterator iConnection;

	for(iConnection	= vConnections.begin(); iConnection != vConnections.end();) {

		if ( (* iConnection)->isMarkedForDisconnection()) {
			delete (* iConnection);
			iConnection = vConnections.erase( iConnection );

		} else { 
			iConnection++;
		}
	}
}

void SBU2HTTPServer::run()
{
	fax.addTCPServer( this );
	fax.addPeriodicTimer( ::cleanupHTTPConnections, this, 1 );
	fax.run();
}
