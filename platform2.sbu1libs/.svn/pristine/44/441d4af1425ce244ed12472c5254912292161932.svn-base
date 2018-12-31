#ifndef __PUSH_SERVER_H__
#define __PUSH_SERVER_H__

#include <iostream>
#include <ubacipc/TCPServer.h>
#include <ubacipc/TLSServer.h>
#include <ubacipc/TLSClient.h>

#include <ubacipc/EventFax.h>
#include <ubacipc/Mutex.h>
#include <ubaclogger/SLog.h>

#include "SBU2PushClient.h"
#include "SessionTable.h"
#include "SymbolTable.h"
#include "MasterTable.h"
#include "IFSubscriptions.h"

class PushServer :
	public virtual UBACIPC::TCPServer
{
	public:
		PushServer(int port, time_t uInactivityTimeout, 
                IFSubscriptions *ifSubscriptions);

        void setEventFax(EventFax * fax);

		~PushServer();

    

		void createNewClient(int fd);
		void monitor();

        void sendToAllSessions(JsonObject *);

		void sendToSession(string, UBACJSON::JsonObject *);

		void sendToSession(uint8_t, string, JsonObject *);
		/** send update to level1 connections.*/
		void sendLevel1(string, JsonObject *);
		/** send update to level2 connections.*/
		void sendLevel2(string, JsonObject *);
		/** send update to TradeSymbol connections.*/
		void sendTradeSymbols(string, JsonObject *);

		void sendLiveTrades(JsonObject *);

		void closeSession(string);

		bool hasLevel1Subscribed(string sSymbol);
                
		bool hasLevel2Subscribed(string sSymbol);

		const static uint8_t DataType_UBAC;
		const static uint8_t DataType_SBU2;
		void setSessionValidation(bool flag);

        void setLogger(SLog* sLogID){
                this->sLogID = sLogID;
        }

        SLog* getLogger(){
                    return this->sLogID;
        }


	protected:
		time_t uInactivityTimeout;
		IFSubscriptions *ifSubscriptions;
		vector<SBU2PushClient *>sbu2ClientList;
		SessionTable *sessionTable;
		MasterTable * masterTable;

		EventFax *fax;
		Mutex *mTableMutex;

		bool bSessionValidation;
		SLog *sLogID;
	private:

		void monitorSBU2Clients();


};

#endif /* __PUSH_SERVER_H__ */
