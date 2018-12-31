#include "ClientDescriptor.h"

ClientDescriptor::ClientDescriptor(int fd) : FileDescriptor(fd)
{
	uReadBufferSize = (16 * 1024) + 1;

	cReadBuffer = (char *) malloc(uReadBufferSize);
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

	if (cReadBuffer != NULL)
		delete cReadBuffer;
}

int ClientDescriptor::call()
{
	 return readData();
}

void ClientDescriptor::setReadBufferSize(size_t s)
{
	if (cReadBuffer != NULL)
		delete cReadBuffer;

	uReadBufferSize = s + 1;
	cReadBuffer = (char *) malloc(uReadBufferSize);
}

int ClientDescriptor::readData()
{

	 const size_t buffer_size = uReadBufferSize - 1;

	 int nRead = 0;
	 int nLastRead = 0;
	 
	 this->setDataAvailForRead(false);

	 /** Keep reading, but loop 10 times. Give other descriptors a change. */
	 for(int i = 0 ; i < 10; i++) {
#ifdef _WIN32
		  nLastRead = recv(descriptor, cReadBuffer, sizeof(cReadBuffer), 0);
#else
		  nLastRead = read( descriptor, cReadBuffer, buffer_size);
#endif

		  if( nLastRead  > 0 ) {
			   nRead += nLastRead;
			   receive_data( cReadBuffer, nLastRead );

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
