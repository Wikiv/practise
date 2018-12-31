#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>

#include <ubacutils/IFHelper.h>

#include "EventFax.h"
#include "TCPServer.h"
#include "Thread.h"

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
	public TCPServer,
	public Thread
{
	public:

		vector<NewTCPClient *> clients;

		MyServer(int port, int listen_q) : TCPServer(port, listen_q)
		{
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

			clients.push_back(tcp_client);

		}

		void run()
		{
			int j = 0;

			while (1) {
				stringstream ss;
				ss << "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh-";
				ss << j++;
				ss << "\n";

				if ( j == 20000 )
					return;

				string s = ss.str();

				for (int i = 0; i < clients.size(); i++ ) {
					clients.at(i)->asyncSendData(s.c_str(), s.length());
				}

				usleep( 1000 );

			};
		}
};

int main()
{
	MyServer *server;
	server = new MyServer(20001, 1000);
	fax.addTCPServer( server );
//	server->start(NULL);
	fax.run();
}
