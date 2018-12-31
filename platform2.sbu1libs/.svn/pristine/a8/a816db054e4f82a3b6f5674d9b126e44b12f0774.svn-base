#ifndef __CMX_SERVER_H__
#define __CMX_SERVER_H__

#include <ubacipc/HTTPServer.h>
#include <ubacipc/EventFax.h>

namespace UBACMONITOR {

    class CMXServer:
        public HTTPServer {

            public:
                CMXServer(int port, EventFax *fax, HTTPListner *httpListner);
                ~CMXServer();
        };

};
#endif /*__CMX_SERVER_H__*/
