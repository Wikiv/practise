#ifndef __UBAC_TLS_SERVER_H__
#define __UBAC_TLS_SERVER_H__

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

#include "TCPServer.h"

class TLSServer :
	public virtual TCPServer
{
	public:
		TLSServer(int iPort, string sCertificateFile, string sKeyFile);
		~TLSServer();
		TLSServer() {}

		void createNewClient(int fd);

		SSL_CTX *ssl_context;
	private:
		SSL *ssl_socket;
		string sCertificateFile;
		string sKeyFile;

		void init_ssl();
		void load_certificates();
};

#endif /* __UBAC_TLS_SERVER_H__ */
