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

#include <stdlib.h>
#include "FileDescriptor.h"

//#define PACKET_SIZE	((16*1024) + 1)

using namespace std;

//! class ClientDescriptor -This class is interface class used to maintain  the Client Fds 

namespace UBACIPC
{
	/// Class ClientDescriptor.
	class ClientDescriptor :
		public FileDescriptor
	{
			// Operations
		public:
			//! Create ClientDescriptor with `fd' as descriptor. 
			ClientDescriptor(int fd);
			ClientDescriptor() {}
			~ClientDescriptor();

			//! Invoke this method to handle an event. 
			/*!
			This funtion is called to handle the an read event.It inturn calls
			readData() funtion to handle the event.
			\sa ReadData()
			*/
			int call ();

			//!Reads data from the descriptor and invokes the callback 'receive_data'.
			/*!
			This function is used to read data from the socket whenever the socket is 
			ready to be read.It uses the read() system call to read the data from the 
			socket.Then it calls the virtual function recieve_data() with data read from 
			socket.
			Note:This function is called by EventFax when it detects EPOLLIN event .
			*/
			virtual int readData ();
			/** Implement this method, to handle the data read from the socket. */
			/*!
			This virtual fuction should be implement by caller to handle the data
			read from the socket.
			\param ptr.The Char pointer which contains the data from socket
			\param len.The Length of buffer data read from socket.
			*/
			virtual void receive_data(void *ptr, size_t len) {}
			//! Virtual method to handle disconnection.
			/*!
			This method handle disconnection of Client,This must be implemented by caller
			*/
			virtual void unbind() {}

            virtual int handleIN() = 0;
            virtual void handleOUT() {}
            virtual void handleERROR() {}

			void setReadBufferSize(size_t s);			

	 	private:
			char * cReadBuffer;
			size_t uReadBufferSize;
	};
};

using namespace UBACIPC;

#endif /* __CLIENT_DESCRIPTOR_H__ */
