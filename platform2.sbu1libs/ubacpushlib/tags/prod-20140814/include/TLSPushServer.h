#ifndef __TLS_PUSH_SERVER_H__
#define __TLS_PUSH_SERVER_H__

#include <iostream>

#include <ubacipc/EventFax.h>
#include <ubacipc/Mutex.h>
#include <ubacipc/TLSServer.h>

#include "SBU2TLSPushClient.h"
#include "SessionTable.h"
#include "SymbolTable.h"
#include "IFSubscriptions.h"
#include "PushServer.h"


class TLSPushServer :
	public PushServer,
	public TLSServer
{
	public:
		TLSPushServer(int, time_t, EventFax *,
					  IFSubscriptions *, string, string);
		~TLSPushServer();

		void createNewClient(int fd);

};

#endif /* __TLS_PUSH_SERVER_H__ */
