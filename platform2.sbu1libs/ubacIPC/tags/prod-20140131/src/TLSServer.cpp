#include "TLSServer.h"

TLSServer::TLSServer(int iPort, string sCertificateFile, string sKeyFile) : TCPServer(iPort)
{
	this->sCertificateFile = sCertificateFile;
	this->sKeyFile = sKeyFile;

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

	method = SSLv3_server_method();
	ssl_context = SSL_CTX_new(method);
	if( ssl_context == NULL ) {
		ERR_print_errors_fp(stderr);
		abort();
	}
}

void TLSServer::load_certificates()
{
	//New lines 
	if (SSL_CTX_load_verify_locations(ssl_context, sCertificateFile.c_str(), sKeyFile.c_str()) != 1)
		ERR_print_errors_fp(stderr);
	
	if (SSL_CTX_set_default_verify_paths(ssl_context) != 1)
		ERR_print_errors_fp(stderr);
	//End new lines

	/* set the local certificate from CertFile */
	if (SSL_CTX_use_certificate_file(ssl_context, sCertificateFile.c_str(), SSL_FILETYPE_PEM) <= 0) {
		ERR_print_errors_fp(stderr);
		abort();
	}
	/* set the private key from KeyFile (may be the same as CertFile) */
	if (SSL_CTX_use_PrivateKey_file(ssl_context, sKeyFile.c_str(), SSL_FILETYPE_PEM) <= 0)
	{
		ERR_print_errors_fp(stderr);
		abort();
	}
	/* verify private key */
	if (!SSL_CTX_check_private_key(ssl_context))
	{
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

