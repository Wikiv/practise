#include "TLSClient.h"

TLSClient::TLSClient(int fd, SSL_CTX *ssl_server_context) : TCPClient(fd)
{
	this->ssl_socket = SSL_new(ssl_server_context);
	SSL_set_fd(this->ssl_socket, fd);
	SSL_accept(this->ssl_socket);
	show_certificates();
}

TLSClient::~TLSClient()
{
}

void TLSClient::show_certificates()
{
	X509 *cert;
	char *line;

	cert = SSL_get_peer_certificate(ssl_socket); /* Get certificates (if available) */
	if ( cert != NULL ) {
		printf("Server certificates:\n");
		line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
		printf("Subject: %s\n", line);
		free(line);
		line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
		printf("Issuer: %s\n", line);
		free(line);
		X509_free(cert);
	} else
		printf("No certificates.\n");
}

int TLSClient::readData()
{
	char buffer[16*1024 + 1] = {'\0'};
	int nRead = 0;
	for(int i = 0; i < 10; i++) {
		int bytes = SSL_read(ssl_socket, buffer, sizeof(buffer));
		if( bytes > 0 ) {
			nRead += bytes;
			receive_data( buffer, bytes );
			memset(&buffer, '\0', sizeof(buffer));
		}  else {
			if( nRead == 0 )
				break;
		}
	}
	return nRead;
}

int TLSClient::sendData(string sResponse)
{
	return SSL_write(ssl_socket, sResponse.c_str(), sResponse.length());
}
