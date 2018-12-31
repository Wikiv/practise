#include "WebSocketPushServer.h"

WebSocketPushServer::WebSocketPushServer(int iPort, time_t uInactivityTimeout,
							 EventFax *fax, IFSubscriptions *ifSubscriptions) 
    :  TCPServer(iPort),   
	   PushServer(iPort, uInactivityTimeout, fax, ifSubscriptions)
{
}

WebSocketPushServer::~WebSocketPushServer()
{
}

void WebSocketPushServer::createNewClient(int fd)
{

    SBU2WebSocketPushClient *client = new SBU2WebSocketPushClient(fd, fax, 
            sessionTable, masterTable, ifSubscriptions, mTableMutex);

    sbu2ClientList.push_back(client);

    fax->addTCPClient( client );
}
