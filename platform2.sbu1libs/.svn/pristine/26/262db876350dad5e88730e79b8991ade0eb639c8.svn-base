#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "EventFax.h"
#include "Thread.h"

using namespace std;
using namespace UBAC;

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
				printf("%c", c);
			}

			usleep(1000 * 5000);

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

int main()
{
	EventFax fax;

	MyClient * tcp_client;

	tcp_client = new MyClient("localhost", 13001);

	fax.addTCPClient( tcp_client );

	tcp_client->start(&fax);

	fax.run();
}
