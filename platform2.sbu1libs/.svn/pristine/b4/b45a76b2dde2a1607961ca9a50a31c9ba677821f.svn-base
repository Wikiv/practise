#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ubacipc/EventFax.h>
#include <ubacipc/Thread.h>

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
			string s((char *)ptr, len);
			cout << s << endl;
		}

		void run() {
			while( 1 ) {
				cout << "isConnected = " << isConnected() << endl;
				if(!isConnected() && ( this->reconnect() ) )
					static_cast<EventFax*>(th_data)->addTCPClient( this );
				sleep(1);
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
	MyClient *tcp_client;
	tcp_client = new MyClient("localhost", 20001);
	fax.addTCPClient( tcp_client );
	tcp_client->start(&fax);
	fax.run();
}
