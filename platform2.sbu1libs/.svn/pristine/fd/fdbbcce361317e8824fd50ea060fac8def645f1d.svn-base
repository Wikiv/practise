#include "AppLoader.h"

AppLoader::AppLoader(int argc, char *argv[])
{
    GetOption getOption(argc, argv);

    string sGlobalConfigFile;
    getOption.getOption("global-config", sGlobalConfigFile);

    string sAppConfigFile;
    getOption.getOption("app-config", sAppConfigFile);


    if ( sGlobalConfigFile == "" || sAppConfigFile == "" )
    {
        cout << "ERROR : Config files not specified" << endl;
        cout << "Usage : ./prog --global-config "
            "<global-file> --app-config <config-file>" << endl;
        exit(1);
    }

    cout << "global = " << sGlobalConfigFile << endl;
    cout << "app = " << sAppConfigFile << endl;

    globalConfig = new YamlConfig(sGlobalConfigFile);
    appConfig = new YamlConfig(sAppConfigFile);

    (*appConfig) += (*globalConfig);

    string sLogAppender;
    getOption.getOption("log-appender", sLogAppender);

    if( sLogAppender == "" ) {
        stringstream s;
        s << getpid();
        sLogAppender = s.str();
    }

    loadYamlConfig();

    IFHelper helper;

    string pwd = helper.getPWD(argv[0], "/bin");

    sLogID = new SLog( *appConfig, pwd, sLogAppender, false);

    progName = argv[0];
}

void AppLoader::loadYamlConfig()
{
    threadPoolSize = atoi((*appConfig)["thread_pool_size"].c_str());
    sForceHttps = (*appConfig)["http_server"]["force_https"];
    sHttpPort = (*appConfig)["http_server"]["port"];
}


AppLoader::~AppLoader()
{
    delete sLogID;
    delete appConfig;
    delete globalConfig;

    delete lBalancer;
    delete httpServer;
}

void AppLoader::init_webservice(map<string, SBU2WebService *> *jWebservice)
{
    if (jWebservice == NULL ) {
        sLogID->debug("Pass webservice for separate features from Application\n");
        exit(1);
    }

    lBalancer = new SBU2LoadBalancer(threadPoolSize,  jWebservice);
    bool bForceHttps = (sForceHttps.compare("true") == 0);
    httpServer = new SBU2HTTPServer(atoi(sHttpPort.c_str()), lBalancer, bForceHttps);
}

void AppLoader::init_webservice(map<string, SBU2WebService *> *jWebservice, 
        WorkerHandler * workerHandler)
{
    if( (*appConfig)["legacyapp"] == "false" ) {
        masterHTTPServer = new MasterHTTPServer(atoi(sHttpPort.c_str()), 
                jWebservice, workerHandler);

        masterHTTPServer->setProgName(progName);
    } else {
        sLogID->debug("Provide legacyapp = false in config files...exiting\n");
        exit(1);
    }
}

void AppLoader::init_webservice(MasterHTTPListener * listener, 
                                WorkerHandler * handler)
{

    if( (*appConfig)["legacyapp"] == "false" ) {

        masterHTTPServer = new MasterHTTPServer(atoi(sHttpPort.c_str()), 
                listener, handler);

        masterHTTPServer->setProgName(progName);

    } else {
        sLogID->debug("Provide legacyapp = false in config files...exiting\n");
        exit(1);
    }
}

void AppLoader::run()
{

    if( (*appConfig)["legacyapp"] == "true" ) {
        sigset_t new_mask;
        sigfillset(&new_mask);
        sigset_t old_mask;
        pthread_sigmask(SIG_BLOCK, &new_mask, &old_mask);

        pthread_sigmask(SIG_SETMASK, &old_mask, 0);
        sigset_t wait_mask;
        sigemptyset(&wait_mask);
        sigaddset(&wait_mask, SIGINT);
        sigaddset(&wait_mask, SIGQUIT);
        sigaddset(&wait_mask, SIGTERM);

        pthread_sigmask(SIG_BLOCK, &wait_mask, 0);
        httpServer->run();
        int sig = 0;
        sigwait(&wait_mask, &sig);
    } else {
        int nWorkers = atoi( (*appConfig)["workers"].c_str() );
        if( nWorkers <= 0 )
            nWorkers = 5;

        cout << "No of Workers " << nWorkers << endl;

        masterHTTPServer->start(nWorkers);
    }
}

EventFax* AppLoader::getEventFax()
{
    return httpServer->getEventFax();
}

SBU2HTTPServer* AppLoader::getSBU2HTTPServer()
{
    return httpServer;
}
