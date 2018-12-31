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


namespace UBACIPC
{

/// Class TLSClient to create TLS Client applications
class TLSClient :
	public virtual TCPClient
{
	public:
		/** Creates new TLSClient connecting to 'ip' and 'port' with the 'sCerticateFile'. */
		TLSClient (string ip, int port);
		/** Creates new TLSClient and stores the new SSL structure in the 'ssl_server_context'. */		
        TLSClient(int fd, SSL_CTX *ssl_server_context);
		TLSClient();
		virtual ~TLSClient();
		
		/** Calls ssl_write which sends 'string' to client and returns the number of bytes of data sent. */
		int sendData(string);
		/** Send buffered data if available */
		//void sendBufferedData();
		/** Calls ssl_write and returns the number of bytes of data sent. */
		int asyncWriten(register int fd, register const char *ptr, register int nBytes);
		/** Implement this method, to handle the data read from the socket. */	
		virtual void receive_data(void *data, size_t len) {}
		
		/** Prints the peer certificate that was received when the SSL session was started. */
		void show_certificates();
		/** Returns the status of ssl_accept request. */
		bool isSslAcceptSuccessful();

        virtual int handleIN();

        virtual bool asyncSendData(const char * ptr, int nbytes);


	private:
		SSL *ssl_socket;
		SSL_CTX *ssl_context;
		string sCertificateFile;
		bool bSslAcceptStatus;
		int readData();
		static void getErrorDetails(int iError);

		void init_ssl();

        void setModes();

        void init();

        void connect();
};
};

#endif /* __UBAC_TLS_CLIENT_H__ */
