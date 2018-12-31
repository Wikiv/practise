#ifndef __SBU2_APP_LOADER_H__
#define __SBU2_APP_LOADER_H__

#include <ubacyaml/YamlConfig.h>
#include <ubacutils/Exceptions.h>
#include <ubacutils/GetOption.h>
#include <ubacipc/EventFax.h>
#include <ubaclogger/SLog.h>

#include "SBU2HTTPServer.h"
#include "MasterHTTPServer.h"

using namespace SBU2;

/// Class AppLoader. Please pass global and application yaml files as command line arguments.
class AppLoader
{
	public:
		/** Create AppLoader with initialized arguments. */
		AppLoader(int argc, char *argv[]);
		~AppLoader();

		/** Initializes load balancer and HTTP server. */
		void init_webservice(map<string, SBU2WebService *> * jWebservice);
        void init_webservice(map<string, SBU2WebService *> *jWebservice, WorkerHandler * workerHandler);
		void run();
        void init_webservice(MasterHTTPListener * listener, WorkerHandler *);

        SBU2HTTPServer *getSBU2HTTPServer();
        EventFax *getEventFax();

		/** Logger object. */
		SLog *sLogID;
		/** Yaml objects for global and application configurations. */
		YamlConfig *globalConfig, *appConfig;

	private:
		SBU2LoadBalancer *lBalancer;
		SBU2HTTPServer *httpServer;
		MasterHTTPServer *masterHTTPServer;

		string sForceHttps, sHttpPort;

        char * progName;

		int threadPoolSize;

		void loadYamlConfig();

		map<string, SBU2WebService *> *jWebservice;
};

#endif /* __SBU2_APP_LOADER_H__ */

