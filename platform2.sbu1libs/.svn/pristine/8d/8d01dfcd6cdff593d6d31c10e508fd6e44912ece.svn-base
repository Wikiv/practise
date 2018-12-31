#include "WebSocketClient.h"

const string WebSocketClient::WEBSOCKET_MAGIC_KEY = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
const uint8_t WebSocketClient::FRAME_STATE_UNKNOWN = 1;
const uint8_t WebSocketClient::FRAME_STATE_GOT_OPCODE = 2;
const uint8_t WebSocketClient::FRAME_STATE_GOT_READING_LENGTH = 3;
const uint8_t WebSocketClient::FRAME_STATE_GOT_LENGTH = 4;
const uint8_t WebSocketClient::FRAME_STATE_GOT_MASKING_KEY = 5;
const uint8_t WebSocketClient::FRAME_STATE_GOT_COMPLETE_FRAME = 6;
const uint8_t WebSocketClient::WebSocket_PROTOCOL_00 = 1;
const uint8_t WebSocketClient::WebSocket_PROTOCOL_06 = 2;

WebSocketClient::WebSocketClient(int fd, EventFax * fax) : TCPClient(fd)
{
    uFrameState = FRAME_STATE_UNKNOWN;
    bHandshakeComplete = false;
    this->fax = fax;
}

WebSocketClient::~WebSocketClient()
{
}

void WebSocketClient::receive_data(void *data, size_t len)
{
    if( !bHandshakeComplete )
        handle_packet(data, len);
    else
        handle_frame_packet(data, len);
}

void WebSocketClient::handle_byte(unsigned char byte)
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

            onMessageinWebsocket(websocket_frame.data, websocket_frame.length);

            free(websocket_frame.data);
            websocket_frame.data = NULL;
            memset(&websocket_frame, '\0', sizeof(struct websocket_frame_t));
            uFrameState = FRAME_STATE_UNKNOWN;
        }
    } else if( uFrameState == FRAME_STATE_GOT_COMPLETE_FRAME ) {
    }
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
            handle_byte( c );
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
        string sInput = request->headers["Sec-WebSocket-Key"] + WEBSOCKET_MAGIC_KEY;
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
            char c[2] = {md5Token[i-2], md5Token[i-1]};
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

    cout << "protocol version = " << this->iWebSocketProtocolVersion 
            << " Sec-WebSocket-Version : " << request->headers["Sec-WebSocket-Version"] << endl;

}

void WebSocketClient::close()
{
    this->fax->deleteTCPClient(this);
    closeConnection();
    unbind();
}

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

bool WebSocketClient::send(string sResponse)
{
    int status = 0;
    cout << "sResponse in WebSocketClient::send protocol version = " <<  this->iWebSocketProtocolVersion << endl;

    if( this->iWebSocketProtocolVersion == WebSocketClient::WebSocket_PROTOCOL_00 ) {
        cout << "WebSocket_PROTOCOL_00 " << endl;
        this->writen( this->descriptor, "\0", 1);
        this->writen( this->descriptor, sResponse.c_str(), sResponse.length());
        char c = 0xff;
        status = this->writen( this->descriptor, &c, 1);
    } else if( this->iWebSocketProtocolVersion == WebSocketClient::WebSocket_PROTOCOL_06 ) {
        cout << "WebSocket_PROTOCOL_06 " << endl;
        size_t len = 0;
        unsigned char *ptr = (unsigned char *)calloc(1, sResponse.length() + 100);
        frame(sResponse, ptr, len);
        status = this->writen( this->descriptor, (char *)ptr, len );
        free(ptr);
    }
    return (status > 0);
}





