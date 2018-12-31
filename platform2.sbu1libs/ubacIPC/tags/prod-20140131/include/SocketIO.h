#ifndef __UBAC_SOCKET_IO_H__
#define __UBAC_SOCKET_IO_H__

#ifdef _WIN32
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>
#include <winsock.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace UBACIPC {
	class SocketIO {
		public:
			/// This is like an interface. Create SocketIO.
			SocketIO();
			~SocketIO();
			
			/** Reads n bytes from the socket descriptor 'fd' and stores in the address 'ptr'. 
			  * This is used specifically with sockets, when the size of the packet is known. */
			int readn(register int fd, register char *ptr, register int nbytes);
			/** Write n bytes into the socket descriptor 'fd', since write operation does not guarantees
			  * that it will write all the bytes passed. */
			int writen(register int fd, register const char *ptr, register int nbytes);
	};
};

using namespace UBACIPC;

#endif /* __SOCKET_IO_H__ */
