
#include <iostream>
#include <map>

#include <ubaclogger/SLog.h>
#include <ubacipc/EventFax.h>

#include "MSFRequest.h"
#include "MSFResponse.h"
#include "SBU2HTTPServer.h"
#include "SBU2WebService.h"

using namespace SBU2;

using namespace UBACIPC;

class MyWebService: public SBU2WebService
{
	public:
		MyWebService(SLog *sLogID): SBU2WebService(sLogID) {}
		~MyWebService();

		void onPostProcessRequest( MSFRequest * msfrequest,
								   MSFResponse * msfResponse,
								   HTTPConnection *connection )
		{
			cout << "In MyWebSerivcce on post request: sRequest = " << endl;
			cout << "Request received ... " << msfrequest->toString() << endl;

            sleep(5);

			this->sendResponse(msfResponse, connection);
		}

		string getSvcName()
		{
			    return "Login";
		}
		string getSvcGroup()
		{
			return "Customer";
		}

		string getSvcVersion()
		{
			return "1.0.0";
		}

};


int main()
{
    struct s_logger_config config;
    config.mode = "1";
    config.level = "4";
    config.appender="test";
    config.file_name="slog-testing";
    config.dir="./";
    config.pwd="/tmp";

    SLog sLog(config);


    MyWebService *ap = new MyWebService(& sLog);

    map<string, SBU2WebService *> * jWebService = new map<string, SBU2WebService *>;

    jWebService->insert(std::make_pair("/init", ap));

    SBU2LoadBalancer * j = new SBU2LoadBalancer(1, jWebService);

    SBU2HTTPServer * h =  new SBU2HTTPServer(30002, j);
    
    // For running in foreground
    //h->run();

    // For running in background
    h->start(NULL);
    while (1);

}
// g++ -I include/ test/test_webservice.cpp src/* -l:libubacjsonparser.so.1.2.2 -l:libubacsslinterface.so.1.2.2 -l:libubachttpclient.so.1.2.1 -l:libubacipc.so.1.2.5 -l:libubacutils.so.1.2.2 -l:libubaclogger.so.1.2.2
