#ifndef __SBU2_WEBSOCKET_PUSH_CLIENT_H__
#define __SBU2_WEBSOCKET_PUSH_CLIENT_H__

#include <iostream>
#include <ubacipc/TCPClient.h>
#include <ubacipc/WebSocketClient.h>

#include "SessionTable.h"
#include "SymbolTable.h"
#include "MasterTable.h"
#include "SBU2RequestCache.h"
#include "IFSubscriptions.h"
#include "SBU2PushClient.h"

class SBU2WebSocketPushClient :
	public WebSocketClient,
	public SBU2PushClient
{
	public:
		SBU2WebSocketPushClient(int fd, EventFax * fax, SessionTable *sessionTable,
						  MasterTable *masterSymbolTable,
						  IFSubscriptions *ifSubscriptions,
						  Mutex *mTableMutex, bool bSessionValidate)
            : TCPClient(fd),
			  WebSocketClient(fd, fax),
			  SBU2PushClient(fd, sessionTable, masterSymbolTable,
							 ifSubscriptions, mTableMutex, bSessionValidate) {}

		~SBU2WebSocketPushClient() {}

		void receive_data(void *ptr, size_t len)
		{
            WebSocketClient::receive_data(ptr, len);
		};

        void onMessageinWebsocket(char * ptr, size_t len)
        {
            SBU2PushClient::parse(ptr, len);
        }

		int sendData(string data)
		{
			return WebSocketClient::send(data);
		};

		bool asyncSendData(const char *data, int length)
		{
			return WebSocketClient::send(string(data, length));
		};

        void unbind()
        {
            SBU2PushClient::unbind();
        }

};

#endif /* __SBU2_WEBSOCKET_PUSH_CLIENT_H__ */
