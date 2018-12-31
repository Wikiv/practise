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

namespace UBACIPC
{
	/// Class SocketIO
	class SocketIO
	{
		public:
			//! This is like an interface. Create SocketIO.
			SocketIO();
			~SocketIO();
			//! reads n bytes from socket descrpitor .
			/*!
			  Reads n bytes from the socket descriptor \a fd  and stores in the address \a ptr.
			  This is used specifically with sockets, when the size of the packet is known.
			  Note:This Function does not guarentee nbytes will be read from socket,it is responsibility of 
			  caller to keep track how much data is actually read.
			  /param fd.The Socket Fd from data is to read.
			  /param ptr.The char pointer in which data read is stored.
			  /param nbytes. The number of bytes of data to read from socket.
			  /return The number of bytes successfully read.
			*/
			int readn(register int fd, register char *ptr, register int nbytes);
			//!Writes n byte of data to the specified socket.
			/*! Write n bytes into the socket descriptor 'fd', since write operation does not guarantees
			   that it will write all the bytes passed.
			   Note:This function makes best effort to write n bytes to socket but it may fail,
			   it is responsibility of caller to keep track number of bytes acutually written.
			   /param fd The socket Descriptor to which data must be written .
			   /param prt The pointer which contains the data which must be written to socket
			   /param nbytes .The number of bytes of data to write.
			   /return The number of bytes succesfully returned.
			*/
			int writen(register int fd, register const char *ptr, register int nbytes);
	};
};

using namespace UBACIPC;

#endif /* __SOCKET_IO_H__ */
