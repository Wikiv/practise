#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include <ubacipc/TCPServer.h>
#include <ubacutils/IFHelper.h>
#include <ubacipc/EventFax.h>

using namespace UBACIPC;
EventFax fax;

class NewTCPClient :
	public TCPClient
{
	public:
		NewTCPClient(int fd) : TCPClient(fd) {}
		void receive_data(void *ptr, size_t len)
		{
			string data( (char *)ptr, len);
			cout << "Length = " << len << endl;
		}

		void unbind()
		{
			cout << "Calling unbind" << endl;
		}
};

class MyServer :
	public TCPServer
{
	public:
		MyServer(int port, int listen_q) : TCPServer(port, listen_q) {
			if( descriptor < 0 )
				exit(0);
		}

		~MyServer();

		void createNewClient(int fd)
		{
			IFHelper helper;
			cout << "Creating a new client with fd = " << fd << endl;
			NewTCPClient *tcp_client;
			tcp_client = new NewTCPClient(fd);
			fax.addTCPClient( tcp_client );
		}
};

int main()
{
	MyServer *server;
	server = new MyServer(20001, 1000);
	fax.addTCPServer( server );
	fax.run();
}
