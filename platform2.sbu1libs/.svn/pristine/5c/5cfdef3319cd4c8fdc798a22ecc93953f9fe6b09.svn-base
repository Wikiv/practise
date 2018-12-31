#include "EventFax.h"

using namespace UBACIPC;

const uint16_t EventFax::TriggerType_EDGE = 1;
const uint16_t EventFax::TriggerType_LEVEL = 2;

int EventFax::EPOLL_WAIT_TIMEOUT = 500;

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

void EventFax::printEvents(struct epoll_event *ev, UBACIPC::FileDescriptor *_fd)
{
    uint32_t event = ev->events;

    printf("Events:0x%x fd: %d -", event, _fd->getDescriptor());

    if ( event & EPOLLIN )
        cout << ":EPOLLIN:";

    if ( event & EPOLLOUT )
        cout << ":EPOLLOUT:";

    if ( event & EPOLLERR )
        cout << ":EPOLLERR:";

    if ( event & EPOLLHUP )
        cout << ":EPOLLHUP:";

    if ( event & EPOLLRDHUP )  
        cout << ":EPOLLRDHUP:";
    

    cout << endl;
}

void EventFax::run()
{

#ifdef _WIN32
	 WINRun();
#else
	 struct epoll_event ev[ MAX_EPOLL_DESCRIPTORS ];

	 while(1) {
		  if( requestedStop ) {
			   close(epollFd);
			   return;
		  }
		  
		  int s = epoll_wait(epollFd, ev, MAX_EPOLL_DESCRIPTORS - 1, EPOLL_WAIT_TIMEOUT);

		  if( (s < 0) && (errno != EINTR) ) return;
		  for(int i = 0; i < s; i++) {
			   FileDescriptor * fileDesc = (FileDescriptor *) ev[i].data.ptr;
			   if ( fileDesc == NULL )
				    continue;
			   
			   //printEvents( &ev[i], fileDesc);

			   if ( fileDesc->isMarkedForRemovalFromEventFax() )
			   {
				    delFileDescriptor(fileDesc);
				    fileDesc->handleERROR();
				    continue;
			   }
			   
			   if(ev[i].events & EPOLLIN) {
				    remFromVReadFileDesc( fileDesc );
				    int _r = fileDesc->handleIN();
				    
				    if ( _r <= 0 ) {
					     delFileDescriptor(fileDesc);
					     fileDesc->handleERROR();
				    } else {
					     if ( fileDesc->isDataAvailForRead() )
					     {
						      this->vReadFileDesc.push_back(fileDesc);
					     }
				    }
			   }

			   if(ev[i].events & EPOLLOUT) {
				    fileDesc->handleOUT();
			   }
#ifdef EPOLLRDHUP

			   if( ((ev[i].events & EPOLLERR) == EPOLLERR) 
					     || ((ev[i].events & EPOLLHUP) == EPOLLHUP)
					     || ((ev[i].events & EPOLLRDHUP) == EPOLLRDHUP) ) {
#else
			   if( ((ev[i].events & EPOLLERR) == EPOLLERR)
					     || ((ev[i].events & EPOLLHUP) == EPOLLHUP) ) {
#endif

				    delFileDescriptor(fileDesc);
				    fileDesc->handleERROR();
			   }
		}
		checkReadEvent();

		timerEvents.check_for_events();
	}
#endif
}

int EventFax::createEventDescriptor()
{
#ifdef _WIN32
	 read_fds = (fd_set *) calloc (1, sizeof(fd_set));
	 printf("%p\n", read_fds);
	 FD_ZERO(read_fds);
	 _nfds = 1;
#else
	 epollFd = epoll_create( MAX_EPOLL_DESCRIPTORS );
	 return epollFd;
#endif
	 return 0;
}

void EventFax::addTCPServer(TCPServer *tcp_server)
{
	 addFileDescriptor(tcp_server);
}

void EventFax::deleteTCPClient(TCPClient *client)
{
	 delFileDescriptor(client);
}

void EventFax::delFileDescriptor(UBACIPC::FileDescriptor *fileDesc)
{
	 if ( fileDesc->isRemFromEFax()) return;

	 int fd = fileDesc->getDescriptor();

	 int ret = epoll_ctl(epollFd, EPOLL_CTL_DEL, fd, & fileDesc->epollEventData);

	 if ( ret == -1)
	 {
		  fprintf(stdout, "EPOLL_CTL_DEL -- %s -- file_descriptor= %d, %p\n", 
				    strerror(errno), fd, fileDesc);
	 }

	 remFromVReadFileDesc(fileDesc);

	 fileDesc->bRemovedFromEFax = true;
}

void EventFax::addOUTEvent(FileDescriptor *fileDesc)
{

	 int fd = fileDesc->getDescriptor();

	 fileDesc->epollEventData.events |= EPOLLOUT;

	 int ret = epoll_ctl(epollFd, EPOLL_CTL_MOD, fd, & fileDesc->epollEventData);

	 if ( ret == -1 )
	 {
		  fprintf(stdout, "EPOLL_CTL_MOD -- %s -- file_descriptor= %d, %p\n", 
				    strerror(errno), fd, fileDesc);
	 } 

}

void EventFax::removeOUTEvent(UBACIPC::FileDescriptor *fileDesc)
{
	 int fd = fileDesc->getDescriptor();

	 fileDesc->epollEventData.events &= ~ EPOLLOUT;

	 int ret = epoll_ctl(epollFd, EPOLL_CTL_MOD, fd, & fileDesc->epollEventData);

	 if ( ret == -1 )
	 {
		  fprintf(stdout, "EPOLL_CTL_MOD -- %s -- file_descriptor= %d, %p\n", 
				    strerror(errno), fd, fileDesc);
	 }
}

void EventFax::addFileDescriptor(UBACIPC::FileDescriptor *fileDesc)
{
	 int fd  = fileDesc->getDescriptor();

	 int val = fcntl (fd, F_GETFL, 0);
	 fcntl (fd, F_SETFL, val | O_NONBLOCK);

	 if( uTrigger == TriggerType_EDGE ) {

		  fileDesc->epollEventData.events = EPOLLIN | EPOLLET | EPOLLERR | EPOLLHUP;

	 } else {

		  fileDesc->epollEventData.events = EPOLLIN | EPOLLERR;
	 }

#ifdef EPOLLRDHUP
	 fileDesc->epollEventData.events = fileDesc->epollEventData.events 
		  | EPOLLRDHUP;
#endif

	 fileDesc->epollEventData.data.ptr = fileDesc;

	 int ret = epoll_ctl(epollFd, EPOLL_CTL_ADD, fd, & fileDesc->epollEventData);

	 if ( ret == -1 )
	 {
		  fprintf(stdout, "EPOLL_CTL_ADD -- %s -- file_descriptor= %d, %p\n", 
				    strerror(errno), fd, fileDesc);
	 } else 
	 {
		  fileDesc->eventFax = this;
		  fileDesc->bRemovedFromEFax = false;
	 }
}

void EventFax::addTCPClient(TCPClient *tcp_client)
{
	 addFileDescriptor(tcp_client);
}

void EventFax::addTimer( void (*f)(void *), void *data, uint16_t timer)
{
	 timerEvents.addEvent(f, data, timer);
}

void EventFax::addPeriodicTimer( void (*f)(void *), void *data, uint32_t timer)
{
	 timerEvents.addPeriodicEvent(f, data, timer);
}

void EventFax::checkReadEvent()
{
	 vector<FileDescriptor *>::iterator it = vReadFileDesc.begin();

	 while ( it != vReadFileDesc.end() )
	 {
		  FileDescriptor * fd = * it;

		  fd->handleIN();

		  //Keeping the filedescripor in the vector itself.
		  if ( fd->isDataAvailForRead() )
		  {
			   it++;

		  } else {
			   it = vReadFileDesc.erase(it);
		  }

	 }
}

void EventFax::remFromVReadFileDesc(FileDescriptor * fd)
{
	 vReadFileDesc.erase(
			   std::remove(vReadFileDesc.begin(), vReadFileDesc.end(), fd), 
			   vReadFileDesc.end());

}

void EventFax::WINRun()
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

#endif
}
