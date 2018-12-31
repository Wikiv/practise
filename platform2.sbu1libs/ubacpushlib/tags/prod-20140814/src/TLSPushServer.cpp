#include "TLSPushServer.h"

TLSPushServer::TLSPushServer(int iPort, time_t uInactivityTimeout,
							 EventFax *fax,
							 IFSubscriptions *ifSubscriptions,
							 string sCertificateFile, string sKeyFile)
	:  TCPServer(iPort),
	   PushServer(iPort, uInactivityTimeout,
				  fax, ifSubscriptions),
	   TLSServer(iPort, sCertificateFile, sKeyFile)
{
}

TLSPushServer::~TLSPushServer()
{
}

void TLSPushServer::createNewClient(int fd)
{

	SBU2TLSPushClient *client = new SBU2TLSPushClient(fd, sessionTable,
			masterTable, ifSubscriptions, mTableMutex, ssl_context);

	cout << "creating sbu2 TLS push client : " << fd <<  " : " << client << endl;

	if( client->isSslAcceptSuccessful() ) {
		sbu2ClientList.push_back(client);
		fax->addTCPClient( client );

	} else {
		cout << "Closing connection in TLSPushserver: SSL Accept unsucessful\n";
		close(fd);
		delete client;
	}
}
