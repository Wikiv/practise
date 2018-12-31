#include "TCPServer.h"

TCPServer::TCPServer(int port, int listen_q) : SocketDescriptor(0)
{
	int status = startServer( port, listen_q );

	if ( status < 0 ) {
		fprintf(stderr, "server connection is not established\n");
		exit(1);
	}
}

TCPServer::~TCPServer()
{
}

int TCPServer::acceptClientConnection()
{
	int nClients = 0;

	while(1) {
		struct sockaddr_in client_address;
		unsigned int sockaddr_in_len = (sizeof(struct sockaddr_in));
#ifdef _WIN32
		int clientId = accept(descriptor, (struct sockaddr *) &client_address,
							  (int *)&sockaddr_in_len);
#else
#if ((__GLIBC__ == 2 && __GLIBC_MINOR__ >= 10) \
    || (__GLIBC__ >= 3 && __GLIBC_MINOR__ >= 0)) \
    && defined SOCK_CLOEXEC
		int clientId = accept4(descriptor, (struct sockaddr *) &client_address,
							   &sockaddr_in_len, SOCK_CLOEXEC);
#else
		int clientId = accept(descriptor, (struct sockaddr *) &client_address,
							  &sockaddr_in_len);
#endif
#endif

		if( clientId > 0 )
			createNewClient( clientId );

		else
			break;

		nClients++;
	}

	return nClients;
}

int TCPServer::startServer(int port, int listen_q)
{
	struct sockaddr_in serv_address;
	int check_ret;
#ifdef _WIN32
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);

	if( err != 0 ) {
		cout << "Error initializing sockets library in Windows" << endl;
		descriptor = -1;
		return -1;
	}

#endif
#if ((__GLIBC__ == 2 && __GLIBC_MINOR__ >= 10) \
    || (__GLIBC__ >= 3 && __GLIBC_MINOR__ >= 0)) \
    && defined SOCK_CLOEXEC
	descriptor = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP);
#else
	descriptor = socket(AF_INET, SOCK_STREAM , IPPROTO_TCP);
#endif

	if(descriptor < 0) {
#ifdef _WIN32
		cout << "unable to create socket: " << WSAGetLastError() << endl;
#else
		cout << "unable to create socket: " << strerror(errno) << endl;
#endif
		descriptor = -1;
		return -1;
	}

#ifdef _WIN32
	u_long p = 1;
	ioctlsocket(descriptor, FIONBIO, &p);
#else
	int val = fcntl (descriptor, F_GETFL, 0);
	fcntl (descriptor, F_SETFL, val | O_NONBLOCK);
	unsigned int opt = 1;

	if (setsockopt(descriptor, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))==-1) {
		close(descriptor);
		descriptor = -1;
	}

#endif
	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(port);
	serv_address.sin_addr.s_addr = INADDR_ANY;
	memset(&serv_address.sin_zero, '\0', 8);

	check_ret = bind(descriptor, (struct sockaddr *) &serv_address,
					 sizeof(struct sockaddr));

	if( check_ret < 0 ) {
		cout << "unable to bind socket" << endl;
		descriptor = -1;
		return -1;
	}

	check_ret = listen(descriptor, listen_q);

	if(check_ret < 0) {
#ifdef _WIN32
		_close(descriptor);
#else
		close(descriptor);
#endif
		descriptor = -1;
		return -1;
	}

	return 0;
}
