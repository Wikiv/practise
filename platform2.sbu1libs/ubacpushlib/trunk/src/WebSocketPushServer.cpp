#include "WebSocketPushServer.h"

WebSocketPushServer::WebSocketPushServer(int iPort, time_t uInactivityTimeout,
							 IFSubscriptions *ifSubscriptions) 
    :  TCPServer(iPort),   
	   PushServer(iPort, uInactivityTimeout, ifSubscriptions)
{
}

WebSocketPushServer::~WebSocketPushServer()
{
}

void WebSocketPushServer::createNewClient(int fd)
{

    SBU2WebSocketPushClient *client = new SBU2WebSocketPushClient(fd, fax, 
            sessionTable, masterTable, ifSubscriptions, mTableMutex, this->bSessionValidation);
    client->setLogger(sLogID);
	
    sbu2ClientList.push_back(client);

    fax->addTCPClient( client );

    if(sLogID){
	    sLogID->debug("New Web socket connection : fd = %d - Addr %p\n", fd, client);
    }

}

