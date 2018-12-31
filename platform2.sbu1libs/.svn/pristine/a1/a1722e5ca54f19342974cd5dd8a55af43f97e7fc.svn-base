#ifndef __UBAC_WEBSOCKET_CLIENT_H__
#define __UBAC_WEBSOCKET_CLIENT_H__

#include <random>

#include "HTTPClient.h"

#define BUF_MIN_SIZE (4*1024)

namespace UBACIPC {

    class WebSocketClient :
        public HTTPParser,
        public virtual TCPClient
    {
        public:
            WebSocketClient(int, EventFax *);

            virtual ~WebSocketClient();

            virtual void receive_data(void *ptr, size_t len);
            void onRequest(HTTPServerRequest * request);

            bool send(string response);
            bool send(const char *, size_t, uint8_t);

            virtual void onMessageinWebsocket(char * ptr, size_t len) {}
            virtual void onPongMessageinWebsocket() {}
			virtual void onHandshakeRequest() {}
			virtual void onHandshakeComplete() {}
            virtual void unbind() {}

            const static string WEBSOCKET_MAGIC_KEY;

            const static uint8_t WebSocket_PROTOCOL_UNKNOWN;
            const static uint8_t WebSocket_PROTOCOL_00;
            const static uint8_t WebSocket_PROTOCOL_06;

            const static uint16_t STATUS_CODE_NORMAL_CLOSURE;
            const static uint16_t STATUS_CODE_PROTOCOL_ERROR;

            const static string STATUS_MSG_NORMAL_CLOSURE;
            const static string STATUS_MSG_PROTOCOL_ERROR;

            const static uint8_t OPCODE_TEXT_FRAME;
            const static uint8_t OPCODE_BINARY_FRAME;
            const static uint8_t OPCODE_CONTINUATION_FRAME;
            const static uint8_t OPCODE_CLOSE_FRAME;
            const static uint8_t OPCODE_PING_FRAME;
            const static uint8_t OPCODE_PONG_FRAME;

        protected:
            IFHelper helper;

            // trim from left
            inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
            {
            	s.erase(0, s.find_first_not_of(t));
            	return s;
            }

            // trim from right
            inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
            {
            	s.erase(s.find_last_not_of(t) + 1);
            	return s;
            }

            // trim from left & right
            inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
            {
            	return ltrim(rtrim(s, t), t);
            }

            void frame(uint8_t, const char *, size_t, unsigned char * &, size_t &);
            bool sendPongMessage( const string & );
            bool sendPingMessage( const string & );

        private:
            EventFax * fax;
            bool bHandshakeComplete;

            void close();
            void handle_frame_packet(void *data, size_t len);
            bool handle_byte(unsigned char byte);

            bool handleCompleteFrame();
            
            size_t copybytes(unsigned char *src, unsigned char *dest, 
                    unsigned char continuation);

            void frame(string & s, unsigned char * & ptr, size_t & len);

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

                void print(bool bPrintData=true )
                {
                    printf("fin=%x,rsv1=%x,rsv2=%x,rsv3=%x,opcode=%x,length=%ld",
                            fin, rsv1, rsv2, rsv3, opcode, length);

			if (bPrintData) {
				printf("\ndata: ");
				for (size_t i = 0; i < length; i++) {
					uint8_t b = (uint8_t) *(data + i);
					printf("%x,", b);
				}
			}
                    printf("\n");
                }
            };

            char * bf_data;
            size_t bf_data_size, bf_data_cur_size;

            struct websocket_frame_t websocket_frame;
            const static uint8_t FRAME_STATE_UNKNOWN;
            const static uint8_t FRAME_STATE_GOT_OPCODE;
            const static uint8_t FRAME_STATE_GOT_READING_LENGTH;
            const static uint8_t FRAME_STATE_GOT_LENGTH;
            const static uint8_t FRAME_STATE_GOT_MASKING_KEY;
            const static uint8_t FRAME_STATE_GOT_COMPLETE_FRAME;

            uint8_t uFrameState;

            bool copyToBufData(char *, size_t);
            bool handle_non_control_frames();
            bool send_close_frame();
            bool send_close_frame( uint16_t, const string & );
            bool send_pong_frame(const char *, size_t);

    };
};

#endif /* __UBAC_HTTP_CLIENT_H__ */
