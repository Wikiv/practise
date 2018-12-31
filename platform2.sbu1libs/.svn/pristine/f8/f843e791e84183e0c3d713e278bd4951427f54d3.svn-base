#include <ubacipc/TLSServer.h>
#include <ubacipc/TLSClient.h>
#include <ubacipc/EventFax.h>

EventFax fax;

class MyTLSClient :
	public TLSClient
{
	public:
		MyTLSClient(int fd, SSL_CTX *ctx) : TLSClient(fd, ctx)
		{
		}

		void receive_data(void *data, size_t len)
		{
			cout << "Received " << len << " bytes. data = ";
			cout << (char *)data << endl;
			this->sendData( string((char *)data, len) );
		}
};


class MyTLSServer : 
	public TLSServer,
    public virtual TCPServer
{
	public:
		MyTLSServer(int iPort, string sCertificate,string sKey) : TLSServer(iPort, sCertificate, sKey), TCPServer(iPort)
		{
		}

		void createNewClient(int fd)
		{
			cout << "Opening create new client" << endl;
			MyTLSClient *tlsClient = new MyTLSClient(fd, this->ssl_context);
			fax.addTCPClient( tlsClient );
		}
};


int main(int argc, char *argv[])
{
	string sCertificate(argv[1]);
	string sKey(argv[2]);
	MyTLSServer *server = new MyTLSServer(5000, sCertificate, sKey);

	fax.addTCPServer( server );
	fax.run();
}
