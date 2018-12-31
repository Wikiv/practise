#include "MasterPushServer.h"

using namespace SBU2PUSH;

class MyWorkerHandler: 
    public WorkerHandler
{
    public:
        MyWorkerHandler() {}

        void onChildProcess(EventFax * fax) 
        {
            cout << "OnCreate Child Process" << endl;
        }

        PushServer * registerPushServer()
        {
            IFSubscriptions * ifSubscriptions = new IFSubscriptions();
            return new PushServer(11001, 3600, ifSubscriptions);
        }

};


int main(int argc, char * argv[])
{


    MyWorkerHandler * worker = new MyWorkerHandler();

    MasterPushServer masterPushServer(worker);

    masterPushServer.setProgName(argv[0]);

    masterPushServer.start(5);
}
