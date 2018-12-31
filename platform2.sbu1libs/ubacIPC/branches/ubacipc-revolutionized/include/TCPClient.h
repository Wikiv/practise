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

#include "ClientDescriptor.h"
#include "SocketIO.h"
#include "CircularBuffer.h"


namespace UBACIPC
{

	/// Class TCPClient for creating TCP client applications.
	class TCPClient :
		public ClientDescriptor,
		public SocketIO
	{
		private:
			//! clientFd is the File Descriptor  of the socket created for TCP Client.
			int clientFd;
			//!makeConnection is private  member function used by TCPclient Constructor to make TCP Connection
			/*!
			  This function  create a new  socket and connect it  with given server ipaddress  and
			  port  
			  \param ip The server ip address which the client must connect.
			  \param port The server port the client must connect.
			  \return It returns the the socket fd of the client.
			  \sa TCPClient()
			 */
			int makeConnection (string ip, int port);
			//! private data member  which stores the Server IP which Client must connect
			string m_IP;
			//! private data member which stores the Server port the Client must connect
			int m_Port;

		protected:
			//! Buffer size. 
            const static size_t WRITE_BUF_SIZE = 1024 * 5120;
			//! Circular Buffer. 
			CircularBuffer * writeBuffer;
			//! Number of bytes left to write. 
			size_t nLeftBytesToWrite;

		private:
			//! init is private member function where we create Circular buffer of size WRITE_BUF_SIZE  and set nLeftBytesToWrite as zero.
			void init();

		public:
			//! Create TCPClient application and connect to \a ip @ \a  port. 
			/*!
			  This function stores the given  \a ip and \a port in member variable.
			  Then it calls makeConnection() function to create the Socket fd which 
			  is connected to server ip and port.
			  the returned sockect fd is stored in 'descriptor' which is a member variable of base class ClientDescriptor.
			  Then calls init() function to initialize data.
			  \sa makeConnection() , init()
			 */
			TCPClient (string ip, int port);
			//! Create TCPClient with an existing descriptor.
			/*!
			  The beauty here is this can be used for unix sockets also. 
			  We Store the \a fd passed in clientFd member variable. 
			  \param fd the file Descriptor passed
			 */
			TCPClient (int fd);
			//!  Creates new circular buffer of size WRITE_BUF_SIZE. 
			TCPClient()
			{
				init();
			}
			//! Destructor which closes the connection and deallocates the memory
			/*!
			  It call the fuction closeConnection() to close the connection.
			  and frees the Cirular buffer memory.
			 */
			~TCPClient ();

            virtual int handleIN();
            virtual void handleERROR();
            virtual void handleOUT();

			//! Check if the client is still connected. 
			bool isConnected();
			//! Reconnect to the same IP and Port. 
			/*!
			  we call the function makeConnection() to make connection to server ip and port.
			  we reset the write buffer then we call the virtual fuction onConnect() to handle after the connection is made
			  \sa makeConnection() , onConnect(). 
			 */
			bool reconnect();
			//! Close the client connection. 
			/*!
			  This call the close system call to socket fd.
			 */
			void closeConnection();
			//! Send \a data to the client.
			/*!
			  This function sends the data to client socket .
			  It does not guarantee that entire data will be sent.
			  It is the reposibility of the caller  to track number of bytes not sent.
			  \param data The data  that is written to client Socket
			  \return The number of bytes successfully written to client Socket.
			 */
			int sendData (string data);
			//!  Read line and store in 'data'. 
			/*!
			  It calls the read system call and reads the data till we get new line character.
			  \param data The data which is read from socket.
			  \return Number of Bytes read from the socket.`
			 */
			int readLine(string & data);
			//! Read n bytes and store in 'data'. 
			/*!
			  This Function trys to read N Bytes from the socket and write it to \a data variable
			  \param data(output parameter) The data which is read from the socket.
			  \param nBytes(input parameter) The Number of bytes which the function is supposed to read from the socket.
			  \return The Number of Bytes Successfully read from the socket.
			 */
			int readNBytes(string & data, size_t nBytes);
			//! Read until you see a delimiter.
			/*!
			  This function trys to read data from the socket until it recieves the delimeter specifeid in the input.
			  \param data (output parameter) The data which is read from the socket.
			  \param c_delimeter (input parameter) The character delimeter until which the data is read from socket.
			  \return Number of bytes read from the socket.
			 */
			int readUntilDelimiter(string & data, char c_delimiter);
			//! Read until you see a string delimiter. 
			/*!
			  This function trys to read data from the socket until it recieves the delimeter specifeid in the input.
			  \param data (output parameter) The data which is read from the socket.
			  \param sDelimeter (input parameter) The string delimeter until which the data is read from socket.
			  \return Number of bytes read from the socket.
			 */

			int readUntilDelimiter(string & data, string sDelimiter);
			//! Set non-blocking IO 
			/*!
			  Set the socket option as non-blocking using 'fcntl()' system call.
			 */
			void setNonBlocking();
			//! Wait for data to be available to read. Time is in milliseconds.
			/*!
			  This  function is used to wait until we get data in socket.we also specify how ling we need to wait for the data.
			  This implemented is using the 'select()' system call so we can wait in the descriptor until we get the data.
			  \param lTimeToWait The Time in milliseconds we need to wait until we get data in socket.
			  \return True is return if data is there in socket ortherwise returns false.
			 */
			bool waitForData(int lTimeToWait);
			//! Writes N Bytes of given  data to the given \a fd 
			/*!
			  This Function uses the write system call to write the given data to fd and returns number of bytes successfully 
			  written.Note:This function doesn't guarantee that all the bytes will be written.
			  \param fd The File Descriptor in  which the data is going to be written.
			  \param ptr The Data which is supposed to be written to fd.
			  \param nbytes The number of bytes of data to write to fd.
			  \return Then number of bytes successfully written.
			 */
			virtual int asyncWriten(register int fd, register const char *ptr,
					register int nbytes);

			//! Returns true if data is accepted to send.
			bool asyncSendData(const char * ptr, int nbytes);

			//! Send buffered data if available 
			/*!
			  This Function Checks if there is data available in Circular buffer  to write to the fd.
			  If data is avaiable to write it calls the function 'asyncWriten()' to write the data.
			  It also keeps track of the number of bytes successfully written ,so that the residue data which are
			  not send by the asyncWriten can be written in the next write cycle.

            Note:This Function is called by the Eventfax run() function whenever it detects a epoll out event.
            \sa asyncWriten
			 */
			virtual void sendBufferedData();

			//! Virtual method to handle logic immediately after connecting.
			virtual void onConnect() {}
	};
};

using namespace UBACIPC;

#endif /* __UBAC_TCP_CLIENT_H__ */
