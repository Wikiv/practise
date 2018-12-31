#include "HTTPClient.h"

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
