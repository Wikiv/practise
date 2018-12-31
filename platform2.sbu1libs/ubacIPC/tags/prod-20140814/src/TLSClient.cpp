#include "TLSClient.h"

TLSClient::TLSClient(int fd, SSL_CTX *ssl_server_context) : TCPClient(fd)
{
	this->ssl_socket = SSL_new(ssl_server_context);
	SSL_set_fd(this->ssl_socket, fd);

    setModes();

	bSslAcceptStatus = false;

	/* Adding Socket timeout - Start */
	struct timeval timeout;
	timeout.tv_sec = 2;
	timeout.tv_usec = 0;

	if( setsockopt (fd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
					sizeof(timeout)) < 0 ) {
		printf("setsockopt for rcv failed\n");
		close(fd);

	} else {
		int iAccept = SSL_accept(this->ssl_socket);

		if( iAccept == 1) {
			bSslAcceptStatus = true;
			printf("Creating successful TLS Connection\n");

		} else {
			printf("SSL Accept error: %d ", iAccept);
			getErrorDetails(SSL_get_error(this->ssl_socket, iAccept));
		}
	}

	/* Adding Socket timeout - End */

	show_certificates();
}

TLSClient::TLSClient (string ip, int port, string sCertificateFile, string sKeyFile) : 
    TCPClient(ip, port)
{
	bSslAcceptStatus = false;

    this->sCertificateFile = sCertificateFile;
    this->sKeyFile = sKeyFile; 

    init_ssl();
    load_certificates();

    this->ssl_socket = SSL_new( this->ssl_context);
    SSL_set_fd(this->ssl_socket, descriptor);

    setModes();

    int error = SSL_connect(this->ssl_socket);

    if ( error == 1 )
        bSslAcceptStatus = true;

}

void TLSClient::init_ssl()
{
	SSL_library_init();
	const SSL_METHOD *method;
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();

	method = SSLv3_client_method();
	ssl_context = SSL_CTX_new(method);

	if( ssl_context == NULL ) {
		ERR_print_errors_fp(stderr);
		abort();
	}
}

void TLSClient::setModes()
{
    SSL_set_mode(this->ssl_socket, SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER);
    SSL_set_mode(this->ssl_socket, SSL_MODE_AUTO_RETRY);
//    SSL_set_mode(this->ssl_socket, SSL_MODE_ENABLE_PARTIAL_WRITE);

}

void TLSClient::load_certificates()
{
	//New lines
	if (SSL_CTX_load_verify_locations(ssl_context, sCertificateFile.c_str(),
									  sKeyFile.c_str()) != 1)
		ERR_print_errors_fp(stderr);

	if (SSL_CTX_set_default_verify_paths(ssl_context) != 1)
		ERR_print_errors_fp(stderr);

	//End new lines

	/* set the local certificate from CertFile */
	if (SSL_CTX_use_certificate_file(ssl_context, sCertificateFile.c_str(),
									 SSL_FILETYPE_PEM) <= 0) {
		ERR_print_errors_fp(stderr);
		abort();
	}

	/* set the private key from KeyFile (may be the same as CertFile) */
	if (SSL_CTX_use_PrivateKey_file(ssl_context, sKeyFile.c_str(),
									SSL_FILETYPE_PEM) <= 0) {
		ERR_print_errors_fp(stderr);
		abort();
	}

	/* verify private key */
	if (!SSL_CTX_check_private_key(ssl_context)) {
		fprintf(stderr, "Private key does not match the public certificate\n");
		abort();
	}

	//New lines - Force the client-side have a certificate
	//SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT, NULL);
	//SSL_CTX_set_verify_depth(ctx, 4);
	//End new lines
}

bool TLSClient::isSslAcceptSuccessful()
{
	return bSslAcceptStatus;
}

void TLSClient::getErrorDetails(int iError)
{
    switch(iError) {
        case SSL_ERROR_NONE:
            printf("The TLS/SSL I/O operation completed\n");
            break;

        case SSL_ERROR_ZERO_RETURN:
            printf("The TLS/SSL connection has been closed\n");
            break;

        case SSL_ERROR_WANT_READ:
            printf("SSL_ERROR_WANT_READ\n");
            break;

        case SSL_ERROR_WANT_WRITE:
            printf("SSL_ERROR_WANT_WRITE:\n");
            break;

        case SSL_ERROR_WANT_CONNECT:
            printf("SSL Connection error. Call TLS/SSL I/O function again\n");
            break;

        case SSL_ERROR_WANT_ACCEPT:
            printf("SSL Accept error. Call TLS/SSL I/O function again\n");
            break;

        case SSL_ERROR_WANT_X509_LOOKUP:
            printf("The operation did not complete because an application callback set by SSL_CTX_set_client_cert_cb() has asked to be called again\n");
            break;

        case SSL_ERROR_SYSCALL:
            printf("Some I/O error occurred\n");
            break;

        case SSL_ERROR_SSL:
            printf("A failure in the SSL library occurred, usually a protocol error\n");
            break;

        default:
            printf("Some random error\n");
    }
    unsigned long lError = ERR_get_error();

    char buf[1024] = { '\0' };

    ERR_error_string(lError, & buf[0]);

    cout << "TLS_ERR_ERROR_string -> " << buf << endl;
}

void TLSClient::show_certificates()
{
    X509 *cert;
    char *line;

    cert = SSL_get_peer_certificate(
            ssl_socket); /* Get certificates (if available) */

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

//    for(int i = 0; i < 10; i++) {
    for (;;) {
        int bytes = SSL_read(ssl_socket, buffer, sizeof(buffer));

        if( bytes > 0 ) {
            nRead += bytes;
            receive_data( buffer, bytes );
            memset(&buffer, '\0', sizeof(buffer));

        }  else {
//            if( nRead == 0 )
                break;
        }
    }

    return nRead;
}

int TLSClient::sendData(string sResponse)
{
    int nWritten = SSL_write(ssl_socket, sResponse.c_str(), sResponse.length());
    if( nWritten <= 0 ) {
        getErrorDetails(SSL_get_error(ssl_socket, nWritten));
    }

    return nWritten;
}

int TLSClient::asyncWriten(register int fd, register const char *ptr, register int nBytes)
{
    int nWritten = SSL_write(ssl_socket, ptr, nBytes);
    if( nWritten <= 0 ) {
        getErrorDetails(SSL_get_error(ssl_socket, nWritten));
        return 0;
    }

    return nWritten;
}


void TLSClient::sendBufferedData()
{
    if ( ! isConnected() )
        return;

    while ( 1 ) {

        if ( 0 == writeBuffer->dataAvail() ) 
            return;

        char readBuf[WRITE_BUF_SIZE] = { '\0' };

        size_t nRead = writeBuffer->read( & readBuf[0] );

        if (this->nLeftBytesToWrite > 0)
            nRead = this->nLeftBytesToWrite;


        int nWritten = asyncWriten(this->descriptor, & readBuf[0], nRead);
        cout << "SendBufferedData of " << nRead
            << " bytes of FD : " << this->descriptor
            << " nWritten : " << nWritten << endl;

        writeBuffer->readCommit(nWritten);
        
        this->nLeftBytesToWrite = nRead - nWritten;    

        if ( this->nLeftBytesToWrite > 0)
            return;
        
    }

}
