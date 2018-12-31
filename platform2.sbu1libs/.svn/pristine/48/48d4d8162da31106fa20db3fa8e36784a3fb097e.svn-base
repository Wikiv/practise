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
	public virtual TCPClient,
    public Thread
{
	public:
		MyTLSClient(string ip, int port) 
            : TLSClient(ip, port), TCPClient(ip, port)
		{
			dummy_counter = 0;
		}

		void receive_data(void *ptr, size_t len)
		{
			dummy_counter++;
			for (int i = 0; i < len; i++) {
				char c = * ((char *) ptr + i);
				printf("%c", c);
			}
			if(dummy_counter == 10 )
				this->sendData("{}");

		//	usleep(1000 * 10);

		}

		void unbind()
		{
			cout << "Calling unbind" << endl;
		}
	private:
		int dummy_counter;
};

int main(int argc, char *argv[])
{
    //MyTLSClient *client = new MyTLSClient("deback01.rhbinvest.co.id", 12001, sCertificate, sKey);
    MyTLSClient *client = new MyTLSClient("localhost", 8443);

    cout << "Created TLSCLient" << endl;

    string request = "{\"request\":{\"data\":{\"symbols\":[{\"symbol\":\"\"},{\"symbol\":\"1082_CDS\"},{\"symbol\":\"-29\"},{\"symbol\":\"1007_CDS\"},{\"symbol\":\"7229_NSE\"},{\"symbol\":\"208709_MFO\"}]},\"streaming_type\":\"quote\",\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"foo\"}}\n";
    //string request = "{\"request\":{\"data\":{\"symbols\":[{\"symbol\":\"53181_NFO\"},{\"symbol\":\"53181_NFO\"},{\"symbol\":\"-29\"},{\"symbol\":\"7257_NSE\"},{\"    symbol\":\"7229_NSE\"},{\"symbol\":\"22_NSE\"}]},\"streaming_type\":\"quote\",\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"foo\"}}\n";

    if ( client->isSslAcceptSuccessful() ) 
      {
      fax.addTCPClient(client);

      cout << "Client is connected" << endl;

      client->sendData(request);
        cout << "req send" << endl;
      fax.run();
      }
}
