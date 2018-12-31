#ifndef __BROKER_HUB_CLIENT_H__
#define __BROKER_HUB_CLIENT_H__

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <sstream>

#include <ubacipc/TCPClient.h>
#include <ubacipc/EventFax.h>
#include <ubacipc/Thread.h>
#include <ubaclogger/SLog.h>

#include "LoadBalancer.h"
#include "Application.h"

/// Class BrokerHubClient to handle requests from sockets instead of RabbitMQ.
class BrokerHubClient :
	public TCPClient,
	public Thread
//	public MessageQueue<string>
{
	public:
		/** Create BrokerHubClient application, which will connect to `ip' and `port' listening by Server.
		  * `m_app' is the Application handler.
		  * `m_logID' is the logger object.
		  * `m_capability' is the broker name.
		  * `poolSize' is the thread pool size.
		  * `m_runType' us the tun mode with threads/processes. Currently use WITH_THREADS. */
		BrokerHubClient(string ip, int port, uint8_t m_runType, Application *m_app,
						SLog *m_logID, string m_capability, int poolSize, bool bReconnect);
		~BrokerHubClient();

		/** Receive request packets from Server. */
		void receive_data(void *ptr, size_t len);
		/** Run method in a loop. This never returns. Reconnection to a server is handled here. */
		void run();
		/** unbind the connection. */
		void unbind();
		/** Method to handle statements, soon after connecting to Server. */
		void onConnect();
		/** Send response `message' back to server. */
		void SendData(string message);

		const static uint8_t WITH_THREADS;
		const static uint8_t WITH_PROCESS;

	private:
		bool bReconnect;
		uint8_t runType;
		string capability;
		Application *app;
		LoadBalancer loadBalancer;
		SLog *sLogID;

		string token;
};

#endif /* __BROKER_HUB_CLIENT_H__ */
