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

class NewTLSClient :
    public TLSClient,
    public virtual TCPClient
{
    public:
        NewTLSClient(int fd, SSL_CTX *ctx) : TLSClient(fd, ctx), TCPClient(fd)
    {
    }

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
    public TLSServer,
    public virtual TCPServer,
    public Thread
{
    vector<NewTLSClient *> clients;

    public:

    MyServer(int iPort, string sCertificate,string sKey) : TLSServer(iPort,
            sCertificate, sKey), TCPServer(iPort)
    {
    }
    ~MyServer();

    void createNewClient(int fd)
    {
        IFHelper helper;
        cout << "Creating a new client with fd = " << fd << endl;
        NewTLSClient *tcp_client;
        tcp_client = new NewTLSClient(fd, this->ssl_context);

        if (tcp_client->isSslAcceptSuccessful()) {

            fax.addTCPClient( tcp_client );

            clients.push_back(tcp_client);
        } else 
        {
            delete tcp_client;
        }

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

            usleep( 5000 );

        };
    }
};

int main(int argc, char *argv[])
{
    string sCertificate(argv[1]);
    string sKey(argv[2]);
    MyServer *server = new MyServer(12001, sCertificate, sKey);

    server->start( NULL );

    fax.setTriggerLevel(EventFax::TriggerType_LEVEL);

    fax.addTCPServer( server );

    fax.run();
}
