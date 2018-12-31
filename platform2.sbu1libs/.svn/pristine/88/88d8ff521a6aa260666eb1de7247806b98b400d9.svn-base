#ifndef __TCP_SERVER_H
#define __TCP_SERVER_H

#include <iostream>
#include <cstring>
#include <fcntl.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "FileDescriptor.h"


namespace UBACIPC
{

    using namespace std;

    //! class TCPServer:This class can be used by application to create an TCP Server application .
	/*!
	  This class implements all the basic functionallity of a TCP Server like creating  a TCP 
	  socket in the Specified ip and port .Then it listens to the port for new TCP client 
	  connection.

	  Note:This class also has a virtual function Create new Client.So it is the responsibility of 
	  the caller to maintain list of all the active TCP Clients the Server is handling.
	 */
	class TCPServer :
		public FileDescriptor
	{

		public:
			//! Create TCP Server at \a port with listen queue size as \a listen_q
			/*!
			  The Constructor call the function startServer() to create a TCP server .
			  That function creates a non blocking socket using fcntl() system call.
			  and uses the bind() system call to bind the server ip address and port
			  to the socket created.
			  \param port The port this the Server must listen to for Client connection.
			  \listen_q The maximum limit of the listen queue of the server.
			 */
			TCPServer (int port, int listen_q = FD_SETSIZE);
			//! Destructor of the class
			virtual ~TCPServer ();
			TCPServer () {}

			//! Get the socket descriptor for the server socket. 
			virtual int handleIN();
            virtual void handleERROR() {}
            virtual void handleOUT() {}

			//! Accept client connection and return the socket descriptor for the connection. 
			/*!
			  This Funtion waits in the infinite while loop for new client connetion.
			  Accepts the new connection using accept() system call(Since the socket is non blocking accept call
			  would not wait infintely for a connection.it returns immediately).

			  After the new client is connected it call the virtual funtion createNewClient().Which is 
			  call_back function implemented in Super class used by it to  maintain the list of  client 
			  connected.
			   Note:The acceptClientConnection is called by EventFax run() function whenever it detects 
			   an EPOLLIN Event and there is epoll fd is same as the server fd.
			 */
			int acceptClientConnection();
			//! Implement this method to handle the new connection created with the descriptor as 'fd'. 
			/*!
			  This fuction is called by acceptClientConnection() when new client is connected.
			  It is responsibility of caller to  implemented this function in Super class to maintain the
			  listed of client it is connected .
			  \param fd This is the File Descriptor of the new Client connected to the server.
			  \sa acceptClientConnection()  
			 */
			virtual void createNewClient(int fd) {}

		private:
			//! This Function is Called by TCPServer() to crete server.
			/*!
			  This is private member funtion which is used by constructor to create server
			  at specified port .
			  \sa TCPServer()
			 */
			int startServer (int port, int listen_q);
	};
};


#endif /* __TCP_SERVER_H */
