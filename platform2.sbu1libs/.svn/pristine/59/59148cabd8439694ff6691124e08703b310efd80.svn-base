#include "MSFBroadcaster.h"

MSFBroadcaster::MSFBroadcaster( int port ) : TCPServer( port )
{
	signal(SIGPIPE, SIG_IGN);

	if( descriptor < 0 ) {
		exit(0);
	}

}

MSFBroadcaster::~MSFBroadcaster()
{
}

void MSFBroadcaster::sendData( void *ptr, size_t len )
{
	mMutex.lock();
	int bytes;
	vector<int>::iterator iList = clientFd.begin();

	while(iList != clientFd.end()) {
		if( (bytes = this->writen( *iList, (char *)ptr, len)) == -1 ) {
			cout << "Sent " << bytes << " bytes from broadcaster" << endl;
			close( *iList );
			clientFd.erase( iList );

		} else {
			iList++;
		}
	}

	mMutex.unlock();
}

void MSFBroadcaster::sendData( string data )
{
	sendData( (void *)data.c_str(), data.length() );
}


void MSFBroadcaster::createNewClient( int fd )
{
	cout << "Creating new client: fd = " << fd << endl;
	mMutex.lock();
	clientFd.push_back( fd );
	mMutex.unlock();
}
