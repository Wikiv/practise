#include "SBU2HTTPServer.h"

using namespace SBU2;

SBU2LoadBalancer::SBU2LoadBalancer(int iPoolSize,
								   map<string, SBU2WebService *> *mJsonWebservice)
{
	loadItem = 0;
	cout << "Creating " << iPoolSize << " actors" << endl;

	for(int i = 0; i < iPoolSize; i++) {
		SBU2MessageActor *actor;
		actor = new SBU2MessageActor(mJsonWebservice);
		actor->start(NULL);
		addActor( actor );
	}
}

SBU2LoadBalancer::~SBU2LoadBalancer()
{
    vector<SBU2MessageActor *>::iterator iActors = actorList.begin();

    while ( iActors != actorList.end() )
    {
        delete (* iActors);

        iActors++;
    }
}

void SBU2LoadBalancer::addActor(SBU2MessageActor * actor)
{
	actorList.push_back( actor );
}

void SBU2LoadBalancer::addMessage(HTTPServerRequest *message, void *ptr)
{
	actorList[loadItem]->addMessage( message, ptr );
	loadItem++;
	loadItem = loadItem % actorList.size();
}
