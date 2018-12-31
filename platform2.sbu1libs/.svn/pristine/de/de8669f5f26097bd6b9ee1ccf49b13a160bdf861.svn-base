#ifndef __MASTER_PUSH_SERVER_H__
#define __MASTER_PUSH_SERVER_H__

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include "PushServer.h"

namespace SBU2PUSH {

    class WorkerHandler
    {
        public:
            WorkerHandler() {};
            virtual ~WorkerHandler() {};

            virtual void onChildProcess(EventFax *fax) {}

            virtual PushServer * registerPushServer() { return NULL; }
    };

    class MasterPushServer
    {
        public:
            MasterPushServer(WorkerHandler * workerHandler);

            void setProgName(char * pgnName);

            void start(const size_t nWorkerProc = 3);

            static void handler(int sig)
            {
                int status;
                pid_t child;


                while ((child = waitpid(-1, &status, WNOHANG)) > 0)
                {   
                    /* Process with PID 'child' has exited, handle it */
                    printf("Handler called...Pid %d exited.\n", child);

                    nProc--;;

                }
            }

        private:
            static size_t nProc ;
            WorkerHandler * workerHandler;
            char * pgnName;

            void startWorkers(const size_t nWorkerProc);
    };

}

#endif /* __MASTER_PUSH_SERVER_H__ */
