#include "MasterHTTPServer.h"

size_t MasterHTTPServer::nProc = 0;

MasterHTTPServer::MasterHTTPServer(int iPort, 
                                    map<string, SBU2WebService *> *serviceMap, 
                                    WorkerHandler * workerHandler)
{
	MasterHTTPListener * _l = new MasterHTTPListener(serviceMap);
    init(iPort, _l, workerHandler);
}

MasterHTTPServer::MasterHTTPServer(int iPort,
                                    MasterHTTPListener * listener,
                                    WorkerHandler * workerHandler)
{
    init(iPort, listener, workerHandler);
}

void MasterHTTPServer::init(int iPort, MasterHTTPListener * listener, 
                            WorkerHandler * workerHandler)
{
    
    this->masterHTTPListener = listener;
    this->iPort = iPort;
    //this->httpServer = new HTTPServer(this->iPort, this->masterHTTPListener);
	this->workerHandler = workerHandler;

    this->pgnName = NULL;

	signal(SIGCHLD, handler);
}

void MasterHTTPServer::setProgName(char * pgnName)
{
        this->pgnName = pgnName;
}

void MasterHTTPServer::start(const size_t nWorkers)
{
    // Changing program name to master ("-M")
    if (pgnName != NULL && strlen(pgnName) > 2)
    {   
        memcpy(pgnName + strlen(pgnName) - 2, "-M", 2); 
    }

    startWorkers(nWorkers);

    while(1) {
        sleep(3);
        startWorkers(nWorkers);
    }
}

void MasterHTTPServer::startWorkers(const size_t nWorkers)
{
	size_t workersCnt = 0;

	for(size_t i = nProc; i < nWorkers; i++) 
	{
        pid_t pid = fork();

        if( pid == 0 ) 
        {
            prctl(PR_SET_PDEATHSIG,  SIGKILL);
            cout << "started child with " << getpid() << endl;

            if (pgnName != NULL && strlen(pgnName) > 2)
            {   
                memcpy(pgnName + strlen(pgnName) - 2, "-W", 2); 
            }

            EventFax *fax = new EventFax();

            HTTPServer * httpServer = new HTTPServer(this->iPort, this->masterHTTPListener);
            httpServer->setFax(fax);
            fax->addTCPServer( httpServer );

            workerHandler->onChildProcess(fax);

            fax->run();
        }

        workersCnt++;
    }

    nProc += workersCnt;
}
