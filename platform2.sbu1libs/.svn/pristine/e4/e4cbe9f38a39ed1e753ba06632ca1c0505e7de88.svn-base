#include "LoadBalancer.h"

LoadBalancer::LoadBalancer()
{
	loadItem = 0;
}

LoadBalancer::LoadBalancer(int iPoolSize, Application *app)
{
	loadItem = 0;
	cout << "Creating " << iPoolSize << " actors" << endl;

	for(int i = 0; i < iPoolSize; i++) {
		MessageActor *actor;
		actor = new MessageActor(app);
		actor->start(NULL);
		addActor( *actor );
	}
}

LoadBalancer::~LoadBalancer()
{
}

void LoadBalancer::addActor(MessageActor actor)
{
	actorList.push_back( actor );
}

void LoadBalancer::addMessage(string message, void *ptr)
{
	actorList[loadItem].addMessage( message, ptr );
	loadItem++;
	loadItem = loadItem % actorList.size();
}
