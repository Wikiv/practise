#include "SBU2HTTPServer.h"

using namespace SBU2;

SBU2MessageActor::SBU2MessageActor(map<string, WebService *> *mJsonWebservice)
{
	this->mJsonWebservice = mJsonWebservice;
	messageQ = new MessageQueue< map<HTTPServerRequest *, void *> >();
	mutex = new Mutex();
}

SBU2MessageActor::~SBU2MessageActor()
{
}

void SBU2MessageActor::addMessage(HTTPServerRequest *message, void *ptr)
{
	map<HTTPServerRequest *, void *>requestPair;
	requestPair.insert( std::make_pair(message, ptr) );
	messageQ->enqueue( requestPair );
	mutex->notify();
}

void SBU2MessageActor::run()
{
	IFHelper helper;

	while(1) {
		if( messageQ->isEmpty() ) {
			mutex->wait(1);

		} else {
			map<HTTPServerRequest *, void*>requestPair = messageQ->dequeue();
			HTTPServerRequest *request = requestPair.begin()->first;

			map<string, WebService *>::iterator iMap = mJsonWebservice->find(
						request->url.c_str());

			if ( iMap == mJsonWebservice->end() ) {
				HTTPConnection * httpCon = (HTTPConnection *) requestPair.begin()->second;

				HTTPResponse httpResponse(HTTPResponse::not_found);
				httpCon->send(httpResponse);
				httpCon->release();

			} else {
				iMap->second->onPostRequest(request,
											(HTTPConnection *)(requestPair.begin()->second));
			}
		}
	}
}
