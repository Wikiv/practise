#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "EventFax.h"
#include "Thread.h"

using namespace std;
using namespace UBACIPC;

class MyClient :
	public TCPClient,
	public Thread
{
	public:
		MyClient(string ip, int port) : TCPClient(ip, port) {}
		~MyClient() {}

		void receive_data(void *ptr, size_t len)
		{
			for (int i = 0; i < len; i++) {
				char c = * ((char *) ptr + i);
				//printf("%x-", c);
			}

            printf("Received lenght %d\n", len);

		    usleep(2000);

		}

		void run()
		{
			while( 1 ) {
				if(!isConnected() && ( this->reconnect() ) )
					static_cast<EventFax*>(th_data)->addTCPClient( this );

				usleep(1000* 1000);
			}
		}

		void unbind()
		{
			cout << "Calling unbind" << endl;
		}
};

void signalHandler(int signal)
{
    cout << "Signal : " << signal << endl;
}

int main()
{
    signal(SIGPIPE, signalHandler);

    EventFax fax;

    for(int i = 0; i < 8000; i++)
    {

        MyClient * tcp_client;

        tcp_client = new MyClient("localhost", 11001);

        fax.addTCPClient(tcp_client);

//        sleep(1);
    }


    fax.run();


}
