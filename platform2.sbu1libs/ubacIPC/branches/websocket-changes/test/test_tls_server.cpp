#include "TLSServer.h"
#include "TLSClient.h"
#include "EventFax.h"
#include "Thread.h"

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

EventFax fax;

class MyTLSClient :
	public TLSClient,
	public virtual TCPClient
{
	public:
		MyTLSClient(int fd, SSL_CTX *ctx) : TLSClient(fd, ctx), TCPClient(fd)
		{
		}

		void receive_data(void *data, size_t len)
		{
			cout << "Received " << len << " bytes. data = ";
//			cout << (char *)data << endl;
//			this->sendData( string((char *)data, len) );
		}
};


class MyTLSServer :
	public TLSServer,
	public virtual TCPServer,
	public Thread
{
	public:
		MyTLSServer(int iPort, string sCertificate, string sKey, string sKeyPassphrase) 
            : TLSServer(iPort, sCertificate, sKey, sKeyPassphrase),TCPServer(iPort)
		{
		}

		void createNewClient(int fd)
		{
			cout << "Opening create new client" << endl;
			MyTLSClient *tlsClient = new MyTLSClient(fd, this->ssl_context);

            if (tlsClient->isSslAcceptSuccessful())
            {
                fax.addTCPClient( tlsClient );
                clientList.push_back( tlsClient );

            } else {

                delete tlsClient;
            }
        }

        void broadcast(string sData)
        {
            vector<MyTLSClient *>::iterator iList = clientList.begin();
            while( iList != clientList.end() ) {
                (*iList)->asyncSendData( sData.c_str(), sData.length() );
                iList++;
            }
        }

        void run()
        {
            int i = 0;
            string sData = "Hello World";
            size_t nBytes = 0;
            while( clientList.size() == 0 ) {}
            while(1) {
                stringstream s;
                s << sData << i << endl;
                i++;
                broadcast( s.str() );
                nBytes += s.str().length();
                if( nBytes > (200*1024) ) {
                    sleep(1);
                    nBytes = 0;
                }

            }
        }

    private:
        vector<MyTLSClient *>clientList;
};


int main(int argc, char *argv[])
{
    string sCertificate(argv[1]);
    string sKey(argv[2]);
    string sKeyPassphrase(argv[3]);

    MyTLSServer *server = new MyTLSServer(8445, sCertificate, sKey, sKeyPassphrase);

    server->start( NULL );

    fax.addTCPServer( server );
    fax.run();

}
