//g++ -g test_monitor.cpp  -l:libubacmysql.so.1.3.3 -l:libubacipc.so.1.3.7 -l:libubacjsonparser.so.1.2.6 -l:libubacmonitor.so.1.0.0  -l:libubaclogger.so.1.3.8 -o monitor


#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <vector>
#include <string.h>

#include <ubacmysql/MySql.h>
#include <ubacipc/EventFax.h>
#include <ubacmonitor/CMXMonitor.h>
#include <ubacipc/Thread.h>
#include <ubaclogger/SLog.h>

using namespace std;
using namespace UBACMONITOR;

class DBConnection:
    public Thread {

        public:
            DBConnection(CMXMonitor *cmxMonitor) {
                this->cmxMonitor = cmxMonitor;
            }

            ~DBConnection() {
            }

            void run() {
                cout <<" Run method called\n"<<endl;

                map<string,struct serviceInfo>::iterator it;
                while(true) {
                    if(checkDBConnection()) {
                        cout<<"Connection available.\n";
                        cmxMonitor->updateSuccess("DB");
                    } else {
                        cout<<"Unable to Connect.\n";
                        cmxMonitor->updateFailure("DB");
                    }

                    sleep(2);
                }
            }

        private:
            CMXMonitor *cmxMonitor;
            bool checkDBConnection()
            {

                UBACSql testsql("localhost", "root", "inxs", "DEMO");
                return testsql.isValidConnection()?true:false;

            }
    };

int main(int argc,char *argv[]) {

    //SLog object creation. In project, it should be created in respective components

    struct s_logger_config config;
    config.name_space = "monitor_log";
    config.mode = "1";
    config.level = "4";
    config.appender = "one";
    config.file_name = "test_monitor.log";
    config.dir="/home/cisadmin/Libraries/sbu1libs/ubacMonitor/trunk/test";

    SLog sLog(config);

    EventFax *fax = new EventFax();

    vector<string> servList;
    servList.push_back("DB");

    CMXMonitor cmxMonitor(30000, fax, servList, &sLog);
//    CMXMonitor cmxMonitor(30000, fax, servList, NULL);

    DBConnection dbCon(&cmxMonitor);
    dbCon.start( &dbCon );

    fax->run();

    delete fax;
    return 0;
}
