#include "TCPClient.h"

TCPClient::TCPClient(string ip, int port) : ClientDescriptor( 0 )
{
	m_IP.append( ip );
	m_Port = port;

	descriptor = makeConnection(ip, port);
	clientFd = descriptor;

	init();
}

TCPClient::TCPClient(int fd) : ClientDescriptor(fd)
{
	clientFd = fd;
	init();
}

TCPClient::~TCPClient()
{
	closeConnection();

	if ( writeBuffer != NULL)
		delete writeBuffer;
}

void TCPClient::init()
{
	writeBuffer = new CircularBuffer(WRITE_BUF_SIZE);
	nLeftBytesToWrite = 0;
}

bool TCPClient::reconnect()
{
	descriptor = makeConnection( m_IP, m_Port );
	writeBuffer->reset();

	bool flag = isConnected();

	if( flag )
		onConnect();

	return flag;
}

int TCPClient::sendData(string data)
{
	int nWritten = this->writen(this->descriptor, data.c_str(), data.length());
	return nWritten;
}

int TCPClient::asyncWriten(register int fd, register const char *ptr,
						   register int nbytes)
{
	int nleft, nwritten;

	const char * base = ptr;

	nleft = nbytes;

	while(nleft > 0) {
#ifdef _WIN32
		nwritten = send(fd, ptr, nleft, 0);
#else
		nwritten = write(fd, ptr, nleft);
#endif

		if(nwritten <= 0)
			return ptr - base;

		nleft -= nwritten;
		ptr += nwritten;
	}

	return nbytes;
}

bool TCPClient::asyncSendData(const char * ptr, int nbytes)
{
	if ( ! isConnected() || isMarkedForRemovalFromEventFax() ) 
        return false;

	// Checking anything is available in buffer.
	// Then add to buffer.
	if ( writeBuffer->dataAvail() > 0) {

		if ( writeBuffer->write(ptr, nbytes) == 0 ) {

			cout << "Marking from removal " << this->descriptor
				 << " because there is no space in internal buffer" << endl;

            markForRemovalFromEventFax();

			return false;

		} else {

            //addOUTEvent();
        }

		return true;
	}

	int nWritten = asyncWriten(this->descriptor, ptr, nbytes);

	this->nLeftBytesToWrite = nbytes - nWritten;

	if (this->nLeftBytesToWrite > 0 && errno == EAGAIN ) {

		// buffering data which is not sent;
		writeBuffer->write(ptr + nWritten, this->nLeftBytesToWrite);

		cout << "Buffered : " << this->nLeftBytesToWrite << " bytes "
			 << "for fd : " << this->descriptor <<  endl;

        addOUTEvent();

	}

	return true;
}



void TCPClient::sendBufferedData()
{
	if ( ! isConnected() || (0 == writeBuffer->dataAvail()) )
		return;

	char * readBuf = new char[WRITE_BUF_SIZE];

	size_t nRead = writeBuffer->read( & readBuf[0] );

    int nWritten = asyncWriten(this->descriptor, & readBuf[0], nRead);

    delete [] readBuf;

    cout << "SendBufferedData of " << nRead
        << " bytes of FD : " << this->descriptor
        << " nWritten : " << nWritten << endl;

    writeBuffer->readCommit(nWritten);

    if (nWritten == nRead)
    {
        //Sent all buffered data. Removing OUT Event from Fax.
        delOUTEvent();        
    }

}

int TCPClient::readLine(string & data)
{
	return readUntilDelimiter(data, '\n');
}

int TCPClient::readUntilDelimiter(string & data, char c_delimiter)
{
	int ret = 0;
	char c;

	while(1) {
#ifdef _WIN32
		ret = recv(descriptor, &c, 1, 0);
#else
		ret = read(descriptor, &c, 1);
#endif

		if( (ret < 1) || (c == c_delimiter) )
			break;

		data.append(&c, 1);
	}

	return ret;
}

int TCPClient::readUntilDelimiter(string & data, string sDelimiter)
{
	int ret = 0;
	char c;
	size_t index_to_check = 0;

	while(1) {
#ifdef _WIN32
		ret = recv(descriptor, &c, 1, 0);
#else
		ret = read(descriptor, &c, 1);
#endif
		data.append(&c, 1);

		if(c == sDelimiter[index_to_check])
			index_to_check++;

		else if(c == sDelimiter[0])
			index_to_check = 1;

		else
			index_to_check = 0;

//		if( (ret < 1) || (strcasestr(data.c_str(), sDelimiter.c_str()) != NULL) )
		if ( (ret < 1) || (index_to_check == sDelimiter.length()) )
			break;
	}

	return ret;
}

int TCPClient::readNBytes(string & data, size_t nBytes)
{
	char *ptr = (char *) calloc (1, nBytes);
	int ret = readn( descriptor, ptr, nBytes );

	if( ret == (int)nBytes )
		data.append( ptr, nBytes );

	if( ptr )
		free(ptr);

	ptr = NULL;
	return ret;
}

bool TCPClient::isConnected()
{
	return (descriptor > 0);
}

int TCPClient::makeConnection(string ip, int port)
{
#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD( 1, 1 );
	WSAStartup( wVersionRequested, &wsaData );
#endif
	struct sockaddr_in serv_addr;
	unsigned long hostAddr;

	hostAddr = inet_addr(ip.c_str());

	if(hostAddr == INADDR_NONE) {
		hostent *hp = gethostbyname(ip.c_str());

		if(!hp) return -1;

		hostAddr = ((in_addr*)(hp->h_addr))->s_addr;
	}

	memset(&serv_addr, '\0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = hostAddr;
	serv_addr.sin_port = htons(port);

#if ((__GLIBC__ == 2 && __GLIBC_MINOR__ >= 10) \
    || (__GLIBC__ >= 3 && __GLIBC_MINOR__ >= 0)) \
    && defined SOCK_CLOEXEC
	int fd = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC , 0);
#else
	int fd = socket(AF_INET, SOCK_STREAM, 0);
#endif

	if(fd <= 0) return -1;

	if(connect(fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
#ifdef _WIN32
		closesocket( fd );
#else
		close(fd);
#endif
		return -1;
	}

	cout << "Connected to channel" << endl;
	return fd;
}

void TCPClient::closeConnection()
{
#ifdef _WIN32

	if( descriptor > 2 )
		closesocket( descriptor );

#else

	if( descriptor > 2 )
		close( descriptor );

#endif
	descriptor = -1;
}

int TCPClient::handleIN()
{
    return this->readData();
}

void TCPClient::handleERROR()
{
    this->closeConnection();
    this->unbind();
}

void TCPClient::handleOUT()
{
    sendBufferedData();
}

void TCPClient::setNonBlocking()
{
#ifdef _WIN32
	unsigned long int nio_val = 1;
	ioctlsocket(descriptor, FIONBIO, &nio_val);
#else
	int val = fcntl (descriptor, F_GETFL, 0);
	fcntl (descriptor ,F_SETFL, val | O_NONBLOCK);
#endif
}

bool TCPClient::waitForData(int lTimeToWait)
{
	fd_set tmp_read_fds;
	FD_ZERO(&tmp_read_fds);
	struct timeval time_val;
	time_val.tv_sec = lTimeToWait / 1000;
	time_val.tv_usec = (lTimeToWait - (time_val.tv_sec * 1000) ) * 1000;
	FD_SET(descriptor, &tmp_read_fds);
    
	int s = select(descriptor+1, &tmp_read_fds, NULL, NULL, &time_val);
	return (s > 0);
}
