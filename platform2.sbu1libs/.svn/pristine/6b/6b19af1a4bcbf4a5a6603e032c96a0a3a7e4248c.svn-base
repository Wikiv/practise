#ifndef __WEBSOCKET_PUSH_SERVER_H__
#define __WEBSOCKET_PUSH_SERVER_H__

#include <iostream>

#include <ubacipc/EventFax.h>

#include "SBU2WebSocketPushClient.h"
#include "SessionTable.h"
#include "SymbolTable.h"
#include "IFSubscriptions.h"
#include "PushServer.h"


class WebSocketPushServer :
	public PushServer
{
	public:
		WebSocketPushServer(int, time_t,
					  IFSubscriptions *);
		~WebSocketPushServer();

		void createNewClient(int fd);

};

#endif /* __WEBSOCKET_PUSH_SERVER_H__ */
