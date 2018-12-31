#include "BrokerHubClient.h"

const uint8_t BrokerHubClient::WITH_THREADS = 0;
const uint8_t BrokerHubClient::WITH_PROCESS = 1;

BrokerHubClient::BrokerHubClient(string ip, int port, uint8_t m_runType,
								 Application *m_app, SLog *m_logID, string m_capability, int poolSize,
								 bool bReconnect) : TCPClient(ip, port)
{
	this->bReconnect = bReconnect;
	sLogID = m_logID;
	capability.append( m_capability );
	app = m_app;
	runType = m_runType;

	for(int i = 0; i < poolSize; i++) {
//		cout << "Adding actor " << i << endl;
		MessageActor *actor;
		actor = new MessageActor(app);
		actor->start(NULL);
		loadBalancer.addActor( *actor );
	}

	printf("sLogID addr = %p\n", sLogID);

	if( isConnected() )
		onConnect();
}

BrokerHubClient::~BrokerHubClient()
{
}

void BrokerHubClient::onConnect()
{
	ServiceCapability service("brokers", capability);
	stringstream capabilityStream;
	capabilityStream << service.toString() << "\n";
	cout << "Sending capability: " << capabilityStream.str() << endl;
	this->sendData(capabilityStream.str());
}

void BrokerHubClient::receive_data(void *ptr, size_t len)
{
	char *c_data = (char *)ptr;
	string message( c_data, len );

	for(size_t i = 0; i < len; i++) {
		token.append(&message[i], 1);

		if( message[i] == '\n' ) {
			if( sLogID ) {
				string logMessage;
				maskLogin(token, logMessage);
				sLogID->debug("Received: %s", logMessage.c_str());
			}

			loadBalancer.addMessage( token, this );
			token.clear();
		}
	}
}

void BrokerHubClient::run()
{
	while(1) {
		if( !isConnected() && (this-reconnect()) ) {
			if( !bReconnect )
				exit(0);

			static_cast<EventFax*>(th_data)->addTCPClient( this );

			if( !isConnected() )
#ifdef _WIN32
				Sleep(1000);

#else
				sleep(1);
#endif

		} else {
#ifdef _WIN32
			Sleep(1000);
#else
			sleep(1);
#endif
		}
	}
}

void BrokerHubClient::unbind()
{
}

void BrokerHubClient::SendData(string message)
{
	if( sLogID )
		sLogID->debug("Sending: %s", message.c_str());

	this->sendData( message );
}
