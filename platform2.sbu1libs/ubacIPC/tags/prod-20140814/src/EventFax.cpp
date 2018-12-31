#include "EventFax.h"

const uint16_t EventFax::TriggerType_EDGE = 1;
const uint16_t EventFax::TriggerType_LEVEL = 2;

EventFax::EventFax()
{
	requestedStop = false;
	createEventDescriptor();
	uTrigger = TriggerType_EDGE;
}

EventFax::~EventFax()
{
}

void EventFax::setTriggerLevel(uint16_t u8TriggerLevel)
{
	uTrigger = u8TriggerLevel;

	if( (uTrigger != TriggerType_EDGE) && (uTrigger != TriggerType_LEVEL) )
		uTrigger = TriggerType_EDGE;
}

void EventFax::stop()
{
	requestedStop = true;
}

void EventFax::run()
{
#ifdef _WIN32
	printf("%p\n", read_fds);

	while(1) {
		struct timeval time_val;
		time_val.tv_sec = 1;
		time_val.tv_usec = 0;
		this->lock();
		fd_set tmp_read_fds;
		memcpy(&tmp_read_fds, read_fds, sizeof(fd_set));
		//cout << "fd_count for select: " << tmp_read_fds.fd_count << endl;
		//cout << "no of fds = " << read_fds->fd_count << endl;
		int s = select(_nfds, &tmp_read_fds, NULL, NULL, &time_val);

		if( s == -1 ) {
			//printf("Errno = %d, Error = %s\n", errno, strerror(errno));
			//return;
			//continue;
		}

		if( s > 0 )
			cout << "no of events = " << s << endl;

		//if( s > 0 ) {
		for(int i = 1; i < _nfds ; i++) {
			map<int, TCPClient *>::iterator j = clientDescriptorHash.find( i );

			if( j == clientDescriptorHash.end() ) {
				map<int, TCPServer *>::iterator iServer = serverDescriptorHash.find( i );

				if( iServer != serverDescriptorHash.end() ) {
					iServer->second->acceptClientConnection();
				}

			} else if( FD_ISSET(j->second->descriptor, &tmp_read_fds) ) {
				cout << "Reading from socket: " << j->second->descriptor << endl;

				if( j->second->readData() <= 0 ) {
					FD_CLR(j->second->descriptor, read_fds);
					j->second->closeConnection();
					j->second->unbind();
					clientDescriptorHash.erase( j );
				}

			} else {
				//std::cout << __FUNCTION__ << ": removing " << j->second->descriptor << std::endl;
				//FD_CLR(j->second->descriptor, read_fds);
			}
		}

		//}
		timerEvents.check_for_events();
		this->unlock();
	}

#else
	struct epoll_event ev[ MAX_EPOLL_DESCRIPTORS ];

	while(1) {
		if( requestedStop ) {
			close(epollFd);
			return;
		}

		int s = epoll_wait(epollFd, ev, MAX_EPOLL_DESCRIPTORS - 1, 1);

		if( (s < 0) && (errno != EINTR) ) return;

//		if( s > 0 )
//			cout << "no of epoll events = " << s << endl;
		for(int i = 0; i < s; i++) {
			if(ev[i].events & EPOLLIN) {
				//cout << "Got event for " << ev[i].data.fd << endl;
				map<int, TCPClient *>::iterator j = clientDescriptorHash.find( ev[i].data.fd );

				if( j == clientDescriptorHash.end() ) {
					map<int, TCPServer *>::iterator iServer = serverDescriptorHash.find(
								ev[i].data.fd );

					if( iServer != serverDescriptorHash.end() ) {
						iServer->second->acceptClientConnection();
					}

				} else {
					if( j->second->readData() <= 0 ) {
						cout << "Removing " << ev[i].data.fd <<  " from event loop" << endl;
						epoll_ctl(epollFd, EPOLL_CTL_DEL, ev[i].data.fd, &ev[i]);
						j->second->closeConnection();
						j->second->unbind();
						clientDescriptorHash.erase( j );
					}
				}
			}

			if(ev[i].events & EPOLLOUT) {
				// cout << "EPOLLOUT Event for " << ev[i].data.fd << endl;
				// printf("someone trying to read %d\n", ev[i].data.fd);
				map<int, TCPClient *>::iterator j = clientDescriptorHash.find( ev[i].data.fd );

				if( j !=  clientDescriptorHash.end() ) {
					j->second->sendBufferedData();
				}

			}

#ifdef EPOLLRDHUP

			if( ((ev[i].events & EPOLLERR) == EPOLLERR)
					|| ((ev[i].events & EPOLLHUP) == EPOLLHUP)
					|| ((ev[i].events & EPOLLRDHUP) == EPOLLRDHUP) ) {
#else

			if( ((ev[i].events & EPOLLERR) == EPOLLERR)
					|| ((ev[i].events & EPOLLHUP) == EPOLLHUP) ) {
#endif
				cout << "EPOLLERR Event for i as " << i << " with fd as " << ev[i].data.fd <<
					 endl;
				//				cout << "EPOLLERR or EPOLLHUP occurred" << endl;
				//				epoll_ctl(epollFd, EPOLL_CTL_MOD, ev[i].data.fd, &ev[i]);
				map<int, TCPClient *>::iterator j = clientDescriptorHash.find( ev[i].data.fd );

				if( j != clientDescriptorHash.end() ) {
					epoll_ctl(epollFd, EPOLL_CTL_DEL, ev[i].data.fd, &ev[i]);
					j->second->closeConnection();
					j->second->unbind();
					clientDescriptorHash.erase( j );
				}
			}
		}

		timerEvents.check_for_events();
	}

#endif
}

int EventFax::createEventDescriptor()
{
#ifdef _WIN32
	read_fds = (fd_set *)calloc(1, sizeof(fd_set));
	printf("%p\n", read_fds);
	FD_ZERO(read_fds);
	_nfds = 1;
#else
	epollFd = epoll_create( MAX_EPOLL_DESCRIPTORS );
	cout << "epollFd = " << epollFd << endl;
	return epollFd;
#endif
	return 0;
}

void EventFax::addTCPServer(TCPServer *tcp_server)
{
	int clientFd = tcp_server->descriptor;
#ifdef _WIN32
	unsigned long int nio_val = 1;
	ioctlsocket(clientFd, FIONBIO, &nio_val);
	this->lock();
	cout << "no of fds1 = " << read_fds->fd_count << endl;
	FD_SET(clientFd, read_fds);
	_nfds = (_nfds > clientFd) ? _nfds : (clientFd + 1);
	serverDescriptorHash.insert( make_pair(clientFd, tcp_server) );
	cout << "nfds=  " << _nfds << endl;
	cout << "no of fds2 = " << read_fds->fd_count << endl;
	this->unlock();
#else
	int val = fcntl (clientFd, F_GETFL, 0);
	fcntl (clientFd,F_SETFL, val | O_NONBLOCK);

	if( uTrigger == TriggerType_EDGE ) {
		tcp_server->epollEventData.events = EPOLLIN | EPOLLET | EPOLLERR | EPOLLOUT;

	} else {
		tcp_server->epollEventData.events = EPOLLIN | EPOLLERR | EPOLLOUT;
	}

	tcp_server->epollEventData.data.fd = clientFd;
	serverDescriptorHash.insert( make_pair(clientFd, tcp_server) );
//	cout << "epollFd = " << epollFd << ", fd = " << clientFd << endl;
//	int ret;
	epoll_ctl (epollFd, EPOLL_CTL_ADD, clientFd,
			   (struct epoll_event *)&tcp_server->epollEventData);
//	cout << "ret for adding client = " << ret << endl;
//	cout << "errno = " << strerror( errno ) << endl;
#endif
}

void EventFax::deleteTCPClient(TCPClient *client)
{
	this->lock();
	int clientFd = client->descriptor;
	map<int, TCPClient *>::iterator iClient = clientDescriptorHash.find(
				clientFd );

	if( iClient != clientDescriptorHash.end() ) {
#ifndef WIN32
		int ret = epoll_ctl (epollFd, EPOLL_CTL_DEL, clientFd,
							 (struct epoll_event *)&iClient->second->epollEventData);
		printf("ret for deleting client = %d\n", ret);
		clientDescriptorHash.erase(iClient);
#else
		FD_CLR( clientFd, read_fds );
		clientDescriptorHash.erase(iClient);
#endif
	}

	this->unlock();
}

void EventFax::addTCPClient(TCPClient *tcp_client)
{
	int clientFd = tcp_client->descriptor;
#ifdef _WIN32
	unsigned long int nio_val = 1;
	ioctlsocket(clientFd, FIONBIO, &nio_val);
	this->lock();
	FD_SET(clientFd, read_fds);
	_nfds = (_nfds > clientFd) ? _nfds : (clientFd + 1);
	cout << __LINE__ << " _nfds = " << _nfds << endl;
	cout << "no of fds = " << read_fds->fd_count << endl;
	clientDescriptorHash.insert( make_pair(clientFd, tcp_client) );
	this->unlock();
#else
	int val = fcntl (clientFd, F_GETFL, 0);
	fcntl (clientFd,F_SETFL, val | O_NONBLOCK);

	if( uTrigger == TriggerType_EDGE ) {
		tcp_client->epollEventData.events = EPOLLIN | EPOLLET | EPOLLERR | EPOLLOUT;

	} else {
		tcp_client->epollEventData.events = EPOLLIN | EPOLLERR | EPOLLOUT;
	}

#ifdef EPOLLRDHUP
	tcp_client->epollEventData.events = tcp_client->epollEventData.events |
										EPOLLRDHUP;
#endif
	tcp_client->epollEventData.data.fd = clientFd;
	clientDescriptorHash.insert( make_pair(clientFd, tcp_client) );
//	cout << "epollFd = " << epollFd << ", fd = " << clientFd << endl;
	int ret = epoll_ctl (epollFd, EPOLL_CTL_ADD, clientFd,
						 (struct epoll_event *)&tcp_client->epollEventData);

	if( ret != 0 ) {
//		cout << "ret for adding client = " << ret << endl;
//		cout << "errno = " << strerror( errno ) << endl;
	}

#endif
}

void EventFax::addTimer( void (*f)(void *), void *data, uint16_t timer)
{
	timerEvents.addEvent(f, data, timer);
}

void EventFax::addPeriodicTimer( void (*f)(void *), void *data, uint32_t timer)
{
	timerEvents.addPeriodicEvent(f, data, timer);
}

