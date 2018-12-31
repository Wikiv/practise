#ifndef __TCP_SERVER_H
#define __TCP_SERVER_H

#include <iostream>
#include <sys/types.h>
#include <fcntl.h>
#include <map>

#include "TCPClient.h"

using namespace std;

namespace UBACIPC {
	/// class TCPServer - 
	class TCPServer :
		public SocketDescriptor
	{
		
		public:
			/** Create TCP Server at 'port'. */
			TCPServer (int port, int listen_q = FD_SETSIZE);
			~TCPServer ();
			TCPServer () {}

			/** Get the socket descriptor for the server socket. */
			int getDescriptor();

			/** Accept client connection and return the socket descriptor for the connection. */
			int acceptClientConnection();
			/** Implement this method to handle the new connection created with the descriptor as 'fd'. */
			virtual void createNewClient(int fd) {}

		private:
			int startServer (int port, int listen_q);
			map<int, TCPClient *> clientDescriptorHash;
	};
};

using namespace UBACIPC;

#endif /* __TCP_SERVER_H */
