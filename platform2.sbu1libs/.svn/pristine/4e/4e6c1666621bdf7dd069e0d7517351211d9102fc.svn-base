#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>

#include <ubacutils/IFHelper.h>

#include "EventFax.h"
#include "TCPServer.h"
#include "TLSServer.h"
#include "TLSClient.h"
#include "Thread.h"

using namespace UBACIPC;
EventFax fax;

class MyTLSClient :
    public TLSClient,
	public virtual TCPClient
{
	public:
		MyTLSClient(string ip, int port, string sCertificateFile, string sKeyFile) 
            : TLSClient(ip, port, sCertificateFile, sKeyFile), TCPClient(ip, port)
		{
		}

		void receive_data(void *ptr, size_t len)
		{
			for (int i = 0; i < len; i++) {
				char c = * ((char *) ptr + i);
				printf("%c", c);
			}

			usleep(1000 * 100);
		}

		void unbind()
		{
			cout << "Calling unbind" << endl;
		}
};

int main(int argc, char *argv[])
{
	string sCertificate(argv[1]);
	string sKey(argv[2]);

	MyTLSClient *client = new MyTLSClient("localhost", 12001, sCertificate, sKey);

    fax.setTriggerLevel(EventFax::TriggerType_LEVEL);

    if ( client->isSslAcceptSuccessful() ) 
    {
	    fax.addTCPClient(client);
    
	    fax.run();
    }
}
