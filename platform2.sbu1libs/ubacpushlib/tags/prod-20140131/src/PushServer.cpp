#include "PushServer.h"

const uint8_t PushServer::DataType_UBAC = 1;
const uint8_t PushServer::DataType_SBU2 = 2;

static void server_monitor(void *d)
{
	PushServer *server = static_cast<PushServer *>(d);
	server->monitor();
}

PushServer::PushServer(int iPort, time_t uInactivityTimeout, 
                        uint8_t iDataType, EventFax *fax, 
                        IFSubscriptions *ifSubscriptions) 
                    : TCPServer(iPort)
{
    this->ifSubscriptions = ifSubscriptions;
    this->fax = fax;
    this->uInactivityTimeout = uInactivityTimeout;
    this->iDataType = iDataType;

	this->mTableMutex = new Mutex();
	this->sessionTable = new SessionTable();
	this->masterSymbolTable = new MasterSymbolTable();

    this->fax->addPeriodicTimer( server_monitor, this, 1 );

}

PushServer::~PushServer()
{
}

void PushServer::createNewClient(int fd)
{
	cout << "creating " << fd << endl;

	if( iDataType == PushServer::DataType_UBAC ) {
		UBACPushClient *client = new UBACPushClient(fd, ifSubscriptions);
		ubacClientList.push_back(client);
		fax->addTCPClient( client );

	} else if( iDataType == PushServer::DataType_SBU2 ) {
		cout << "creating sbu2 client" << endl;
		SBU2PushClient *client = new SBU2PushClient(fd, sessionTable,
				masterSymbolTable, ifSubscriptions, mTableMutex);

		sbu2ClientList.push_back(client);
		fax->addTCPClient( client );
	}
}

void PushServer::monitorUBACClients()
{
	time_t t_threshold_time = time(NULL) - uInactivityTimeout;
	vector<UBACPushClient *>::iterator iClientList = ubacClientList.begin();

	while( iClientList != ubacClientList.end() ) {
		UBACPushClient *client = *iClientList;

		if( client->isMarkedForRemoval() ) {
			fax->deleteTCPClient( client );
			ubacClientList.erase( iClientList );
			delete client;

		} else {
			client->checkInactivity( t_threshold_time );
			iClientList++;
		}
	}
}

void PushServer::monitor()
{
	if( iDataType == PushServer::DataType_UBAC ) {
		monitorUBACClients();

	} else if( iDataType == PushServer::DataType_SBU2 ) {
		monitorSBU2Clients();
	}
}

void PushServer::monitorSBU2Clients()
{
	time_t t_threshold_time = time(NULL) - uInactivityTimeout;
	vector<SBU2PushClient *>::iterator iClientList = sbu2ClientList.begin();

	while( iClientList != sbu2ClientList.end() ) {
		SBU2PushClient *client = *iClientList;

		if( client->isMarkedForRemoval() ) {
			fax->deleteTCPClient( client );
			sbu2ClientList.erase( iClientList );
			delete client;

		} else {
			client->checkInactivity( t_threshold_time );
			iClientList++;
		}
	}
}

void PushServer::sendToSession(uint8_t iStreamingRequestType,
							   string sSessionID, JsonObject *jsonResponse)
{
	//Lock sessionTable to tackle any incoming request for that session.
	mTableMutex->lock();
	void *conn = sessionTable->getSession( sSessionID );
	printf("conn = %p\n", conn);

	if( conn != NULL ) {
		SBU2PushClient *client = static_cast<SBU2PushClient *>(conn);
		client->send(iStreamingRequestType, jsonResponse);
	}

	mTableMutex->unlock();
}

void PushServer::sendLevel1(string sSymbol, JsonObject *jsonResponse)
{
	//Lock symbolTable to tackle any incoming request for that session.
	mTableMutex->lock();
	vector<void *>connList = this->masterSymbolTable->l1SymbolTable->getConnList(
								 sSymbol );

//	cout << "symbol = " << sSymbol << ", connlist size = " << connList.size() <<
//		 endl;

	if( connList.size() > 0 ) {
		vector<void *>::iterator iConnection = connList.begin();
		while( iConnection != connList.end() ) {
			SBU2PushClient *client = static_cast<SBU2PushClient *>(*iConnection);
			client->sendLevel1( sSymbol, jsonResponse );
			iConnection++;
		}
	}

	mTableMutex->unlock();
}

void PushServer::sendLevel2(string sSymbol, JsonObject *jsonResponse)
{
	//Lock symbolTable to tackle any incoming request for that session.
	mTableMutex->lock();
	vector<void *>connList = this->masterSymbolTable->l2Symboltable->getConnList(
								 sSymbol );

	if( connList.size() > 0 ) {
		vector<void *>::iterator iConnection = connList.begin();

		while( iConnection != connList.end() ) {
			SBU2PushClient *client = static_cast<SBU2PushClient *>(*iConnection);
			client->sendLevel2( sSymbol, jsonResponse );
			iConnection++;
		}
	}

	mTableMutex->unlock();
}

void PushServer::sendTradeSymbols(string sSymbol, JsonObject *jsonResponse)
{
	//Lock symbolTable to tackle any incoming request for that session.
	mTableMutex->lock();
	vector<void *>connList =
		this->masterSymbolTable->tradeSymbolTable->getConnList( sSymbol );

	if( connList.size() > 0 ) {
		vector<void *>::iterator iConnection = connList.begin();

		while( iConnection != connList.end() ) {
			SBU2PushClient *client = static_cast<SBU2PushClient *>(*iConnection);
			client->sendTradeSymbols( sSymbol, jsonResponse );
			iConnection++;
		}
	}

	mTableMutex->unlock();
}
