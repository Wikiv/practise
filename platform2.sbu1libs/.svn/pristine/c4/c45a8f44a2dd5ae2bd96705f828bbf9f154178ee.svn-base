#ifndef __SBU2_PUSH_CLIENT_H__
#define __SBU2_PUSH_CLIENT_H__

#include <iostream>
#include <ubacipc/TCPClient.h>
#include <ubacipc/TLSClient.h>
#include <ubacipc/Mutex.h>
#include <vector>

#include "SessionTable.h"
#include "SymbolTable.h"
#include "MasterSymbolTable.h"
#include "SBU2RequestCache.h"
#include "SBU2StreamingRequest.h"
#include "IFSubscriptions.h"

class SBU2PushClient :
	public virtual TCPClient
{
	public:
		SBU2PushClient(int fd, SessionTable *sessionTable,
					   MasterSymbolTable *masterSymbolTable,
					   IFSubscriptions *ifSubscriptions,
					   Mutex *mTableMutex);

		virtual ~SBU2PushClient() {};

		void receive_data(void *data, size_t len);
		void unbind();
		int getDescriptor();
		bool send(uint8_t, JsonObject *);
		bool sendLevel1(string, JsonObject *);
		bool sendLevel2(string, JsonObject *);
		bool sendTradeSymbols(string, JsonObject *);
		bool isMarkedForRemoval();
		void checkInactivity(time_t);

        virtual int sendData(string data) { return TCPClient::sendData(data); };

	protected:
		void unsubscribeAll();
		void parse(char *data, size_t len);
		void parse(string sRequest);
		string sToken;
		time_t uLastActivityTime;
		bool bMarkedForRemoval;

		void removeSubscriptions(uint8_t streamType,
								 SymbolTable * symbolTable);

		IFSubscriptions *ifSubscriptions;
		int fd;
		Mutex *mTableMutex;

		SBU2RequestCache sbu2Cache;
		SessionTable *sessionTable;
		MasterSymbolTable *masterSymbolTable;
};

#endif /* __PUSH_CLIENT_H__ */
