#ifndef __SBU2_PUSH_CLIENT_H__
#define __SBU2_PUSH_CLIENT_H__

#include <iostream>
#include <ubacipc/TCPClient.h>
#include <ubacipc/TLSClient.h>
#include <ubacipc/Mutex.h>
#include <vector>

#include "SessionTable.h"
#include "SymbolTable.h"
#include "MasterTable.h"
#include "SBU2RequestCache.h"
#include "SBU2StreamingRequest.h"
#include "IFSubscriptions.h"

class SBU2PushClient :
	public virtual TCPClient
{
	public:
		SBU2PushClient(int fd, SessionTable *sessionTable,
					   MasterTable *masterTable,
					   IFSubscriptions *ifSubscriptions,
					   Mutex *mTableMutex);

		virtual ~SBU2PushClient() {};

		void receive_data(void *data, size_t len);
		void unbind();
		int getDescriptor();
		bool send(uint8_t, JsonObject *);
		bool send(JsonObject *);
		bool isMarkedForRemoval();

		void markForRemoval();
		bool checkInactivity(time_t);
		void removeFromTables();

		virtual int sendData(string data)
		{
			return TCPClient::sendData(data);
		};
		virtual bool asyncSendData(const char *data, int nBytes)
		{
			return TCPClient::asyncSendData(data, nBytes);
		};

	protected:
		void unsubscribeAll();
		void parse(char *data, size_t len);
		void parse(string sRequest);
		string sToken, sSessionID;
		time_t uLastActivityTime;
		bool bMarkedForRemoval;

		void handleSession(SBU2StreamingRequest &);

		/** returns symbols that has to be unsubscribed */
		vector<string> removeSubscriptions(uint8_t streamType,
										   SymbolTable * symbolTable);

		IFSubscriptions *ifSubscriptions;
		Mutex *mTableMutex;

		SBU2RequestCache sbu2Cache;
		SessionTable *sessionTable;
		MasterTable *masterTable;

};

#endif /* __PUSH_CLIENT_H__ */
