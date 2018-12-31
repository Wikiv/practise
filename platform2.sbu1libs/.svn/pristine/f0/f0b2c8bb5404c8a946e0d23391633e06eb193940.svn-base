#include "PushServer.h"

const uint8_t PushServer::DataType_UBAC = 1;
const uint8_t PushServer::DataType_SBU2 = 2;

static void server_monitor(void *d)
{
	PushServer *server = static_cast<PushServer *>(d);
	server->monitor();
}

PushServer::PushServer(int iPort, time_t uInactivityTimeout, 
					   IFSubscriptions *ifSubscriptions)
	: TCPServer(iPort)
{
	this->ifSubscriptions = ifSubscriptions;
	this->uInactivityTimeout = uInactivityTimeout;

	this->fax = NULL;

	this->mTableMutex = new Mutex();
	this->sessionTable = new SessionTable();
	this->masterTable = new MasterTable();
	this->bSessionValidation = true;
	this->sLogID = NULL;
}

PushServer::~PushServer()
{
}

void PushServer::setSessionValidation( bool flag )
{
	bSessionValidation = flag;
}

void PushServer::createNewClient(int fd)
{
	SBU2PushClient *client = new SBU2PushClient(fd, sessionTable,
			masterTable, ifSubscriptions, mTableMutex, bSessionValidation);
	client->setLogger(sLogID);

	sbu2ClientList.push_back(client);
	fax->addTCPClient( client );
	if(sLogID){
                sLogID->debug("New client connection : fd = %d - Addr %p\n", fd, client);
        } 
}

void PushServer::monitor()
{
	monitorSBU2Clients();
}

void PushServer::setEventFax(EventFax * fax)
{
	this->fax = fax;
	this->fax->addPeriodicTimer( server_monitor, this, 1 );
}



void PushServer::monitorSBU2Clients()
{
	time_t t_threshold_time = time(NULL) - uInactivityTimeout;
	vector<SBU2PushClient *>::iterator iClientList = sbu2ClientList.begin();

	while( iClientList != sbu2ClientList.end() ) {
		SBU2PushClient *client = *iClientList;

		if( client->isMarkedForRemoval() 
				|| client->checkInactivity( t_threshold_time ))  
		{
			fax->deleteTCPClient( client );
			iClientList = sbu2ClientList.erase( iClientList );
			ifSubscriptions->onPushClientClose(client);
			delete client;

		} else {
			iClientList++;
		}
	}


}

void PushServer::closeSession(string sSessionID)
{
	//Lock sessionTable to tackle any incoming request for that session.
	mTableMutex->lock();
	void *conn = sessionTable->getSession( sSessionID );
	mTableMutex->unlock();

	if( conn != NULL ) {
		SBU2PushClient *client = static_cast<SBU2PushClient *>(conn);
		client->markForRemoval();
	}
}

void PushServer::sendToSession(string sSessionID,
		UBACJSON::JsonObject *jsonResponse)
{
	//Lock sessionTable to tackle any incoming request for that session.
	mTableMutex->lock();
	void *conn = sessionTable->getSession( sSessionID );

	if( conn != NULL ) {
		SBU2PushClient *client = static_cast<SBU2PushClient *>(conn);
		client->send(jsonResponse);
	}

	mTableMutex->unlock();
}

void PushServer::sendToAllSessions(JsonObject * jsonResponse)
{
	mTableMutex->lock();

    map<string, void *>::iterator it = sessionTable->begin();
    while( it != sessionTable->end())
    {
        void * conn = it->second;

        if( conn != NULL ) {
            SBU2PushClient *client = static_cast<SBU2PushClient *>(conn);
            client->send(jsonResponse);
        }

        it++;
    }

    mTableMutex->unlock();
}

void PushServer::sendToSession(uint8_t iStreamingRequestType,
        string sSessionID, JsonObject *jsonResponse)
{
    //Lock sessionTable to tackle any incoming request for that session.
    mTableMutex->lock();
    void *conn = sessionTable->getSession( sSessionID );
    //	printf("conn = %p\n", conn);

    if( conn != NULL ) {
        SBU2PushClient *client = static_cast<SBU2PushClient *>(conn);
        client->send(iStreamingRequestType, jsonResponse);
    }

    mTableMutex->unlock();
}

bool PushServer::hasLevel1Subscribed(string sSymbol) {
    bool status;
    mTableMutex->lock();
    status = this->masterTable->l1SymbolTable->isSubscribed(sSymbol);
    mTableMutex->unlock();
    return status;
}

void PushServer::sendLevel1(string sSymbol, JsonObject *jsonResponse)
{
    //Lock symbolTable to tackle any incoming request for that session.
    mTableMutex->lock();
    vector<void *>connList = this->masterTable->l1SymbolTable->getConnList(
            sSymbol );
    if( connList.size() > 0 ) {
        vector<void *>::iterator iConnection = connList.begin();

        while( iConnection != connList.end() ) {
            SBU2PushClient *client = static_cast<SBU2PushClient *>(*iConnection);
            client->send( SBU2StreamingRequest::SBU2StreamingRequest_Level1,
                    jsonResponse );
            iConnection++;
        }
    }

    mTableMutex->unlock();
}

bool PushServer::hasLevel2Subscribed(string sSymbol) {
    bool status;
    mTableMutex->lock();
    status = this->masterTable->l2Symboltable->isSubscribed(sSymbol);
    mTableMutex->unlock();
    return status;
}

void PushServer::sendLevel2(string sSymbol, JsonObject *jsonResponse)
{
    //Lock symbolTable to tackle any incoming request for that session.
    mTableMutex->lock();
    vector<void *>connList = this->masterTable->l2Symboltable->getConnList(
            sSymbol );

    if( connList.size() > 0 ) {
        vector<void *>::iterator iConnection = connList.begin();

        while( iConnection != connList.end() ) {
            SBU2PushClient *client = static_cast<SBU2PushClient *>(*iConnection);
            client->send(SBU2StreamingRequest::SBU2StreamingRequest_Level2,
                    jsonResponse );
            iConnection++;
        }
    }

    mTableMutex->unlock();
}

void PushServer::sendLiveTrades(JsonObject * jsonResponse)
{
    mTableMutex->lock();

    vector<void *> * connList = this->masterTable->liveTradeConns;

    vector<void *>::iterator iConnection = connList->begin();

    while( iConnection != connList->end() ) {

        SBU2PushClient *client = static_cast<SBU2PushClient *>(*iConnection);
        client->send( SBU2StreamingRequest::SBU2StreamingRequest_LiveTrades,
                jsonResponse);
        iConnection++;
    }

    mTableMutex->unlock();
}

void PushServer::sendTradeSymbols(string sSymbol, JsonObject *jsonResponse)
{
    //Lock symbolTable to tackle any incoming request for that session.
    mTableMutex->lock();
    vector<void *>connList =
        this->masterTable->tradeSymbolTable->getConnList( sSymbol );

    if( connList.size() > 0 ) {
        vector<void *>::iterator iConnection = connList.begin();

        while( iConnection != connList.end() ) {
            SBU2PushClient *client = static_cast<SBU2PushClient *>(*iConnection);
            client->send( SBU2StreamingRequest::SBU2StreamingRequest_TradeSymbols,
                    jsonResponse );
            iConnection++;
        }
    }

    mTableMutex->unlock();
}
