#include "ClientDescriptor.h"

ClientDescriptor::ClientDescriptor(int fd) : FileDescriptor(fd)
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

	 const size_t buffer_size = PACKET_SIZE - 1;

	 int nRead = 0;
	 int nLastRead = 0;
	 
	 this->setDataAvailForRead(false);

	 /** Keep reading, but loop 10 times. Give other descriptors a change. */
	 for(int i = 0 ; i < 10; i++) {
#ifdef _WIN32
		  nLastRead = recv(descriptor, buffer, sizeof(buffer), 0);
#else
		  nLastRead = read( descriptor, buffer, buffer_size);
#endif

		  if( nLastRead  > 0 ) {
			   nRead += nLastRead;
			   receive_data( &buffer[0], nLastRead );

		  } else {
			   if( nRead == 0 )
				    nRead = -1;

			   break;
		  }
	 }

	 if (nLastRead > 0)
	 {
		  // Still bytes are left
		  this->setDataAvailForRead(true);

	 }

	 return nRead;
}
