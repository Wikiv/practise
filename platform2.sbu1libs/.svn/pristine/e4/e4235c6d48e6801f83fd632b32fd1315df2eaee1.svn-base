#ifndef __PUSH_SERVER_H__
#define __PUSH_SERVER_H__

#include <iostream>
#include <ubacipc/TCPServer.h>
#include <ubacipc/TLSServer.h>
#include <ubacipc/TLSClient.h>

#include <ubacipc/EventFax.h>
#include <ubacipc/Mutex.h>

#include "UBACPushClient.h"
#include "SBU2PushClient.h"
#include "SessionTable.h"
#include "SymbolTable.h"
#include "MasterSymbolTable.h"
#include "IFSubscriptions.h"

class PushServer :
	public virtual TCPServer
{
	public:
		PushServer(int port, time_t uInactivityTimeout, uint8_t iDataType,
				   EventFax *fax, IFSubscriptions *ifSubscriptions);

		~PushServer();

		void createNewClient(int fd);
		void monitor();

		void sendToSession(uint8_t iStreamingRequestType, string sSessionID,
						   JsonObject *jsonResponse);
		void sendLevel1(string, JsonObject *);
		void sendLevel2(string, JsonObject *);
		void sendTradeSymbols(string, JsonObject *);

		const static uint8_t DataType_UBAC;
		const static uint8_t DataType_SBU2;

    protected:
		uint8_t iDataType;
		time_t uInactivityTimeout;
		IFSubscriptions *ifSubscriptions;
		vector<UBACPushClient *>ubacClientList;
		vector<SBU2PushClient *>sbu2ClientList;
		SessionTable *sessionTable;
		MasterSymbolTable * masterSymbolTable;

		EventFax *fax;
		Mutex *mTableMutex;

	private:

		void monitorUBACClients();
		void monitorSBU2Clients();


};

#endif /* __PUSH_SERVER_H__ */
