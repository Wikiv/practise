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

namespace UBACIPC
{

    /// Class TLSServer
    class TLSServer :
        public virtual TCPServer
    {
        public:
            /** Creates new TLSServer at 'iPort' with 'sCertificateFile' and 'sKeyFile. */
            TLSServer(int iPort, string sCertificateFile, string sKeyFile, 
                    string sKeyPassphrase);
            ~TLSServer();
            TLSServer() {}

            /** Creates new client. */
            void createNewClient(int fd);
            /** Holds the SSL_SESSIONS and the certicate lookup information. */
            SSL_CTX *ssl_context;

            void setKeyPassphrase(string passphrase);
        private:
            SSL *ssl_socket;
            string sCertificateFile;
            string sKeyFile;
            string sKeyPassphrase;

            void init_ssl();
            void load_certificates();
    };
};

#endif /* __UBAC_TLS_SERVER_H__ */
