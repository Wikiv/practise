#ifndef __MASTER_HTTP_SERVER_H__
#define __MASTER_HTTP_SERVER_H__

#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/prctl.h>

#include <ubacipc/HTTPServer.h>
#include "SBU2WebService.h"

namespace SBU2 {

    class WorkerHandler
    {
        public:
            WorkerHandler() {}; 
            virtual ~WorkerHandler() {}; 
            virtual void onChildProcess(EventFax *fax) {};   
    };

	class MasterHTTPListener :
		public HTTPListner
	{
		public:
			MasterHTTPListener(map<string, SBU2WebService *> * serviceMap); 
			void onGetRequest(HTTPServerRequest * request, HTTPConnection *client);
			void onPostRequest(HTTPServerRequest * request, HTTPConnection *client);
            
            virtual void onServiceNotFound(HTTPServerRequest * request, 
                    HTTPConnection * client) {}

		private:
			map<string, SBU2WebService *> *serviceMap;
			void sendError( HTTPServerRequest * request, HTTPConnection *client);
	};

	class MasterHTTPServer 
	{
		public:
			MasterHTTPServer(int iPort, 
                            map<string, SBU2WebService *> *serviceMap, 
                            WorkerHandler * workerHandler);

			MasterHTTPServer(int iPort, 
                            MasterHTTPListener * listener,
                            WorkerHandler * workerHandler);

			void start(const size_t nWokers);

            void setProgName(char * pgnName);

			static void handler(int sig)
			{
				int status;
				pid_t child;
	
				while( (child = waitpid(-1, &status, WNOHANG)) > 0 )
				{
					cout << "Exited child: " << child << endl;
					nProc--;
				}
			}

		private:

            void init(int port, MasterHTTPListener * listener, 
                    WorkerHandler * handler);

			static size_t nProc;

            char * pgnName;

            HTTPServer * httpServer;

            int iPort;

			MasterHTTPListener *masterHTTPListener;
            WorkerHandler *workerHandler;
			void startWorkers(const size_t nWorkers);
	};
};

using namespace SBU2;

#endif /* __MASTER_HTTP_SERVER_H__ */
