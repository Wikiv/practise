#ifndef __UBAC_TLS_CLIENT_H__
#define __UBAC_TLS_CLIENT_H__

#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <resolv.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <iostream>

#include "TCPClient.h"

class TLSClient :
	public virtual TCPClient
{
	public:
		TLSClient(int fd, SSL_CTX *ssl_server_context);
        TLSClient() {}
		~TLSClient();

		int sendData(string);
		virtual void receive_data(void *data, size_t len) {}		

		void show_certificates();

	private:
		SSL *ssl_socket;
		int readData();
};

#endif /* __UBAC_TLS_CLIENT_H__ */
