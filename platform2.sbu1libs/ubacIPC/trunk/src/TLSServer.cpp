#include "TLSServer.h"

using namespace UBACIPC;

int pem_passwd_callback(char *buf, int size, int rwflag, void *password)
{
    strncpy(buf, (char *)(password), size);
    buf[size - 1] = '\0';
    return(strlen(buf));
}

TLSServer::TLSServer(int iPort, string sCertificateFile,
					 string sKeyFile, string sKeyPassphrase) : TCPServer(iPort)
{
	this->sCertificateFile = sCertificateFile;
	this->sKeyFile = sKeyFile;
    this->sKeyPassphrase = sKeyPassphrase;

	init_ssl();
	load_certificates();
}

TLSServer::~TLSServer()
{
}

void TLSServer::init_ssl()
{
	SSL_library_init();
	const SSL_METHOD *method;
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();

	/* Ref: https://wiki.openssl.org/index.php/SSL/TLS_Client */
	method = SSLv23_server_method();
	ssl_context = SSL_CTX_new(method);

	if( ssl_context == NULL ) {
		ERR_print_errors_fp(stderr);
		abort();
	}
}

void TLSServer::load_certificates()
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

    if ( sKeyPassphrase.length() > 0 )
    {
        SSL_CTX_set_default_passwd_cb(ssl_context, pem_passwd_callback);
        SSL_CTX_set_default_passwd_cb_userdata(ssl_context, 
                                            (void *) sKeyPassphrase.c_str());
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


void TLSServer::createNewClient(int fd)
{
}
