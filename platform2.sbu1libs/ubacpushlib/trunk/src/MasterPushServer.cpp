#include "MasterPushServer.h"

using namespace SBU2PUSH;

size_t MasterPushServer::nProc = 0;

MasterPushServer::MasterPushServer(WorkerHandler * workerHandler)
{
    this->workerHandler = workerHandler;
    this->pgnName = NULL;

    signal(SIGCHLD, handler);
}

void MasterPushServer::start(const size_t nWorkerProc)
{
    // Changing program name to master ("-M")
    if (pgnName != NULL && strlen(pgnName) > 2)
    {
        memcpy(pgnName + strlen(pgnName) - 2, "-M", 2);
    }

    startWorkers(nWorkerProc);

    while(1)
    {
        sleep(3);
        startWorkers(nWorkerProc);
    }
}

void MasterPushServer::setProgName(char * pgnName)
{
    this->pgnName = pgnName;
}

void MasterPushServer::startWorkers(const size_t nWorkerProc)
{
    size_t workersCnt = 0;
    for(size_t i = nProc; i < nWorkerProc; i++)
    {
        pid_t pid = fork();

        if (pid == 0) {

            prctl(PR_SET_PDEATHSIG,  SIGKILL);

            if (pgnName != NULL && strlen(pgnName) > 2)
            {
                memcpy(pgnName + strlen(pgnName) - 2, "-W", 2);
            }

            EventFax *fax = new EventFax();

            PushServer * pushServer = workerHandler->registerPushServer();

            if ( pushServer != NULL )
            {
                pushServer->setEventFax(fax);

                fax->addTCPServer( pushServer );
            }

            workerHandler->onChildProcess(fax);

            fax->run();
        }

        workersCnt++;
    }

    nProc += workersCnt;
}
