#ifndef __CMX_MONITOR_H__
#define __CMX_MONITOR_H__

#include "ServiceMonitor.h"
#include "CMXListner.h"
#include "CMXServer.h"

namespace UBACMONITOR {

    class CMXMonitor {
        public:
            CMXMonitor(int port, EventFax *fax, vector<string> &servList, SLog *sLog);
            ~CMXMonitor();
            bool updateFailure(string sName);
            bool updateSuccess(string sName);
        private:
            ServiceMonitor *sMonitor;
            CMXListner *cmxListner;
            CMXServer *cmxServer;

    };

};

#endif /*__CMX_MONITOR_H__*/
