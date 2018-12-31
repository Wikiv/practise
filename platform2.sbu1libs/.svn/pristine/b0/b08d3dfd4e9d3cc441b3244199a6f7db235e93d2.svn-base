#include <iostream>
#include <string>
#include <map>

#include "AppLoader.h"

#include "SBU2WebService.h"
#include "MasterHTTPServer.h"

using namespace std;

class Listener:
    public MasterHTTPListener
{
    public:
        Listener(map<string, SBU2WebService *> * m) : MasterHTTPListener(m) {}

        void onServiceNotFound(HTTPServerRequest * request, 
                HTTPConnection * client)
        {
            cout << __func__ << " Not found " << endl;
        }
};

class MyWebService: public SBU2WebService
{
	public:
		MyWebService(SLog *sLogID): SBU2WebService(sLogID)
		{
			cout << "HI in webservice\n";
		}
        ~MyWebService();


        void onRawRequest( HTTPServerRequest * request, 
                           HTTPConnection * connection,
                           string & rawRequest) 
        {
            cout << "Raw Request " << rawRequest << endl;
        };

        void onInvalidJSONRequest( HTTPServerRequest * request, 
                           HTTPConnection * connection,
                           string & rawRequest) 
        {
            cout << __func__ << " " << rawRequest << endl;

            sendErrorResponse(HTTPResponse::bad_request, connection);
            connection->release();
        }

        void onPostProcessRequest( MSFRequest * msfrequest,
                MSFResponse * msfResponse,
                HTTPConnection *connection )

        {
            cout << "In MyWebSerivcce on post request: Messageid  = " <<
                msfrequest->getMsgID() << ":" << getpid() << endl;

            sleep(1);

            msfResponse->addToData("service", "MyWebService");
            
            sendResponse(msfResponse, connection);

            connection->release();
        }

};

int main(int argc, char *argv[])
{
    try {

        AppLoader *app =  new AppLoader(argc, argv);

        SLog *sLogID;
        sLogID = app->sLogID;
        sLogID->debug( "Starting init application\n" );

        MyWebService *ap = new MyWebService(sLogID);
        map<string, SBU2WebService *> *jWebservice = new map<string, SBU2WebService *>;
        jWebservice->insert(std::make_pair("/init", ap));

        cout << "Hello " << endl;

        Listener * listener = new Listener( jWebservice );
        WorkerHandler * handler = new WorkerHandler();

        app->init_webservice(listener, handler);

        cout << "Hello " << endl;
        app->run();

    } catch (exception & e) {
        cout << "Error is:" << endl;
        cout << e.what() <<  endl;
    }
}
// ./a.out -g test/global.yaml -c test/app.yaml
// g++ -I include/ test/test_apploader.cpp  src/*  -l:libubacjsonparser.so.1.2.2 -l:libubacsslinterface.so.1.2.2 -l:libubachttpclient.so.1.2.1 -l:libubacipc.so.1.2.5 -l:libubacutils.so.1.2.2 -l:libubaclogger.so.1.2.2 -l:libubacyaml.so.1.2.1
// curl -X POST "http://localhost:30002/init" -d "{}"
