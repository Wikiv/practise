#include <iostream>

#include "EventFax.h"
#include "WebSocketClient.h"
#include "TCPServer.h"

using namespace std;

static void cleanupWSConnections(void *data);

class WebSocketConnection:
	public WebSocketClient
//    public virtual TCPClient
{
	public:
		WebSocketConnection(int fd, EventFax * fax)
			: WebSocketClient(fd, fax), TCPClient(fd)
		{
		}

		void onMessageinWebsocket( char * data, size_t len )
		{
            string s(data, len);

			cout << "Message from WebSocket Client : " << s << endl;

			this->send("From WebSocket Server : Hai");
		}

		void unbind() {

			cout << "unbind" << endl;

		}


};

class WebSocketTCPServer :
	public TCPServer
{
    private:
        EventFax * fax;

		vector <WebSocketConnection *> vConnections;

	public:
		WebSocketTCPServer(int port, EventFax * fax) : TCPServer(port)
		{
            this->fax = fax;
            this->fax->addPeriodicTimer( ::cleanupWSConnections, this, 1);
		}

		void createNewClient(int fd)
		{
			cout << "create New WebSocket" << endl;

			WebSocketConnection * wsCon = new WebSocketConnection(fd, this->fax);
			//WebSocketClient * wsCon = new WebSocketClient(fd, this->fax);

			vConnections.push_back( wsCon );
			fax->addTCPClient(wsCon);

		}

		void cleanupWSConnections()
		{
			vector<WebSocketConnection *>::iterator iConnection;

			for(iConnection = vConnections.begin(); iConnection != vConnections.end();) {

				if ( ( (* iConnection)->isMarkedForRemovalFromEventFax())
						|| ((* iConnection)->isRemFromEFax() ) ){

					delete (* iConnection);
					iConnection = vConnections.erase( iConnection );

				} else {
					iConnection++;
				}
			}
		}
};

static void cleanupWSConnections(void *data)
{
	WebSocketTCPServer *wsServer = static_cast<WebSocketTCPServer *>(data);
	wsServer->cleanupWSConnections();
}

int main()
{
    EventFax fax;

    WebSocketTCPServer * server = new WebSocketTCPServer(8443, &fax);
    fax.addTCPServer( server );

    fax.run();
}
