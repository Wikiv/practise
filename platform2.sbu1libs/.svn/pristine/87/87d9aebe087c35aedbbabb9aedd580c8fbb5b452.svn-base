#ifndef __UBAC_WEBSOCKET_CLIENT_H__
#define __UBAC_WEBSOCKET_CLIENT_H__

#include "HTTPClient.h"

namespace UBACIPC {

    class WebSocketClient :
        public HTTPParser,
        public virtual TCPClient
    {
        public:
            WebSocketClient(int fd, EventFax * fax);
            ~WebSocketClient();

            virtual void receive_data(void *ptr, size_t len);
            void onRequest(HTTPServerRequest * request);

            bool send(string response);
            virtual void onMessageinWebsocket(char * ptr, size_t len) {}
			virtual void onHandshakeRequest() {}
			virtual void onHandshakeComplete() {}
            virtual void unbind() {}

            const static string WEBSOCKET_MAGIC_KEY;
            const static uint8_t WebSocket_PROTOCOL_00;
            const static uint8_t WebSocket_PROTOCOL_06;
        private:
            EventFax * fax;
            bool bHandshakeComplete;

            void close();
            void handle_frame_packet(void *data, size_t len);
            void handle_byte(unsigned char byte);

            uint8_t iWebSocketProtocolVersion;

            struct websocket_frame_t {
                uint8_t fin, rsv1, rsv2, rsv3;
                uint8_t opcode;
                uint8_t isMasked;
                char payload_length[8];
                char c_masking_key[4];
                uint8_t uMaskIndex;
                uint64_t uLengthCopied;
                uint8_t noOfBytesOfPayloadLength;
                char *data;
                uint64_t length;
            };

            struct websocket_frame_t websocket_frame;
            const static uint8_t FRAME_STATE_UNKNOWN;
            const static uint8_t FRAME_STATE_GOT_OPCODE;
            const static uint8_t FRAME_STATE_GOT_READING_LENGTH;
            const static uint8_t FRAME_STATE_GOT_LENGTH;
            const static uint8_t FRAME_STATE_GOT_MASKING_KEY;
            const static uint8_t FRAME_STATE_GOT_COMPLETE_FRAME;

            uint8_t uFrameState;
    };
};

#endif /* __UBAC_HTTP_CLIENT_H__ */
