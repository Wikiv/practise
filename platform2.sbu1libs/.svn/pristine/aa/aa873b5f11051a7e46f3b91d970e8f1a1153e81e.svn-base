
#include <iostream>
#include <map>

#include <ubaclogger/SLog.h>
#include <ubacipc/EventFax.h>

#include "MSFRequest.h"
#include "MSFResponse.h"
#include "SBU2HTTPServer.h"
#include "SBU2WebService.h"

SLog * sLogID;

using namespace SBU2;

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

	MyWebService *ap = new MyWebService(sLogID);

	map<string, WebService *> * jWebService = new map<string, WebService *>;

	jWebService->insert(std::make_pair("/init", ap));

	SBU2LoadBalancer * j = new SBU2LoadBalancer(100, jWebService);

	SBU2HTTPServer * h =  new SBU2HTTPServer("30002", j, false);

	h->run();

}
