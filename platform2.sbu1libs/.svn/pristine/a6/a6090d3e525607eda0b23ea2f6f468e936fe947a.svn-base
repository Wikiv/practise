#ifndef __MSF_BROADCASTER_H__
#define __MSF_BROADCASTER_H__

#include <iostream>
#include <sys/types.h>
#include <fcntl.h>
#include <vector>
#include <signal.h>

#include "TCPServer.h"
#include "SocketIO.h"

using namespace std;

namespace UBAC {
	class MSFBroadcaster:
        	public TCPServer,
        	public SocketIO
	{
		private:
                        size_t index;
			vector<int> clientFd;
        	public:
                	MSFBroadcaster( int port );
			~MSFBroadcaster();
                	void sendData( void *ptr, size_t len );
			void sendData( string data );
                	void createNewClient( int fd );
	};
};

using namespace UBAC;

#endif /* __MSF_BROADCASTER_H__ */
