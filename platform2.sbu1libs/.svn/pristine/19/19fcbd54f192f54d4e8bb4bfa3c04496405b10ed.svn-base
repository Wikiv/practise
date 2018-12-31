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
	int bytes;
        vector<int>::iterator iList = clientFd.begin();
        while(iList != clientFd.end())
        {
                if( (bytes = this->writen( *iList, (char *)ptr, len)) == -1 )
                {
			cout << "Sent " << bytes << " bytes from broadcaster" << endl;
                        close( *iList );
                        clientFd.erase( iList );
                } else {
                        iList++;
                }
        }
}

void MSFBroadcaster::sendData( string data )
{
	sendData( (void *)data.c_str(), data.length() );
}


void MSFBroadcaster::createNewClient( int fd )
{
	cout << "Creating new client...............\n";
        clientFd.push_back( fd );
}
