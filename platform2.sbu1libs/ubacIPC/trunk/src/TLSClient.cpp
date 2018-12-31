#include "TLSClient.h"

using namespace UBACIPC;

#define ssl_io_error(err) \
    SSL_ERROR_ZERO_RETURN == err \
    || SSL_ERROR_SYSCALL == err \
    || SSL_ERROR_SYSCALL == err

/*
 * Bugs & Known Issues
 * https://rt.openssl.org/Ticket/Display.html?id=2481&user=guest&pass=guest
 * https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS/SSL_functions/sslfnc.html#1061582
 *
 * */

TLSClient::TLSClient(int fd, SSL_CTX *ssl_server_context) : TCPClient(fd)
{
    init();

	this->ssl_socket = SSL_new(ssl_server_context);
	SSL_set_fd(this->ssl_socket, fd);

    setModes();


    connect();
}

void TLSClient::init()
{
    bSslAcceptStatus = false;
    this->ssl_socket = NULL;
    this->ssl_context = NULL;
}

TLSClient::TLSClient (string ip, int port) : 
    TCPClient(ip, port)
{
    init();

    init_ssl();

    this->ssl_socket = SSL_new( this->ssl_context);
    SSL_set_fd(this->ssl_socket, descriptor);

    setModes();

    int error = SSL_connect(this->ssl_socket);

    if ( error == 1 )
        bSslAcceptStatus = true;
    else 
    {
        int iSSLError = SSL_get_error(this->ssl_socket, error);
        getErrorDetails(iSSLError);
    }

    
}

TLSClient::TLSClient()
{
    init();
}

TLSClient::~TLSClient()
{
    if (this->ssl_socket != NULL)
    {
        SSL_free(this->ssl_socket);
    }

    if ( this->ssl_context != NULL)
    {
        SSL_CTX_free(this->ssl_context);
    }
}

void TLSClient::init_ssl()
{
	SSL_library_init();
	const SSL_METHOD *method;
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();

	/* Ref: https://wiki.openssl.org/index.php/SSL/TLS_Client */
	method = SSLv23_client_method();
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
    // SSL_set_mode(this->ssl_socket, SSL_MODE_ENABLE_PARTIAL_WRITE);

}

int TLSClient::handleIN()
{
    if ( bSslAcceptStatus )
    {
        return readData();

    } else 
    {
        /*
        // 
        int iAccept = SSL_accept(this->ssl_socket);

        if (iAccept == 1)
        {
            bSslAcceptStatus = true;

        } else {

            int iSSLError = SSL_get_error(ssl_socket, iAccept);
            getErrorDetails(iSSLError);
        }
        */
        return 0;
    }
}

void TLSClient::connect()
{
    struct timeval timeout;
	timeout.tv_sec = 2;
	timeout.tv_usec = 0;

	if( setsockopt (descriptor, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
					sizeof(timeout)) < 0 ) {
		printf("setsockopt for rcv failed\n");
		close(descriptor);

	} else {
		int iAccept = SSL_accept(this->ssl_socket);

		if( iAccept == 1) {
			bSslAcceptStatus = true;

		} else {
			printf("SSL Accept error: %d ", iAccept);
			getErrorDetails(SSL_get_error(this->ssl_socket, iAccept));
		}
	}
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

    /* Get certificates (if available) */
    cert = SSL_get_peer_certificate(ssl_socket); 

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

    for(int i = 0; i < 10; i++) 
    {
        int bytes = SSL_read(ssl_socket, buffer, sizeof(buffer));

        if ( bytes == 0 )
        {
            return 0;

        } else if ( bytes < 0 )
        {
            int iSSLError = SSL_get_error(ssl_socket, bytes);

            if ( ssl_io_error(iSSLError) )
            {
                getErrorDetails(iSSLError);
                return 0;
            }

            return 1;

        } else {
            nRead += bytes;
            receive_data( buffer, bytes );
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

int TLSClient::asyncWriten(register int _fd, register const char *ptr, register int nBytes)
{
    int nWritten = SSL_write(ssl_socket, ptr, nBytes);
    if( nWritten <= 0 ) {
        getErrorDetails(SSL_get_error(ssl_socket, nWritten));
        return 0;
    }

    return nWritten;
}

bool TLSClient::asyncSendData(const char * ptr, int nbytes)
{
	if ( ! bSslAcceptStatus 
            || ! isConnected() 
            || isMarkedForRemovalFromEventFax() ) 
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

            addOUTEvent();
        }

		return true;
	}

	int nWritten = asyncWriten(this->descriptor, ptr, nbytes);

	this->nLeftBytesToWrite = nbytes - nWritten;

	if (this->nLeftBytesToWrite > 0 ) {

		// buffering data which is not sent;
		writeBuffer->write(ptr + nWritten, this->nLeftBytesToWrite);

		cout << "Buffered : " << this->nLeftBytesToWrite << " bytes "
			 << "for fd : " << this->descriptor <<  endl;

        addOUTEvent();

	}

	return true;
}
