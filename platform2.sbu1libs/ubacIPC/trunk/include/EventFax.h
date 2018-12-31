#ifndef __EVENT_FAX_H__
#define __EVENT_FAX_H__

#ifdef _WIN32
#define FD_SETSIZE      64*64
#include <windows.h>
#else
#include <sys/epoll.h>
#endif

#include <iostream>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#include <vector>
#include <algorithm>

#include "FileDescriptor.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "TimerEvents.h"

namespace UBACIPC
{

    using namespace std;

	/*! This implements a event triggered IO handling for sockets. This provides an interface
	    to add TCPServer objects and TCPClient objects, so as to be monitored for events.
	    Events monitored for TCPServer includes accepting of new connections and closing of server.
	    Events monitored for TCPClient includes availability of data for reading and for closing of
	    connections.
  	*/
	class EventFax
	{
			// Attributes
		private:
			//! epoll descriptor used for running event loop.
			int epollFd;
			//! Trigger used. 
			/*!
			There are two Type of trigger in Event poll Edge trigger or Level trigger
			Pls reffer to man page of epoll for more details.
			Note:Edge trigger is used in this class by Default.
			*/
			uint16_t uTrigger;

			// Operations
		public:
			//! Contructor for Event fax class
			/*!
			This initializes the epollfd by calling createEventDescriptor() Function.
			Sets uTrigger to Edge triggered.
			*/
			EventFax ();
			//! Destructor For Event Fax
			~EventFax ();
			//! Run the event loop. 
			/*!
			This is the main Fuction which monitors for Events using epoll_wait() System call.
			It  monitor the Client and Server Fd List which it maintains.
			whenever an EPOLLIN event  occurrs it First Checked if the EpollFd matches any of
			Client Fd it maintains .

				If it is present in the Client fd List ,it implies  this is an read event for the Client.
				So it call the  readData() Function of the Corressponding Client Object
				(ClientFd and Client Object are maintained as map).
				Note: readData() Function reads the data and calls the recieve_data() virtual function to 
				handle the data which is read.

				If the epollFd does not match the ClientFd List it checks it matches the ServerFd List.
				If there is a match it means this is a new client connection ,so it calls the
				acceptClientConnection() funtion of the Server object for which the new connection
				is requested(This is done by maintaining the map of serverFd and Corressponding Server object)
				Note: acceptClientConnection() calls the virtual function CreateNewClient() so that caller
				can handle the new client connection.

			Whenever an EPOLLOUT event has occurred it checks whether EpollFd matches the ClientFd list.
				if  a match is found it calls sendBufferedData() function of the Corresponding Client Object
				(Using the map of ClientFd and Client Object)
				Note:The sendBufferedData() function stores the data in Circular buffer and sends the data to 
				corresponding Client Fd.
			
			Whenever an EPOLLHUP or EPOLLERR event occurs for the EpollFd.The EpollFd is comparred with ClientFd List
			maintained.
			When an match is found it 
				1.It first removes the epollFd from the epollfd list using epoll_ctl() System call.
				2.It calls closeConnection function of the Coressponding Client object to close the
				connection and freeing the memory
				3.Then it calls the unbind() function of the Corresspoinding client object.
				4.Then it removes the ClientFd from the ClientFd List it maintains		

			At last it checks if there is any timer Event and handles the event.
			Then it goes back to monitoring the Server and Client again.(Note:This function is infinite loop 
			which never terminates)
			*/
			void run ();
            void WINRun();
			//!* Add TCPClient object to the event loop. 
			/*!
			This Function is used to add new Client which are to be monitored by Event fax.
			It gets the Descriptor from the client object and make the Descriptor as non-Blocking using
			fcntl() system call.Then it checks if the ClientFd is already present in ClientDescriptorHash it
			maintains(ClientdescriptorHash is member variable which is map of Clientfd and Client object )
				if present it deletes that entry from map .and adds the clientFd and Client object to map.
				if not present it just adds the new entry.
			Then it adds the Client Fd to the list of Epollfd it monitors using epoll_ctl() system call.
			Note : It is reponsibility of the application which uses the Eventfax to call this function so it can
			be monitored.(This is usually done in creatNewClient() function of the application )
			*/
			void addTCPClient (TCPClient *tcp_client);
			//! Delete TCPClient object. 
			/*!
			This Function is responsible for remove the Client from being monitered by Event fax.
			It removes the Client from the Client Descriptor lists  which is mainatained by Event Fax.
			It should be called whenever server dectects client is closed.
			so it is resposiblity of the funtion monitoring the server to called this funtion whenever it 
			detects client is closed.
			/param tcp_client .The Client object which needs to be monitored
			
			*/
			void deleteTCPClient(TCPClient *client);
			//! Add TCPServer object to the event loop. 
			/*!
			This function is used to add new Server Object which is to be monitored by Event Fax.
			It gets the Server Descriptor and makes it non blocking using fcntl() system call.
			 Then it checks if the ServerFd is already present in ServerDescriptorHash it
			maintains(ServerdescriptorHash is member variable which is map of Serverfd and Server object )
				if present it deletes that entry from map .and adds the ServerFd and Sever object to map.
				if not present it just adds the new entry.
			Then it adds the Server Fd to the list of Epollfd it monitors using epoll_ctl() system call.
			Note : It is reponsibility of the application which uses the Eventfax to call this function so it can
			be monitored.(This is usually done when we start the server application )
			/param .The client object which needs to be removed from monitoring.
			*/
			void addTCPServer(TCPServer *tcp_server);

            void addOUTEvent(FileDescriptor * f_d);

            void removeOUTEvent(FileDescriptor * f_d);
            
            void addFileDescriptor(FileDescriptor * f_d);

            void delFileDescriptor(FileDescriptor * f_d);
            //! Stop event loop.
            /*!
              This funtion needs to be called whenever it required to stop the event loop monitoring.
              */
            void stop();
            //! Add timed events. 
            /*!
              This funtion is used to timer events to Event Fax.
              /param f .The Function pointer of the Funtion which needs to be called when timer has expired.
              /param data.The data which needs to be passed to Function.
              /timer.The Time in secs after which the event should be triggered
              */
            void addTimer( void (*f)(void *), void *data, uint16_t timer);
            //! Add periodic timed events. 
            /*!
              This Function is used to add periodic Timer to the Event fax.
              /param f .The Function pointer of the Funtion which needs to be called when timer has expired.
              /param data.The data which needs to be passed to Function.
              /timer.The Time in secs after which the event should be triggered
              */
            void addPeriodicTimer( void (*f)(void *), void *data, uint32_t timer);
            //! Set event trigger type. EDGE or LEVEL triggered. 
            void setTriggerLevel(uint16_t u8Trigger);
            //! Trigger type definition EDGE. 
            const static uint16_t TriggerType_EDGE;
            //! Trigger type definition LEVEL. 
            const static uint16_t TriggerType_LEVEL;

            static int EPOLL_WAIT_TIMEOUT;

        private:

            int createEventDescriptor ();

            TimerEvents timerEvents;

            vector<FileDescriptor *> vReadFileDesc;

            void remFromVReadFileDesc(FileDescriptor *);

            void checkReadEvent( vector<FileDescriptor *> & vEventFileDesc );

#ifdef _WIN32

            fd_set *read_fds;
            int _nfds;
#else
            enum { MAX_EPOLL_DESCRIPTORS = 64 * 1024 };

            void raiseException (string error, int errorNumber);
#endif
            bool requestedStop;

            static void printEvents(struct epoll_event * ev, FileDescriptor * _fd);
    };
};

#endif /* __EVENT_FAX_H__ */
