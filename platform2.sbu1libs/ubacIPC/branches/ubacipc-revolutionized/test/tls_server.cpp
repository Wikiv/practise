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

useconds_t delay_sec = 1000 * 1000;
bool flag = true;

void signalHandler(int signal)
{
    cout << "Signal : " << signal << endl;
    if ( flag == true )
    {
        delay_sec = 0;
        flag = false;
    } else 
    {
        delay_sec = 1000 * 100;
        flag = true;
    }

    cout << "Delay Sec " << delay_sec << endl;
}

class NewTLSClient :
    public TLSClient,
    public virtual TCPClient
{
    public:
        size_t totalBytes;

        NewTLSClient(int fd, SSL_CTX *ctx) : TLSClient(fd, ctx), TCPClient(fd)
        {
            totalBytes = 0;
        }

        void receive_data(void *ptr, size_t len)
        {
            //string data( (char *)ptr, len);
            //cout << "^" << data << "$" << endl;

            totalBytes += len;
        }

        void unbind()
        {
            cout << "Calling unbind -- " << totalBytes << endl;
        }
};

class MyServer :
    public TLSServer,
    public virtual TCPServer,
    public Thread
{
    vector<NewTLSClient *> clients;

    public:

    MyServer(int iPort, string sCertificate,string sKey, string _s) : TLSServer(iPort,
            sCertificate, sKey, _s), TCPServer(iPort)
    {
    }
    ~MyServer() {}

    void createNewClient(int fd)
    {
        IFHelper helper;
        cout << "Creating a new client with fd = " << fd << endl;
        NewTLSClient *tcp_client;
        tcp_client = new NewTLSClient(fd, this->ssl_context);

        fax.addTCPClient( tcp_client );

        clients.push_back(tcp_client);

    }

    void run()
    {
        int j = 0;

        while (1) {
            stringstream ss;
            ss << "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh-";
            ss << j;
            ss << "\n";

            if (clients.size() > 0 )
            {


                string s = ss.str();

                for (int i = 0; i < clients.size(); i++ ) {
                    clients.at(i)->asyncSendData(s.c_str(), s.length());
                }

                usleep( delay_sec );

                j++;
            }

        };
    }
};

int main(int argc, char *argv[])
{
    signal(SIGPIPE, signalHandler);
    signal(SIGINT, signalHandler);

    string sCertificate(argv[1]);
    string sKey(argv[2]);
    MyServer *server = new MyServer(12001, sCertificate, sKey, "");

    server->start( NULL );

    fax.addTCPServer( server );

    fax.run();
}
