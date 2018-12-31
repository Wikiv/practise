#include "ClientDescriptor.h"

ClientDescriptor::ClientDescriptor(int fd) : SocketDescriptor(fd)
{
}

ClientDescriptor::~ClientDescriptor()
{
#ifdef _WIN32
	if( descriptor > 2 ) 
		_close( descriptor );
#else
	if( descriptor > 2 ) 
		close( descriptor );
#endif
}

int ClientDescriptor::call()
{
	return readData();
}

int ClientDescriptor::readData()
{
	char buffer[PACKET_SIZE] = {'\0'};
	int nRead = 0;
	/** Keep reading, but loop 10 times. Give other descriptors a change. */
	for(int i = 0 ;i < 10; i++) {
#ifdef _WIN32
		int reading = recv(descriptor, buffer, sizeof(buffer), 0);
#else
		int reading = read( descriptor, buffer, sizeof(buffer) - 1 );
#endif
		if( reading > 0 ) {
			nRead += reading;
			receive_data( &buffer[0], reading );
			memset(&buffer, '\0', sizeof(buffer));
		} else {
			if( nRead == 0 )
				nRead = -1;
			break;
		}
	}
	return nRead;
}
