#include "SocketIO.h"

SocketIO::SocketIO()
{
}

SocketIO::~SocketIO()
{
}

int SocketIO::readn(register int fd, register char *ptr, register int nbytes)
{
	int nleft, nread;

	nleft = nbytes;

	while(nleft > 0) {
#ifdef _WIN32
		nread = recv(fd, ptr, nleft, 0);
#else
		nread = read(fd, ptr, nleft);
#endif

		if(nread < 0) return nread;

		else if(nread == 0) break;

		nleft -= nread;
		ptr += nread;
	}

	return (nbytes - nleft);
}

int SocketIO::writen(register int fd, register const char *ptr,
					 register int nbytes)
{
	int nleft, nwritten;

	nleft = nbytes;

	while(nleft > 0) {
#ifdef _WIN32
		nwritten = send(fd, ptr, nleft, 0);
#else
		nwritten = write(fd, ptr, nleft);
#endif

		if(nwritten <= 0)
			return (nwritten);

		nleft -= nwritten;
		ptr += nwritten;
	}

	return (nbytes - nleft);
}
