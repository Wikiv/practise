#ifndef __EVENT_FAX_H__
#define __EVENT_FAX_H__

#include <iostream>
#include <map>
#ifdef _WIN32
#define FD_SETSIZE      64*64
#include <windows.h>
#else
#include <sys/epoll.h>
#endif
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#include "TCPClient.h"
#include "TCPServer.h"
#include "UDPClient.h"
#include "Mutex.h"
#include "TimerEvents.h"

#ifndef _WIN32
extern int errno;
#endif

using namespace std;

namespace UBAC {
	/** This implements a event triggered IO handling for sockets. This provides an interface 
	  * to add TCPServer objects and TCPClient objects, so as to be monitored for events. 
	  * Events monitored for TCPServer includes accepting of new connections and closing of server.
	  * Events monitored for TCPClient includes availability of data for reading and for closing of 
	  * connections. 
	  **/
	class EventFax :
		public Mutex
	{
		// Attributes
		private:
			map<int, TCPClient *> clientDescriptorHash;
			map<int, TCPServer *> serverDescriptorHash;
			map<int, UDPClient *> udpClientDescriptorHash;
			
			// epoll descriptor used for running event loop.
			int epollFd;
			/** Trigger used. */
			uint16_t uTrigger;
			
		// Operations
		public:
			EventFax ();
			~EventFax ();
			/** Run the event loop. */
			void run ();
			/** Add TCPClient object to the event loop. */
			void addTCPClient (TCPClient *tcp_client);
			/** Delete TCPClient object. */
			void deleteTCPClient(TCPClient *client);
			/** Add TCPServer object to the event loop. */
			void addTCPServer (TCPServer *tcp_server);
			/** Add UDPClient object to the event loop. */
			void addUDPClient (UDPClient *udp_client);
			/// Stop event loop.
			void stop();
			/** Add timed events. */
			void addTimer( void (*f)(void *), void *data, uint16_t timer);
			/** Add periodic timed events. */
			void addPeriodicTimer( void (*f)(void *), void *data, uint32_t timer);
			/** Set event trigger type. EDGE or LEVEL triggered. */
			void setTriggerLevel(uint16_t u8Trigger);
			/** Trigger type definitions. */
			const static uint16_t TriggerType_EDGE;
			const static uint16_t TriggerType_LEVEL;
		
		private:

			int createEventDescriptor ();
			TimerEvents timerEvents;

#ifdef _WIN32
			fd_set *read_fds;
			int _nfds;
#else
			void raiseException (string error, int errorNumber);
			enum {
				MAX_EPOLL_DESCRIPTORS = 64*1024
			};
#endif
			bool requestedStop;
	};
};

using namespace UBAC;

#endif /* __EVENT_FAX_H__ */
