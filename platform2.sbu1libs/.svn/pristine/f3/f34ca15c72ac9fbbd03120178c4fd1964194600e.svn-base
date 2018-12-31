#include "TLSPushServer.h"

TLSPushServer::TLSPushServer(int iPort, time_t uInactivityTimeout, 
                                uint8_t iDataType, EventFax *fax, 
                                IFSubscriptions *ifSubscriptions,  
                                string sCertificateFile, string sKeyFile) 
                            :  TCPServer(iPort),
                               PushServer(iPort, uInactivityTimeout, iDataType, 
                                       fax, ifSubscriptions),
                               TLSServer(iPort, sCertificateFile, sKeyFile)
{
}

TLSPushServer::~TLSPushServer()
{
}

void TLSPushServer::createNewClient(int fd) 
{
    cout << "creating " << fd << endl;

    if( iDataType == PushServer::DataType_UBAC ) { 
        UBACPushClient *client = new UBACPushClient(fd, ifSubscriptions);
        ubacClientList.push_back(client);
        fax->addTCPClient( client );

    } else if( iDataType == PushServer::DataType_SBU2 ) { 
        cout << "creating sbu2 TLS push client" << endl;
        SBU2TLSPushClient *client = new SBU2TLSPushClient(fd, sessionTable,
                masterSymbolTable, ifSubscriptions, mTableMutex, ssl_context);

        sbu2ClientList.push_back(client);
        fax->addTCPClient( client );
    }   
}
