#include "HTTPServer.h"

const string HTTPResponse::switching_protocols = "HTTP/1.1 101 Switching Protocols\r\n";
const string HTTPResponse::websocket_protocol_handshake = "HTTP/1.1 101 WebSocket Protocol Handshake\r\n";
const string HTTPResponse::ok = "HTTP/1.1 200 OK\r\n";
const string HTTPResponse::created = "HTTP/1.1 201 Created\r\n";
const string HTTPResponse::accepted = "HTTP/1.1 202 Accepted\r\n";
const string HTTPResponse::no_content = "HTTP/1.1 204 No Content\r\n";
const string HTTPResponse::multiple_choices = "HTTP/1.1 300 Multiple Choices\r\n";
const string HTTPResponse::moved_permanently = "HTTP/1.1 301 Moved Permanently\r\n";
const string HTTPResponse::moved_temporarily = "HTTP/1.1 302 Moved Temporarily\r\n";
const string HTTPResponse::not_modified = "HTTP/1.1 304 Not Modified\r\n";
const string HTTPResponse::bad_request = "HTTP/1.1 400 Bad Request\r\n";
const string HTTPResponse::unauthorized = "HTTP/1.1 401 Unauthorized\r\n";
const string HTTPResponse::forbidden = "HTTP/1.1 403 Forbidden\r\n";
const string HTTPResponse::not_found = "HTTP/1.1 404 Not Found\r\n";
const string HTTPResponse::internal_server_error = "HTTP/1.1 500 Internal Server Error\r\n";
const string HTTPResponse::not_implemented = "HTTP/1.1 501 Not Implemented\r\n";
const string HTTPResponse::bad_gateway = "HTTP/1.1 502 Bad Gateway\r\n";
const string HTTPResponse::service_unavailable = "HTTP/1.1 503 Service Unavailable\r\n";

static void cleanupHTTPConnections(void *data)
{
	HTTPServer *httpServer = static_cast<HTTPServer *>(data);
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
	for(map<string, string>::iterator iHeader = headers.begin(); iHeader != headers.end(); iHeader++) {
		sResponse = sResponse + iHeader->first + ": " + iHeader->second + "\r\n";
	}
	sResponse = sResponse + "\r\n" + sContent;
	return sResponse;
}

WebService::WebService(string sRoot)
{
}

WebService::~WebService()
{
}

void WebService::markToDisconnect(HTTPConnection *connection)
{
	vConnections.push_back( connection );
}

vector<HTTPConnection *> & WebService::getConnectionsToClean()
{
	return vConnections;
}


HTTPConnection::HTTPConnection(WebService *service, int fd, bool bForceHttps) : TCPClient(fd)
{
	this->bForceHttps = bForceHttps;
	bMark = true;
	this->service = service;
}

HTTPConnection::~HTTPConnection()
{
}

void HTTPConnection::release()
{
	this->closeConnection();
}

/*void HTTPConnection::send(HTTPResponse response)
{
	string sResponse = response.toString();
	this->writen(this->descriptor, sResponse.c_str(), sResponse.length());
}*/

bool HTTPConnection::send(HTTPResponse response)
{
	int status;
	string sResponse = response.toString();
	status = this->writen(this->descriptor, sResponse.c_str(), sResponse.length());
	return ( status > 0 );
}

void HTTPConnection::markToDisconnect(bool bMark)
{
	this->bMark = bMark;
}

void HTTPConnection::receive_data(void *ptr, size_t len)
{
	handle_packet(ptr, len);
}

void HTTPConnection::onRequest(HTTPServerRequest request)
{
	if( ( (request.sMethod.compare("POST") == 0) && (request.sContent.length() == 0) ) || ( (request.sMethod.compare("GET") == 0) && (request.sContent.compare("/") == 0) ) ) {
		HTTPResponse httpResponse(HTTPResponse::ok);
		this->send(httpResponse);
		service->markToDisconnect( this );
		return;
	}
	if( bForceHttps && (request.headers["X-Forwarded-Proto"].compare("https") != 0) ) {
		HTTPResponse httpResponse(HTTPResponse::ok);
		httpResponse.setHeader("Content-Type", "text/json");
		httpResponse.setContent( "640 <Invalid Protocol>" );
		this->send( httpResponse );
		return;
	}
	if( request.sMethod == "GET" ) {
		service->onGetRequest(request, this);
		onHTTPConGetRequest( request.sContent );
	} else if( request.sMethod == "POST" ) {
		service->onPostRequest(request, this);
		onHTTPConPostRequest( request.sContent );
	}
//	if( bMark )
//		service->markToDisconnect( this );
}

void HTTPConnection::onHeaderExpectContinue(string sHeaderKey, string sHeaderValue, string sHttpVersion)
{
	IFHelper helper;
	helper.gsub(sHeaderKey, "-", " ");
	string sResponse = sHttpVersion + " " + sHeaderValue + "\r\n\r\n";
	this->writen(this->descriptor, sResponse.c_str(), sResponse.length());
}

/*void HTTPConnection::unbind()
{
	service->onClosingConnection(this);
}*/

const string WebSocketConnection::WEBSOCKET_MAGIC_KEY = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
const uint8_t WebSocketConnection::FRAME_STATE_UNKNOWN = 1;
const uint8_t WebSocketConnection::FRAME_STATE_GOT_OPCODE = 2;
const uint8_t WebSocketConnection::FRAME_STATE_GOT_READING_LENGTH = 3;
const uint8_t WebSocketConnection::FRAME_STATE_GOT_LENGTH = 4;
const uint8_t WebSocketConnection::FRAME_STATE_GOT_MASKING_KEY = 5;
const uint8_t WebSocketConnection::FRAME_STATE_GOT_COMPLETE_FRAME = 6;
const uint8_t WebSocketConnection::WebSocket_PROTOCOL_00 = 1;
const uint8_t WebSocketConnection::WebSocket_PROTOCOL_06 = 2;

WebSocketConnection::WebSocketConnection(WebSocketService *service, int fd) : TCPClient(fd)
{
	uFrameState = FRAME_STATE_UNKNOWN;
	bHandshakeComplete = false;
	this->service = service;
}

WebSocketConnection::~WebSocketConnection()
{
}

void WebSocketConnection::receive_data(void *data, size_t len)
{
	if( !bHandshakeComplete )
		handle_packet(data, len);
	else
		handle_frame_packet(data, len);
}

void WebSocketConnection::handle_byte(unsigned char byte)
{
//	printf("Handle byte: byte = %x - %d when frame state is %d\n", byte, byte, uFrameState);
	if( uFrameState == FRAME_STATE_UNKNOWN ) {
		websocket_frame.fin = byte & 128;
		websocket_frame.rsv1 = byte & 64;
		websocket_frame.rsv2 = byte & 32;
		websocket_frame.rsv3 = byte & 16;
		websocket_frame.opcode = byte & 15;
		uFrameState = FRAME_STATE_GOT_OPCODE;
	} else if( uFrameState == FRAME_STATE_GOT_OPCODE ) {
		websocket_frame.isMasked = byte & 128;
		websocket_frame.length = byte & 127;
//		cout << "websocket_frame.length = " << websocket_frame.length << endl;
		if( websocket_frame.length <= 0x7D ) {
			uFrameState = FRAME_STATE_GOT_LENGTH;
			websocket_frame.uMaskIndex = 0;
			websocket_frame.uLengthCopied = 0;
		} else if( websocket_frame.length == 0x7E ) {
			uFrameState = FRAME_STATE_GOT_READING_LENGTH;
			websocket_frame.noOfBytesOfPayloadLength = 2;
		} else if( websocket_frame.length == 0x7F ) {
			uFrameState = FRAME_STATE_GOT_READING_LENGTH;
			websocket_frame.noOfBytesOfPayloadLength = 8;
		}
	} else if( uFrameState == FRAME_STATE_GOT_READING_LENGTH ) {
		if( websocket_frame.length == 0x7E ) {
			websocket_frame.payload_length[2 - websocket_frame.noOfBytesOfPayloadLength] = byte;
		} else if( websocket_frame.length == 0x7F ) {
			websocket_frame.payload_length[8 - websocket_frame.noOfBytesOfPayloadLength] = byte;
		}
		websocket_frame.noOfBytesOfPayloadLength--;
		if( websocket_frame.noOfBytesOfPayloadLength == 0 ) {
			IFHelper helper;
			void *p = &websocket_frame.payload_length[0];
			if( websocket_frame.length == 0x7E ) {
//				for(size_t i = 0; i < 2; i++) 
//					printf("%lu - %u\n", i, websocket_frame.payload_length[i]);
				websocket_frame.length = helper.readU16(p);
			} else if( websocket_frame.length == 0x7F ) {
//				for(size_t i = 0; i < 2; i++) 
//					printf("%lu - %u\n", i, websocket_frame.payload_length[i]);
				double d = helper.readDouble(p);
				uint64_t *ld = (uint64_t *)&d;
				websocket_frame.length = *ld;
			}
			uFrameState = FRAME_STATE_GOT_LENGTH;
			websocket_frame.uMaskIndex = 0;
			websocket_frame.uLengthCopied = 0;
		}
	} else if( uFrameState == FRAME_STATE_GOT_LENGTH ) {
		if( websocket_frame.uLengthCopied == 0 )
			websocket_frame.data = (char *)calloc(1, websocket_frame.length);
		cout << "Got length: " << websocket_frame.length << endl;
		if( websocket_frame.isMasked ) {
			websocket_frame.c_masking_key[websocket_frame.uMaskIndex++] = byte;
			if( websocket_frame.uMaskIndex == 4 ) {
				uFrameState = FRAME_STATE_GOT_MASKING_KEY;
				websocket_frame.uMaskIndex = 0;
			}
		} else {
			//Copy data.
			*(websocket_frame.data + websocket_frame.uLengthCopied) = byte;
			websocket_frame.uLengthCopied++;
			if( websocket_frame.uLengthCopied == websocket_frame.length ) 
				uFrameState = FRAME_STATE_GOT_COMPLETE_FRAME;
		}
	} else if( uFrameState == FRAME_STATE_GOT_MASKING_KEY ) {
		//Copy data.
//		cout << __LINE__ << ": websocket_frame.uLengthCopied = " << websocket_frame.uLengthCopied << endl;
		*(websocket_frame.data + websocket_frame.uLengthCopied) = byte ^ websocket_frame.c_masking_key[websocket_frame.uMaskIndex%4];
		websocket_frame.uMaskIndex++;
		websocket_frame.uLengthCopied++;
		if( websocket_frame.uLengthCopied == websocket_frame.length )  {
			uFrameState = FRAME_STATE_GOT_COMPLETE_FRAME;
//			cout << "Got complete frame" << endl;
//			service->onMessage( string(websocket_frame.data, websocket_frame.length), this );
			onMessageinWebsocket( string(websocket_frame.data, websocket_frame.length) );
			free(websocket_frame.data);
			websocket_frame.data = NULL;
			memset(&websocket_frame, '\0', sizeof(struct websocket_frame_t));
			uFrameState = FRAME_STATE_UNKNOWN;
		}
	} else if( uFrameState == FRAME_STATE_GOT_COMPLETE_FRAME ) {
	}
}

void WebSocketConnection::handle_frame_packet(void *data, size_t len)
{
	if( this->iWebSocketProtocolVersion == WebSocketConnection::WebSocket_PROTOCOL_00 ) {
//		service->onMessage( string((char *)data + 1, len-2), this );
		onMessageinWebsocket( string((char *)data + 1, len-2) );
	} else if( this->iWebSocketProtocolVersion == WebSocketConnection::WebSocket_PROTOCOL_06 ) {
		cout << "Received buffer with length " << len << endl;
		unsigned char *c_data = (unsigned char *)data;
		for(size_t i = 0; i < len; i++) {
			unsigned char c = *(c_data + i);
			handle_byte( c );
		}
	}
}


void WebSocketConnection::onRequest(HTTPServerRequest request)
{
	if( request.sMethod == "GET" ) {
		cout << "method is GET" << endl;
		if( request.headers["Sec-WebSocket-Key"].length() > 0 ) {
			cout << "in Get Sec-WebSocket-Key" << endl;
			service->onHandshakeRequest();
			string sAcceptKey, shaValue;
			string sInput = request.headers["Sec-WebSocket-Key"] + WEBSOCKET_MAGIC_KEY;
			Digest digest;
			digest.sha1sum(sInput.c_str(), sInput.length(), shaValue);

			char sha_buffer[1024] = {'\0'};
			size_t sha_buffer_len = 0;
			for(size_t i = 2; i <= shaValue.length(); i += 2) {
				char c[2] = {shaValue[i-2], shaValue[i-1]};
				sha_buffer[sha_buffer_len] = strtol(c, NULL, 16);
				sha_buffer_len++;
			}
			Base64 base64;
			base64.encode(string(sha_buffer, sha_buffer_len), sAcceptKey);
			IFHelper helper;
			helper.rstrip(sAcceptKey, '\n');

			HTTPResponse response(HTTPResponse::switching_protocols);
			response.setHeader("Connection", "Upgrade");
			response.setHeader("Upgrade", "websocket");
			response.setHeader("Sec-WebSocket-Accept", sAcceptKey);
			string sToWrite = response.toString();
			this->writen(this->descriptor, sToWrite.c_str(), sToWrite.length());
			bHandshakeComplete = true;
			this->iWebSocketProtocolVersion = WebSocketConnection::WebSocket_PROTOCOL_06;
			service->onHandshakeComplete();
			cout << "protocol version set as " << (int) this->iWebSocketProtocolVersion << endl;
		} else {
			service->onHandshakeRequest();
			cout << "Printing header." << endl;
			for(map<string, string>::iterator iString = request.headers.begin(); iString != request.headers.end(); iString++) 
				cout << iString->first << ": " << iString->second << endl;
			string sKey1 = request.headers["Sec-WebSocket-Key1"];
			string sKey2 = request.headers["Sec-WebSocket-Key2"];
			string s1, s2;
			int count_spaces1 = 0, count_spaces2 = 0;
			for(size_t i = 0; i < sKey1.length(); i++ ) {
				if( isdigit(sKey1[i]) > 0 ) 
					s1.append(&sKey1[i], 1);
				else if( sKey1[i] == ' ' )
					count_spaces1++;
			}
			for(size_t i = 0; i < sKey2.length(); i++ ) {
				if( isdigit(sKey2[i]) > 0 ) 
					s2.append(&sKey2[i], 1);
				else if( sKey2[i] == ' ' )
					count_spaces2++;
			}
			uint32_t i1 = atol(s1.c_str())/count_spaces1;
			uint32_t i2 = atol(s2.c_str())/count_spaces2;
			cout << "s1 = " << s1 << ", count = " << count_spaces1 << ", int " << i1 << endl;
			cout << "s2 = " << s2 << ", count = " << count_spaces2 << ", int " << i2 << endl;
			for(size_t i = 0; i < request.sContent.length(); i++)
				printf("%c - %d\n", request.sContent[i], request.sContent[i]);
			uint32_t bi1 = htonl(i1);
			uint32_t bi2 = htonl(i2);
			unsigned char c_buffer[128] = {'\0'};
			memcpy(&c_buffer[0], &bi1, sizeof(uint32_t));
			memcpy(&c_buffer[sizeof(uint32_t)], &bi2, sizeof(uint32_t));
			memcpy(&c_buffer[(2*sizeof(uint32_t))], request.sContent.c_str(), 8);
			for(size_t i = 0; i < 16; i++ )
				printf("Bytes = %u - %x\n", c_buffer[i], c_buffer[i]);
			Digest d;
			string md5Token;
			d.digest(c_buffer, 16, Digest::DigestType_MD5, md5Token);
			cout << "md5Token = " << md5Token << endl;
	
			string sResponse( HTTPResponse::websocket_protocol_handshake );
			sResponse = sResponse + "Upgrade: WebSocket\r\n";	
			sResponse = sResponse + "Connection: Upgrade\r\n";
			sResponse = sResponse + "Sec-WebSocket-Origin: " + request.headers["Origin"] + "\r\n";
			sResponse = sResponse + "Sec-WebSocket-Location: ws://" + request.headers["Host"] + "/\r\n\r\n";
			size_t sha_buffer_len = 0;
			memset(c_buffer, '\0', sizeof(c_buffer));
			for(size_t i = 2; i <= md5Token.length(); i += 2) {
				char c[2] = {md5Token[i-2], md5Token[i-1]};
				c_buffer[sha_buffer_len] = strtol(c, NULL, 16);
				sha_buffer_len++;
			}
			printf("md5 = %s\n", c_buffer);
			this->sendData( sResponse );
			this->writen(this->descriptor, (const char *)&c_buffer[0], sha_buffer_len);
			bHandshakeComplete = true;
			this->iWebSocketProtocolVersion = WebSocketConnection::WebSocket_PROTOCOL_00;
			service->onHandshakeComplete();
			cout << "protocol version = " << this->iWebSocketProtocolVersion << endl;
		}
	}
}

/*void WebSocketConnection::unbind()
{
}*/

size_t copybytes(unsigned char *src, unsigned char *dest, unsigned char continuation)
{
	size_t i = 0, j = 2;
	while( *(src + i) != '\0' ) {
		*(dest + j) = *(src + i);
		i++;
		j++;
		if( i == 100 )
			break;
	}
	if( i == 100 ) {
		*dest = continuation;
		*(dest + 1) = 100;
	} else {
		*dest = 0x80;
		*(dest + 1) = (unsigned char)i;
	}
	return i;
}

void frame(string s, unsigned char *ptr, size_t & len)
{
	len = 0;
	cout << "Actual length = " << s.length() << endl;
//	unsigned char tmp_buffer[1024] = {'\0'};
	if( s.length() < 100 ) {
		*ptr = 0x81;
		*(ptr + 1) = (unsigned char)s.length();
		for(size_t i = 2, j = 0; j < s.length(); i++, j++)
			*(ptr + i) = s[j];
		len = s.length() + 2;
	} else {
		unsigned char tmp_frame[128] = {'\0'};
		unsigned char *src = (unsigned char *)s.c_str();
		size_t length_copied = 0;
		while( 1 ) {
			size_t tmp_length_copied = copybytes(src + length_copied, tmp_frame, (length_copied == 0) ? 0x01 : 0x00);
			memcpy(ptr + len, tmp_frame, tmp_length_copied + 2);
			length_copied += tmp_length_copied;
			len += tmp_length_copied + 2;
			cout << "tmp_length_copied = " << tmp_length_copied << ", length_copied = " << length_copied << ", len = " << len << endl;
			if( length_copied == s.length() )
				break;
		}
//		for(size_t i = 0; i < len; i++)
//			printf("%lu - %d - %x - %c\n", i, *(ptr + i), *(ptr + i), *(ptr + i));
	}
}

bool WebSocketConnection::send(string sResponse)
{
	int status = 0;
	cout << "sResponse in WebSocketConnection::send protocol version = " <<  this->iWebSocketProtocolVersion << endl;

	if( this->iWebSocketProtocolVersion == WebSocketConnection::WebSocket_PROTOCOL_00 ) {
		cout << "WebSocket_PROTOCOL_00 " << endl;
		this->writen( this->descriptor, "\0", 1);
		this->writen( this->descriptor, sResponse.c_str(), sResponse.length());
		char c = 0xff;
		status = this->writen( this->descriptor, &c, 1);
	} else if( this->iWebSocketProtocolVersion == WebSocketConnection::WebSocket_PROTOCOL_06 ) {
		cout << "WebSocket_PROTOCOL_06 " << endl;
		size_t len = 0;
		unsigned char *ptr = (unsigned char *)calloc(1, sResponse.length() + 100);
		frame(sResponse, ptr, len);
		status = this->writen( this->descriptor, (char *)ptr, len );
		free(ptr);
	}
	return (status > 0);
}

HTTPParser::HTTPParser()
{
	crlf_count = 0;
	endOfHeader = 0;
}

HTTPParser::~HTTPParser()
{
}

void HTTPParser::handle_packet(void *ptr, size_t len)
{
	char *s = (char *)ptr;
	for(size_t i = 0; i < len; i++) {
		char c = *(s + i);
		if(c == '\r') {
			endOfHeader++;
		} else if( c == '\n' ) {
			if( endOfHeader >= 4 ) {
				sBuffer.append(&c, 1);
				parse(sBuffer);
			} else {
				endOfHeader++;
				crlf_count++;
				parse(sBuffer);
				sBuffer.clear();
			}
		} else {
			sBuffer.append(&c, 1);
			if( endOfHeader < 4 )
				endOfHeader = 0;
		}
	}
	cout << "endOfHeader = " << endOfHeader << ", crlf_count = " << crlf_count << ", buffer = " << sBuffer << ", length = " << sBuffer.length() << endl;
	if( endOfHeader >= 4 ) {
		if( (size_t)atoi(request.headers["Content-Length"].c_str()) == sBuffer.length() ) {
			request.sContent = sBuffer;
			onRequest(request);
			sBuffer.clear();

			crlf_count = 0;
			endOfHeader = 0;
			request.headers.clear();
			request.sContent.clear();
			request.sMethod.clear();
			request.sHttpVersion.clear();
		} else {
			request.sContent = sBuffer;
			onRequest(request);
			sBuffer.clear();

			crlf_count = 0;
			endOfHeader = 0;
			request.headers.clear();
			request.sContent.clear();
			request.sMethod.clear();
			request.sHttpVersion.clear();
		}
	}
}

void HTTPParser::parseMethod(string line)
{
	int state = 0;
	string sMethod, sPath, sHTTP;
	for(size_t i = 0; i < line.length();i++) {
		if( line[i] == ' ' ) {
			state++;
		} else {
			switch(state) {
				case 0: sMethod.append(&line[i], 1); break;
				case 1: sPath.append(&line[i], 1); break;
				default: sHTTP.append(&line[i], 1); break;
			}
		}
	}
	request.sMethod = sMethod;
	request.url = sPath;
	request.sHttpVersion = sHTTP;
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
	request.headers[sHeaderKey] = sHeaderValue;
	if( line == "Expect: 100-continue" ) {
		onHeaderExpectContinue(sHeaderKey, sHeaderValue, request.sHttpVersion);
	}
}

void HTTPParser::parse(string line)
{
	if( crlf_count == 1 ) {
		parseMethod(line);
	} else if( endOfHeader >= 4 ) {
		request.sContent = line;
	} else {
		parseOthers(line);
	}
}

HTTPServer::HTTPServer(string sPort, WebService *service, bool bForceHttps) : TCPServer(atoi(sPort.c_str()))
{
	this->bForceHttps = bForceHttps;
	this->service = service;
	this->wsService = NULL;
}

HTTPServer::HTTPServer(string sPort, WebSocketService *service) : TCPServer(atoi(sPort.c_str()))
{
	this->service = NULL;
	this->wsService = service;
}

HTTPServer::HTTPServer(int iPort) : TCPServer( iPort)
{
}

HTTPServer::~HTTPServer()
{
}

void HTTPServer::createNewClient(int fd)
{
	eraseConnection(fd);
	if( service ) {
		HTTPConnection *connection = new HTTPConnection(service, fd, bForceHttps);
		connectionMap.insert( make_pair(fd, connection) );
		fax.addTCPClient( connection );
		service->createNewHttpsocket( fd, &fax);
	} else {
//		WebSocketConnection *connection = new WebSocketConnection(wsService, fd);
//		fax.addTCPClient( connection );
		wsService->createNewWebsocket( fd, &fax);
	}
}


void HTTPServer::eraseConnection(HTTPConnection *connection)
{
	TCPClient *client = static_cast<TCPClient *>(connection);
	fax.deleteTCPClient( client );
	eraseConnection( connection->descriptor );
	connection->release();
//	connection = NULL;
}

void HTTPServer::eraseConnection(int fd)
{
	map<int, HTTPConnection *>::iterator iConnection = connectionMap.find( fd );
	if( iConnection != connectionMap.end() ) {
		cout << "Erasing connection: " << fd << endl;
		connectionMap.erase( iConnection );
	}
}

void HTTPServer::cleanupHTTPConnections()
{
	if( !service ) return;
	vector<HTTPConnection *> & vConnections = service->getConnectionsToClean();
	vector<HTTPConnection *>::iterator iConnection = vConnections.begin();
	while(iConnection != vConnections.end()) {
		if( (*iConnection) ) {
			eraseConnection( *iConnection );
		}
		vConnections.erase( iConnection );
		iConnection = vConnections.begin();
	}
}

void HTTPServer::run()
{
	fax.addTCPServer( this );
	fax.addPeriodicTimer( ::cleanupHTTPConnections, this, 1 );
	fax.run();
}
