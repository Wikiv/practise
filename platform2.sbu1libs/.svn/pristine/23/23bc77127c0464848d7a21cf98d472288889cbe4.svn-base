#ifndef __CMX_LISTNER_H__
#define __CMX_LISTNER_H__

#include <ubacipc/HTTPServer.h>
#include <ubacipc/Mutex.h>
#include <jsonparser/JsonParser.h>

#include "ServiceMonitor.h"

namespace UBACMONITOR {

    class CMXListner:
        public HTTPListner {
            public:
                CMXListner(ServiceMonitor *sMonitor, SLog *logger);
                virtual ~CMXListner();
                void onGetRequest(HTTPServerRequest *request, HTTPConnection *client);
                void onPostRequest(HTTPServerRequest *request, HTTPConnection *client);
            private:
                SLog *sLogID;
                string convertStructToJson(struct serviceInfo &statusInfo, string info);
                ServiceMonitor *sMonitor;
        };

};

#endif /*__CMX_LISTNER_H__*/
