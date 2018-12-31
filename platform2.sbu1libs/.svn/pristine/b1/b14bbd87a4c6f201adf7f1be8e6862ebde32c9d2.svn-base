#ifndef __SERVICE_MONITOR_H__
#define __SERVICE_MONITOR_H__

#include <map>
#include <vector>
#include <strings.h>
#include <string>

#include <ubacipc/Mutex.h>
#include <ubaclogger/SLog.h>

using namespace std;

namespace UBACMONITOR {

    struct serviceInfo {
        int s_cnt;
        int f_cnt;
    };

    class ServiceMonitor {
        public:
            ServiceMonitor(vector<string> &serviceList, SLog *logger);
            ~ServiceMonitor();
            bool updateFailure(string sName);
            bool updateSuccess(string sName);
            bool getStatus(string sName, struct serviceInfo &servInfo);
        private:
            Mutex mMutex;
            SLog *sLogID;
            map<string,struct serviceInfo > status_map;
            string convertIntegerToString(int iNumber);
            void logStatus(string sName, struct serviceInfo &servInfo); 
            void init_map(vector<string> &serviceList);
    };

};
#endif /*__SERVICE_MONITOR_H__*/

