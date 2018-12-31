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
#include <vector>

#include "TCPClient.h"

class TLSClient :
	public virtual TCPClient
{
	public:
		TLSClient (string ip, int port, string sCertificateFile, string sKeyFile);
        TLSClient(int fd, SSL_CTX *ssl_server_context);
		TLSClient() {}
		~TLSClient() {};

		int sendData(string);
		
		void sendBufferedData();

		int asyncWriten(register int fd, register const char *ptr, register int nBytes);

		virtual void receive_data(void *data, size_t len) {}

		void show_certificates();
		bool isSslAcceptSuccessful();

	private:
		SSL *ssl_socket;
		SSL_CTX *ssl_context;
		string sCertificateFile;
		string sKeyFile;
		bool bSslAcceptStatus;
		int readData();
		void getErrorDetails(int iError);

		void init_ssl();
		void load_certificates();

        void setModes();
};

#endif /* __UBAC_TLS_CLIENT_H__ */
