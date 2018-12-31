#ifndef __CLIENT_DESCRIPTOR_H__
#define __CLIENT_DESCRIPTOR_H__

#include <iostream>
#include <string>
#include <string.h>
#ifndef _WIN32
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#include <winsock.h>
#endif

#include "SocketDescriptor.h"

#define PACKET_SIZE	((16*1024) + 1)

using namespace std;

/// class ClientDescriptor - 

namespace UBACIPC {
	/// Class ClientDescriptor.
	class ClientDescriptor : 
		public SocketDescriptor 
	{
		// Operations
		public:
			/** Create ClientDescriptor with `fd' as descriptor. */
			ClientDescriptor(int fd);
            ClientDescriptor() {}
			~ClientDescriptor();
		
			/** Invoke this method to handle an event. */	
			int call ();

			/** Reads data from the descriptor and invokes the callback 'receive_data'. */
			virtual int readData ();
			/** Implement this method, to handle the data read from the socket. */
			virtual void receive_data(void *ptr, size_t len) {}
			/** Virtual method to handle disconnection. */
			virtual void unbind() {}
	};
};

using namespace UBACIPC;

#endif /* __CLIENT_DESCRIPTOR_H__ */
