#ifndef __UBAC_TCP_CLIENT_H__
#define __UBAC_TCP_CLIENT_H__

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include <sys/types.h>
#ifdef _WIN32
#include <WinSock.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#endif
#include <errno.h>

using namespace std;
#include "ClientDescriptor.h"
#include "SocketIO.h"
#include "CircularBuffer.h"
#include "Mutex.h"


namespace UBACIPC
{
	/// Class TCPClient for creating TCP client applications.
	class TCPClient :
		public ClientDescriptor,
		public SocketIO
	{
		private:
			int clientFd;
			int makeConnection (string ip, int port);
			string m_IP;
			int m_Port;

		protected:
			const static size_t WRITE_BUF_SIZE = 1024 * 5120;
			CircularBuffer * writeBuffer;
			size_t nLeftBytesToWrite;

		private:
			void init();

		public:
			// Create TCPClient application and connect to `ip' @ `port'.
			TCPClient (string ip, int port);
			// Create TCPClient with an existing descriptor.
			// The beauty here is this can be used for unix sockets also.
			TCPClient (int fd);
			TCPClient()
			{
				init();
			}
			~TCPClient ();

			/** Check if the client is still connected. */
			bool isConnected();
			/** Reconnect to the same IP and Port. */
			bool reconnect();
			/** Close the client connection. */
			void closeConnection();
			/** Send 'data' to the client. */
			int sendData (string data);
			/** Read line and store in 'data'. */
			int readLine(string & data);
			/** Read n bytes and store in 'data'. */
			int readNBytes(string & data, size_t nBytes);
			/** Read until you see a delimiter. */
			int readUntilDelimiter(string & data, char c_delimiter);
			/** Read until you see a string delimiter. */
			int readUntilDelimiter(string & data, string sDelimiter);
			/** Set non-blocking IO */
			void setNonBlocking();
			/** Wait for data to be available to read. Time is in milliseconds. */
			bool waitForData(int lTimeToWait);

			/** Same written function available in socket-descriptor.
			 *  Difference is it returns the number of bytes wrote to fd. */
			virtual int asyncWriten(register int fd, register const char *ptr,
							register int nbytes);

			/** Returns true if data is accepted to send. */
			bool asyncSendData(const char * ptr, int nbytes);

			/** Send buffered data if available */
			virtual void sendBufferedData();

			/// Virtual method to handle logic immediately after connecting.
			virtual void onConnect() {}
	};
};

using namespace UBACIPC;

#endif /* __UBAC_TCP_CLIENT_H__ */
