#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "EventFax.h"
#include "Thread.h"

using namespace std;
using namespace UBAC;

class MyClient :
	public TCPClient,
	public Thread
{
	public:
		MyClient(string ip, int port) : TCPClient(ip, port) {}
		~MyClient() {}

		string output;

		void receive_data(void *ptr, size_t len)
		{

			for (int i = 0; i < len; i++) {
				char c = * ((char *) ptr + i);

				if ( c == '\n' ) {
					cout << "^" << output << "$" << endl;
					output.clear();

				} else {

					output.append(&c);
				}
			}
			/*
			if( rand()%2 == 0 )
				usleep(500000);
			else
				usleep(1000);
				*/
			//usleep(500000);
			sleep(5);

		}

		void run()
		{

			int i = 0;

			string req = "";

			while( 1 ) {
				if(!isConnected() && ( this->reconnect() ) ) {
					static_cast<EventFax*>(th_data)->addTCPClient( this );

					usleep( 1000 * 100);
					continue;
				}

				usleep(1000 * 1000 * 3);

				if ( i % 2 == 0 ) {

					req = "{\"request\":{\"data\":{},\"streaming_type\":\"liveTrades\",\"request_type\":\"unsubscribe\",\"response_format\":\"json\",\"session\":\"foo\"}}";

				} else if ( i % 3 == 0 ) {

					req = "{\"request\":{\"data\":{},\"streaming_type\":\"liveTrades\",\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"foo\"}}";

				} else if ( i % 5 == 0) {

					req = "{\"request\":{\"data\":{\"symbols\":[{\"symbol\":\"AUD/IDR\"},{\"symbol\":\"RPMAS\"},{\"symbol\":\"LGD\"},{\"symbol\":\"EUR/USD\"},{\"symbol\":\"JPY/IDR\"},{\"symbol\":\"EUR/IDR\"}]},\"streaming_type\":\"quote\",\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"foo\"}}";

				} else {

					req = "{\"request\":{\"data\":{\"symbols\":[{\"symbol\":\"AUD/IDR\"},{\"symbol\":\"RPMAS\"},{\"symbol\":\"LGD\"},{\"symbol\":\"EUR/USD\"},{\"symbol\":\"JPY/IDR\"},{\"symbol\":\"EUR/IDR\"}]},\"streaming_type\":\"quote\",\"request_type\":\"unsubscribe\",\"response_format\":\"json\",\"session\":\"foo\"}}";

				}

				cout << "Sending request ##### " << req << endl;
				sendData(req + "\n");

				i++;

			}
		}

		void unbind()
		{
			cout << "Calling unbind" << endl;
		}
};

int main(int argc, char *argv[])
{
	string sSession(argv[1]);
	EventFax fax;

	MyClient * tcp_client;

	tcp_client = new MyClient("localhost", 10444);

	fax.addTCPClient( tcp_client );
//	tcp_client->start(&fax);

//	string req =
//		"{\"request\":{\"data\":{},\"streaming_type\":\"liveTrades\",\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"foo\"}}";
	string sLevel1 = 
	"{\"request\":{\"appID\":\"a673e59efd2c45646a611f79a925fb6a\",\"data\":{\"symbols\":[{\"symbol\":\"USD/JPY\"},{\"symbol\":\"GBP/PLN\"},{\"symbol\":\"USD/CAD\"},{\"symbol\":\"USD/CHF\"},{\"symbol\":\"EUR/USD\"},{\"symbol\":\"EUR/GBP\"},{\"symbol\":\"EUR/JPY\"},{\"symbol\":\"EUR/CAD\"},{\"symbol\":\"GBP/USD\"}]},\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"" + sSession + "\",\"streaming_type\":\"quote\"}}";

	string sAccountUpdate = 
	"{\"request\":{\"appID\":\"a673e59efd2c45646a611f79a925fb6a\",\"data\":{},\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"" + sSession + "\",\"streaming_type\":\"accountUpdate\"}}";
	string sPositionUpdate = 
	"{\"request\":{\"appID\":\"a673e59efd2c45646a611f79a925fb6a\",\"data\":{},\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"" + sSession + "\",\"streaming_type\":\"positions\"}}";
	tcp_client->sendData( sLevel1 + "\n");
	tcp_client->sendData( sAccountUpdate + "\n");
	tcp_client->sendData( sPositionUpdate + "\n");

	fax.run();
}
