/*
 * Implementation is based on -- https://tools.ietf.org/html/rfc6455
 */

#include "WebSocketClient.h"

const string WebSocketClient::WEBSOCKET_MAGIC_KEY = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

const uint8_t WebSocketClient::FRAME_STATE_UNKNOWN = 1;
const uint8_t WebSocketClient::FRAME_STATE_GOT_OPCODE = 2;
const uint8_t WebSocketClient::FRAME_STATE_GOT_READING_LENGTH = 3;
const uint8_t WebSocketClient::FRAME_STATE_GOT_LENGTH = 4;
const uint8_t WebSocketClient::FRAME_STATE_GOT_MASKING_KEY = 5;
const uint8_t WebSocketClient::FRAME_STATE_GOT_COMPLETE_FRAME = 6;

const uint8_t WebSocketClient::WebSocket_PROTOCOL_UNKNOWN = 0;
const uint8_t WebSocketClient::WebSocket_PROTOCOL_00 = 1;
const uint8_t WebSocketClient::WebSocket_PROTOCOL_06 = 2;

const uint16_t WebSocketClient::STATUS_CODE_NORMAL_CLOSURE = 1000;
const uint16_t WebSocketClient::STATUS_CODE_PROTOCOL_ERROR = 1002;

const string WebSocketClient::STATUS_MSG_NORMAL_CLOSURE = "Normal Closure";
const string WebSocketClient::STATUS_MSG_PROTOCOL_ERROR = "Protocol Error";

const uint8_t WebSocketClient::OPCODE_CONTINUATION_FRAME = 0x00;
const uint8_t WebSocketClient::OPCODE_TEXT_FRAME = 0x01;
const uint8_t WebSocketClient::OPCODE_BINARY_FRAME = 0x02;
const uint8_t WebSocketClient::OPCODE_CLOSE_FRAME = 0x08;
const uint8_t WebSocketClient::OPCODE_PING_FRAME = 0x09;
const uint8_t WebSocketClient::OPCODE_PONG_FRAME = 0x0A;

WebSocketClient::WebSocketClient(int fd, EventFax * fax ) :
		TCPClient(fd) {

	uFrameState = FRAME_STATE_UNKNOWN;
	iWebSocketProtocolVersion = WebSocket_PROTOCOL_UNKNOWN;
	bHandshakeComplete = false;
	this->fax = fax;
	websocket_frame.data = NULL;

	bf_data = (char *) malloc( BUF_MIN_SIZE);
	bf_data_size = BUF_MIN_SIZE;
	bf_data_cur_size = bf_data_size;
}

WebSocketClient::~WebSocketClient()
{
	if (websocket_frame.data != NULL) {

		free(websocket_frame.data);
		websocket_frame.data = NULL;

	}

	if( bf_data != NULL ) {

		free(bf_data);
		bf_data = NULL;

	}

}

void WebSocketClient::receive_data(void *data, size_t len)
{
    if( !bHandshakeComplete ) {

		handle_packet(data, len);

    } else {

    	handle_frame_packet(data, len);

    }

}

bool WebSocketClient::handle_byte(unsigned char byte)
{
	//websocket_frame.print(false);

    //printf("Handle byte: byte = %x - %d when frame state is %d\n", byte, byte, uFrameState);
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
        	//	cout << "websocket_frame.length = " << websocket_frame.length << endl;
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


       if( websocket_frame.isMasked ) {

            websocket_frame.c_masking_key[websocket_frame.uMaskIndex++] = byte;
            if( websocket_frame.uMaskIndex == 4 ) {

                uFrameState = FRAME_STATE_GOT_MASKING_KEY;
                websocket_frame.uMaskIndex = 0;

                //cout << "got masking key\n";

				if (websocket_frame.length == 0) {

					uFrameState = FRAME_STATE_GOT_COMPLETE_FRAME;

					// data frame can be empty for some packet. Eg close
					if (!handleCompleteFrame()) {
						return false;
					}

				}

            }

        } else {

			if (websocket_frame.length == 0) {

				uFrameState = FRAME_STATE_GOT_COMPLETE_FRAME;

				// data frame can be empty for some packet. Eg close
				if (!handleCompleteFrame()) {
					return false;
				}

			} else {

				if (websocket_frame.uLengthCopied == 0) {
					// Allocating memory for data
					websocket_frame.data = (char *) malloc(
							websocket_frame.length);
				}

				//Copy data.
				*(websocket_frame.data + websocket_frame.uLengthCopied) = byte;
				websocket_frame.uLengthCopied++;
				if (websocket_frame.uLengthCopied == websocket_frame.length) {
					uFrameState = FRAME_STATE_GOT_COMPLETE_FRAME;

					if (!handleCompleteFrame()) {
						return false;
					}

				}

			}

        }

    } else if( uFrameState == FRAME_STATE_GOT_MASKING_KEY ) {

        if( websocket_frame.uLengthCopied == 0 )
        {
            // Allocating memory for data
            websocket_frame.data = (char *)malloc(websocket_frame.length);
        }

        //Copy data.
        		//cout << __LINE__ << ": websocket_frame.uLengthCopied = " << websocket_frame.uLengthCopied << endl;
        *(websocket_frame.data + websocket_frame.uLengthCopied) = 
            byte ^ websocket_frame.c_masking_key[websocket_frame.uMaskIndex % 4];

        websocket_frame.uMaskIndex++;
        websocket_frame.uLengthCopied++;

        if( websocket_frame.uLengthCopied == websocket_frame.length ) {
            uFrameState = FRAME_STATE_GOT_COMPLETE_FRAME;

			if (!handleCompleteFrame()) {
				return false;
			}

        }

    }

    return true;

}

bool WebSocketClient::handleCompleteFrame()
{
    //websocket_frame.print();

	bool bStatus = true;
	if (websocket_frame.opcode <= 0x7) {
//cout << "non control frame\n";
		if( !handle_non_control_frames() ) {

			send_close_frame(STATUS_CODE_NORMAL_CLOSURE,
					STATUS_MSG_NORMAL_CLOSURE);

			close();
			bStatus = false;

		}

	} else if (websocket_frame.opcode == 0x8) {
		//cout << "close frame\n";
		// close frame with same received data
		send_close_frame();
		close();
		bStatus = false;

	} else if (websocket_frame.opcode == 0x9) {
		//cout << "ping frame\n";
		// ping frame; send pong frame
		if( !send_pong_frame(websocket_frame.data, websocket_frame.length) ) {
			close();
			bStatus = false;
		}

	} else if (websocket_frame.opcode == 0xA) {
		//cout << "pong frame\n";
		// pong frame
		// do nothing
		onPongMessageinWebsocket();

	} else {
		//cout << "unknown frame\n";
		send_close_frame(STATUS_CODE_PROTOCOL_ERROR, STATUS_MSG_PROTOCOL_ERROR);
		close();
		bStatus = false;

	}

    free(websocket_frame.data);
    websocket_frame.data = NULL;
    memset(&websocket_frame, '\0', sizeof(struct websocket_frame_t));

    uFrameState = FRAME_STATE_UNKNOWN;

    //cout << "bStatus " << bStatus << endl;
    return bStatus;

}

void WebSocketClient::handle_frame_packet(void *data, size_t len)
{
    if( this->iWebSocketProtocolVersion == WebSocketClient::WebSocket_PROTOCOL_00 ) {

        onMessageinWebsocket((char *)data + 1, len-2) ;

    } else if( this->iWebSocketProtocolVersion == WebSocketClient::WebSocket_PROTOCOL_06 ) {
        cout << "Received buffer with length " << len << endl;
        unsigned char *c_data = (unsigned char *)data;
        for(size_t i = 0; i < len; i++) {

            unsigned char c = *(c_data + i);
            if( !handle_byte( c ) ) {
            	return;
            }

        }
    }
}

void WebSocketClient::onRequest(HTTPServerRequest * request)
{
    if( request->sMethod != "GET" ) {
        close();
        return;
    }

    if( request->headers["Sec-WebSocket-Key"].length() > 0 ) {

        onHandshakeRequest();

        string sAcceptKey, shaValue;
        string sInput = request->headers["Sec-WebSocket-Key"];
					
				sInput = trim(sInput) + WEBSOCKET_MAGIC_KEY;

        Digest digest;
        digest.sha1sum(sInput.c_str(), sInput.length(), shaValue);

        char sha_buffer[1024] = {'\0'};
        size_t sha_buffer_len = 0;
        for(size_t i = 2; i <= shaValue.length(); i += 2) {
            //char c[4] = {'0', 'x', shaValue[i-2], shaValue[i-1]};
            char c[] = {shaValue[i-2], shaValue[i-1], '\0'};
            sha_buffer[sha_buffer_len] = strtol(c, NULL, 16);
            //printf("%ld - %d - %d", strtol(c, NULL, 16), c[0], c[1]);
            //printf("\n");

            sha_buffer_len++;
        }

        Base64 base64;
        base64.encode(string(sha_buffer, sha_buffer_len), sAcceptKey);
        helper.rstrip(sAcceptKey, '\n');

        /*
        cout << "input " << sInput 
            << " : sha-buffer-len " << sha_buffer_len
            << " : AcceptKey " << sAcceptKey 
            << " : sha1sum " << shaValue 
            << endl;
        */
        HTTPResponse response(HTTPResponse::switching_protocols);
        response.setHeader("Connection", "Upgrade");
        response.setHeader("Upgrade", "websocket");
        response.setHeader("Sec-WebSocket-Accept", sAcceptKey);

        string sToWrite = response.toString();
        this->writen(this->descriptor, sToWrite.c_str(), sToWrite.length());

        bHandshakeComplete = true;

        this->iWebSocketProtocolVersion = WebSocketClient::WebSocket_PROTOCOL_06;

        onHandshakeComplete();

    } else if ( (request->headers["Sec-WebSocket-Key1"].length() > 0) 
            && (request->headers["Sec-WebSocket-Key2"].length() > 0) ) {

        onHandshakeRequest();

        string sKey1 = request->headers["Sec-WebSocket-Key1"];
        string sKey2 = request->headers["Sec-WebSocket-Key2"];
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
        for(size_t i = 0; i < request->sContent.length(); i++)
            printf("%c - %d\n", request->sContent[i], request->sContent[i]);
        uint32_t bi1 = htonl(i1);
        uint32_t bi2 = htonl(i2);
        unsigned char c_buffer[128] = {'\0'};
        memcpy(&c_buffer[0], &bi1, sizeof(uint32_t));
        memcpy(&c_buffer[sizeof(uint32_t)], &bi2, sizeof(uint32_t));
        memcpy(&c_buffer[(2*sizeof(uint32_t))], request->sContent.c_str(), 8);
        for(size_t i = 0; i < 16; i++ )
            printf("Bytes = %u - %x\n", c_buffer[i], c_buffer[i]);
        Digest d;
        string md5Token;
        d.digest(c_buffer, 16, Digest::DigestType_MD5, md5Token);
        cout << "md5Token = " << md5Token << endl;

        string sResponse( HTTPResponse::websocket_protocol_handshake );
        sResponse = sResponse + "Upgrade: WebSocket\r\n";
        sResponse = sResponse + "Connection: Upgrade\r\n";
        sResponse = sResponse + "Sec-WebSocket-Origin: " + request->headers["Origin"] + "\r\n";
        sResponse = sResponse + "Sec-WebSocket-Location: ws://" + request->headers["Host"] + "/\r\n\r\n";
        size_t sha_buffer_len = 0;
        memset(c_buffer, '\0', sizeof(c_buffer));
        for(size_t i = 2; i <= md5Token.length(); i += 2) {
            char c[] = {md5Token[i-2], md5Token[i-1], '\0'};
            c_buffer[sha_buffer_len] = strtol(c, NULL, 16);
            sha_buffer_len++;
        }
        printf("md5 = %s\n", c_buffer);
        this->sendData( sResponse );
        this->writen(this->descriptor, (const char *)&c_buffer[0], sha_buffer_len);
        bHandshakeComplete = true;
        this->iWebSocketProtocolVersion = WebSocketClient::WebSocket_PROTOCOL_00;

        onHandshakeComplete();

    } else {
        close();
        return;
    }

    cout << " Sec-WebSocket-Version : " 
        << request->headers["Sec-WebSocket-Version"] << endl;

}

void WebSocketClient::close()
{
    this->fax->deleteTCPClient(this);
    closeConnection();
    unbind();
}

// -- Not using this function.
size_t WebSocketClient::copybytes(unsigned char *src, unsigned char *dest, unsigned char continuation)
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

void WebSocketClient::frame(string & s, unsigned char * & ptr, size_t & len)
{
	frame( OPCODE_TEXT_FRAME, s.c_str(), s.length(), ptr, len);
}

bool WebSocketClient::send(string sResponse)
{

    if( this->iWebSocketProtocolVersion == WebSocketClient::WebSocket_PROTOCOL_00 ) {

        this->writen( this->descriptor, "\0", 1);
        this->writen( this->descriptor, sResponse.c_str(), sResponse.length());
        char c = 0xff;
        int status = this->writen( this->descriptor, &c, 1);
        return (status > 0);

    } else if( this->iWebSocketProtocolVersion == WebSocketClient::WebSocket_PROTOCOL_06 ) {

    	return send( sResponse.c_str(), sResponse.length(), OPCODE_TEXT_FRAME);
    }

    return false;

}

bool WebSocketClient::send(const char * data, size_t data_len, uint8_t uOpcode) {

	int status = 0;

	size_t len = 0;
	unsigned char * ptr = NULL;

	frame(uOpcode, data, data_len, ptr, len);

	status = this->asyncSendData((char *) ptr, len);
	free(ptr);

	return (status > 0);

}

bool WebSocketClient::handle_non_control_frames() {

	if ( websocket_frame.fin && (websocket_frame.opcode != 0x0) ) {
//cout << "unfragmented msg" <<endl;
		// unfragmented message
		onMessageinWebsocket(websocket_frame.data, websocket_frame.length);

	} else if ( !websocket_frame.fin
			&& (websocket_frame.opcode != 0x0)) {
		//cout << "start of fragmented message" <<endl;
		// start of fragmented message
		bf_data_cur_size = 0;
		return copyToBufData( websocket_frame.data, websocket_frame.length);

	} else if ( !websocket_frame.fin
			&& (websocket_frame.opcode == 0x0)) {
		//cout << "continuation of the fragmented message" <<endl;
		// continuation of the fragmented message
		return copyToBufData( websocket_frame.data, websocket_frame.length);

	} else if ( websocket_frame.fin
			&& (websocket_frame.opcode == 0x0)) {
		//cout << "end of fragmented message" <<endl;
		// end of fragmented message
		if( !copyToBufData( websocket_frame.data, websocket_frame.length) )
			return false;

		onMessageinWebsocket(bf_data, bf_data_cur_size);
		bf_data_cur_size = 0;

	}

	return true;

}


bool WebSocketClient::copyToBufData(char *ptr, size_t len) {

	if( bf_data_size - bf_data_cur_size < len ) {

		char *_p = (char * )realloc(bf_data, bf_data_size + len);
		if( _p == NULL )
			return false;

		bf_data = _p;
		bf_data_size += len;

	}

	memcpy( bf_data + bf_data_cur_size, ptr, len );
	bf_data_cur_size += len;

	return true;

}

bool WebSocketClient::send_close_frame() {

	if (websocket_frame.length <= 2) {
		send_close_frame(STATUS_CODE_NORMAL_CLOSURE, STATUS_MSG_NORMAL_CLOSURE);
		return true;
	}

	void *_p = (void *) websocket_frame.data;
	uint16_t status_code = helper.readU16(_p);
	send_close_frame(status_code,
			string(websocket_frame.data + 2, websocket_frame.length - 2));

	return true;

}

bool WebSocketClient::send_close_frame( uint16_t iStatusCode, const string & sStatusMsg ) {

	size_t data_len = 2 + sStatusMsg.length();
	char data[data_len];

	for (size_t i = 0; i < 2; i++) {
		uint8_t b = (iStatusCode >> (i * 8));
		*(data + 1 - i) = b;
	}

	memcpy( data+2, sStatusMsg.c_str(), data_len-2);

	return send( data, data_len, OPCODE_CLOSE_FRAME);

}

bool WebSocketClient::send_pong_frame( const char *data, size_t data_len) {

	return send( data, data_len, OPCODE_PONG_FRAME);

}

bool WebSocketClient::sendPongMessage( const string & data ) {

	return send_pong_frame(data.c_str(), data.length());

}

bool WebSocketClient::sendPingMessage( const string & data ) {

	return send( data.c_str(), data.length(), OPCODE_PING_FRAME);

}

void WebSocketClient::frame(uint8_t uOpcode, const char *payload_data, size_t payload_data_len, unsigned char * & packet, size_t & packet_len)
{
	packet_len = 0;

	/*
	 * The length of the "Payload data", in bytes: if 0-125, that is the
	 payload length.  If 126, the following 2 bytes interpreted as a
	 16-bit unsigned integer are the payload length.  If 127, the
	 following 8 bytes interpreted as a 64-bit unsigned integer (the
	 most significant bit MUST be 0) are the payload length.  Multibyte
	 length quantities are expressed in network byte order.  Note that
	 in all cases, the minimal number of bytes MUST be used to encode
	 the length.
	 */

	size_t payload_data_len_byte_count = 0;

	uint8_t uMaskBit = 0;
	uint8_t uFinBit = 0x80;
	uint8_t uPktLen = 0;

	unsigned char *p = NULL;

	// 0x7D = 125
	if (payload_data_len <= 0x7D) {

		uPktLen = payload_data_len;

		p = packet = (unsigned char *) malloc(
				2 + payload_data_len
						+ payload_data_len_byte_count);

		packet_len = 2 + payload_data_len
				+ payload_data_len_byte_count;

		*p++ = uFinBit | uOpcode;
		*p++ = uMaskBit | uPktLen;

	} else if (payload_data_len <= 0xFFFF) {

		uPktLen = 0x7E;
		payload_data_len_byte_count = 2;

		p = packet = (unsigned char *) malloc(
				2 + payload_data_len
						+ payload_data_len_byte_count);

		packet_len = 2 + payload_data_len
				+ payload_data_len_byte_count;

		*p++ = uFinBit | uOpcode;
		*p++ = uMaskBit | uPktLen;

		// storing payload length.
		for (size_t i = 0; i < payload_data_len_byte_count; i++) {
			uint8_t b = (payload_data_len >> (i * 8));
			*(packet + 3 - i) = b;
			++p;
		}

	} else {

		uPktLen = 0x7F;
		payload_data_len_byte_count = 8;

		p = packet = (unsigned char *) malloc(
				2 + payload_data_len
						+ payload_data_len_byte_count);

		packet_len = 2 + payload_data_len
				+ payload_data_len_byte_count;

		*p++ = uFinBit | uOpcode;
		*p++ = uMaskBit | uPktLen;

		// storing payload length.
		for (size_t i = 0; i < payload_data_len_byte_count; i++) {
			uint8_t b = (payload_data_len >> (i * 8));
			*(packet + 9 - i) = b;
			++p;
		}

	}

	memcpy(p, payload_data, payload_data_len);

}
