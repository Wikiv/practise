#include <iostream>

#include "EventFax.h"
#include "WebSocketClient.h"
#include "TCPServer.h"

using namespace std;

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

};

class WebSocketTCPServer :
	public TCPServer
{
    private:
        EventFax * fax;

	public:
		WebSocketTCPServer(int port, EventFax * fax) : TCPServer(port)
		{
            this->fax = fax;
		}

		void createNewClient(int fd)
		{
			cout << "create New WebSocket" << endl;

			WebSocketConnection * wsCon = new WebSocketConnection(fd, this->fax);
			//WebSocketClient * wsCon = new WebSocketClient(fd, this->fax);

			fax->addTCPClient(wsCon);

		}
};

int main()
{
    EventFax fax;

    WebSocketTCPServer * server = new WebSocketTCPServer(8443, &fax);
    fax.addTCPServer( server );

    fax.run();
}
