#include "UDPClient.h"

UDPClient::UDPClient(string ip, int port) :
		ClientDescriptor(0) {
	m_IP.append(ip);
	m_Port = port;
	descriptor = makeConnection(ip, port);
	clientFd = descriptor;
}

UDPClient::UDPClient(int fd) :
		ClientDescriptor(fd) {
	clientFd = fd;
}

UDPClient::~UDPClient() {
	closeConnection();
}

bool UDPClient::reconnect() {
	descriptor = makeConnection(m_IP, m_Port);
	bool flag = isConnected();

	if (flag)
		onConnect();

	return flag;
}

int UDPClient::sendData(string data) {
	sendto(this->descriptor, data.c_str(), data.length(), 0,
			(struct sockaddr *) &serv_addr, sizeof(serv_addr));
	return 1;
}

int UDPClient::readLine(string & data) {
	return readUntilDelimiter(data, '\n');
	/*
	 int ret = 0;
	 char c;
	 while(1) {
	 #ifdef _WIN32
	 ret = _read(descriptor, &c, 1);
	 #else
	 ret = read(descriptor, &c, 1);
	 #endif
	 if( (ret < 1) || (c == '\n') )
	 break;
	 data.append(&c, 1);
	 }
	 return ret;
	 */
}

int UDPClient::readUntilDelimiter(string & data, char c_delimiter) {
	int ret = 0;
	char c;

	while (1) {
#ifdef _WIN32
		ret = _read(descriptor, &c, 1);
#else
		ret = read(descriptor, &c, 1);
#endif

		if ((ret < 1) || (c == c_delimiter))
			break;

		data.append(&c, 1);
	}

	return ret;
}

int UDPClient::readNBytes(string & data, size_t nBytes) {
	char *ptr = (char *) calloc(1, nBytes);
	int ret = readn(descriptor, ptr, nBytes);

	if (ret == (int) nBytes)
		data.append(ptr, nBytes);

	return ret;
}

bool UDPClient::isConnected() {
	return (descriptor > 0);
}

int UDPClient::makeConnection(string ip, int port) {

	memset(&serv_addr, '\0', sizeof(serv_addr));
	//bzero((char *)&serv_addr, sizeof(serv_addr));

	hostAddr = inet_addr(ip.c_str());

	if (hostAddr == INADDR_NONE) {
		hostent *hp = gethostbyname(ip.c_str());

		if (!hp)
			return -1;

		hostAddr = ((in_addr*) (hp->h_addr))->s_addr;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = hostAddr;

	// Creating datagram socket
	int fd = socket(AF_INET, SOCK_DGRAM, 0);

	cout << "Client is created with fd .." << fd << endl;

	if (fd <= 0)
		return -1;

	return fd;
}

void UDPClient::closeConnection() {
#ifdef _WIN32

	if( descriptor > 2 )
	closesocket( descriptor );

#else

	if (descriptor > 2)
		close(descriptor);

#endif
	descriptor = -1;
}

void UDPClient::setNonBlocking() {
#ifdef _WIN32
	unsigned long int nio_val = 1;
	ioctlsocket(clientFd, FIONBIO, &nio_val);
#else
	int val = fcntl(clientFd, F_GETFL, 0);
	fcntl(descriptor, F_SETFL, val | O_NONBLOCK);
#endif
}

bool UDPClient::waitForData(int lTimeToWait) {
	fd_set tmp_read_fds;
	FD_ZERO(&tmp_read_fds);
	struct timeval time_val;
	time_val.tv_sec = lTimeToWait / 1000;
	time_val.tv_usec = (lTimeToWait - (time_val.tv_sec * 1000)) * 1000;
	FD_SET(descriptor, &tmp_read_fds);
	int s = select(descriptor + 1, &tmp_read_fds, NULL, NULL, &time_val);
	return (s > 0);
}
