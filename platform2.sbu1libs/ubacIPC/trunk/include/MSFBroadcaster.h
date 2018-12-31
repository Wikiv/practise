#ifndef __MSF_BROADCASTER_H__
#define __MSF_BROADCASTER_H__

#include <iostream>
#include <sys/types.h>
#include <fcntl.h>
#include <vector>
#include <signal.h>

#include "TCPServer.h"
#include "SocketIO.h"
#include "Mutex.h"

using namespace std;

namespace UBAC
{
	/// Class MSFBroadcaster broadcasts data. Similar to proxy component used in broker backends.
	class MSFBroadcaster:
		public TCPServer,
		public SocketIO
	{
		private:
			size_t index;
			vector<int> clientFd;
			Mutex mMutex;
		public:
			/** Creates new MSFBroadcaster at 'port'. */
			MSFBroadcaster( int port );
			~MSFBroadcaster();
			/** sends data contained in 'ptr' of length 'len' to client. */
			void sendData( void *ptr, size_t len );
			/** sends 'data' to client. */
			void sendData( string data );
			/** creates new client. */
			void createNewClient( int fd );
	};
};

using namespace UBAC;

#endif /* __MSF_BROADCASTER_H__ */
