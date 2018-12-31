#include "TLSPushServer.h"

TLSPushServer::TLSPushServer(int iPort, time_t uInactivityTimeout,
							 IFSubscriptions *ifSubscriptions,
							 string sCertificateFile, string sKeyFile,
                             string sKeyPassphrase)
	:  TCPServer(iPort),
	   PushServer(iPort, uInactivityTimeout, ifSubscriptions),
	   TLSServer(iPort, sCertificateFile, sKeyFile, sKeyPassphrase)
{
}

TLSPushServer::~TLSPushServer()
{
}

void TLSPushServer::createNewClient(int fd)
{

	SBU2TLSPushClient *client = new SBU2TLSPushClient(fd, sessionTable,
			masterTable, ifSubscriptions, mTableMutex, ssl_context, this->bSessionValidation);
	client->setLogger(sLogID);

	if(sLogID){
                sLogID->debug("New TLS client connection : fd = %d - Addr %p\n", fd, client);
        }


	if( client->isSslAcceptSuccessful() ) {
		sbu2ClientList.push_back(client);
		fax->addTCPClient( client );

	} else {
		if(sLogID){
			sLogID->debug("Closing TLS client connection : SSL Accept unsucessful, fd = %d - Addr %p\n", fd, client);
		}
		close(fd);
		delete client;
	}
}

