#include "MessageActor.h"

MessageActor::MessageActor(Application *m_app)
{
	app = m_app;
	messageQ = new MessageQueue< map<string, void *> >();
	mutex = new Mutex();
}

MessageActor::~MessageActor()
{
}

void MessageActor::addMessage(string message, void *ptr)
{
	map<string, void *>requestPair;
	requestPair.insert( make_pair(message, ptr) );
	messageQ->enqueue( requestPair );
	mutex->notify();
}

void MessageActor::run()
{
	IFHelper helper;

//	printf("Starting thread with q %p\n", messageQ);
	while(1) {
		if( messageQ->isEmpty() ) {
//			helper.usleep(10);
			mutex->wait(1);

		} else {
			map<string, void*>requestPair = messageQ->dequeue();
			string request( requestPair.begin()->first );
			int code;
			string data, extModBuf, reply;
			crack(request, code, data, extModBuf);
			app->call(code, data, extModBuf, reply, requestPair.begin()->second);
		}
	}
}
