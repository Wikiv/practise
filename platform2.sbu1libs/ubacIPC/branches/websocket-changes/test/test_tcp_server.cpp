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
EventFax *fax;

class NewTCPClient :
	public TCPClient
{
	public:
        
        int recvCount;

		NewTCPClient(int fd) : TCPClient(fd) { recvCount = 0; }

		void receive_data(void *ptr, size_t len)
		{
			string data( (char *)ptr, len);
			cout << data << endl;
			//this->sendData(data);
		}

		void unbind()
		{
			cout << "Calling unbind" << endl;
            closeConnection();
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

        ~MyServer() {}

        void gen_random(string & s, const int len) {

            static const char alphanum[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";

            for (int i = 0; i < len; ++i) {
                s.append( & alphanum[rand() % (sizeof(alphanum) - 1)], 1);
            }

            s[len] = '\n';
        }

        void createNewClient(int fd)
        {
            IFHelper helper;
            cout << "For pid = " << getpid() << " Creating a new client with fd = " << fd << endl;
            NewTCPClient *tcp_client;
            tcp_client = new NewTCPClient(fd);
            fax->addTCPClient( tcp_client );

            clients.push_back(tcp_client);

        }

        void run()
        {
            int j = 0;

            while (1) {
                /*stringstream ss;
                ss << "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh-";
                ss << j++;
                ss << "\n";

                if ( j == 20000 )
                    return;

                string s = ss.str();
                */

                string s;
                gen_random(s, 1 * 1024);
                s.append(1, '\n');

    
                vector<NewTCPClient *>::iterator itr = clients.begin();
                while ( itr != clients.end() ) {
                    //clients.at(i)->asyncSendData(s.c_str(), s.length());

                    NewTCPClient * client = * itr;

                    bool bFlag = client->asyncSendData(s.c_str(), s.length());

                    if  ( ! bFlag )
                    {
                        cout    << "Sending data with length " << s.length()
                                << " : " << client->recvCount << endl;

                        //delete client;
                        clients.erase(itr);
                    } else {
                        
                        client->recvCount++;

                        //cout    << "Sending data with length " << s.length()
                        //        << " : " << client->recvCount << endl;
                        itr++;
                    }

                }

//                usleep( 1000 );

            };
        }
};


MyServer *server = NULL;

void handleSignal(int signal)
{
    cout << __func__ << " " << signal << endl;
    delete server;
}

int main()
{

    //signal(SIGINT, handleSignal);
    signal(SIGPIPE, SIG_IGN);

    server = new MyServer(20001, 1000);

    /*	pid_t pid;
        for(int i = 0; i < 100; i++) {
        pid = fork();
        if( pid == 0 ) {
        fax = new EventFax();
        fax->addTCPServer( server );
        fax->run();
        } else {
        cout << "pid = " << pid << endl;
        }
        }
        pause();
        server->start(NULL);
        */
    fax = new EventFax();
    fax->addTCPServer(server);
    server->start(NULL);
    fax->run();
}
