#include "SBU2HTTPServer.h"

using namespace SBU2;
using namespace UBACIPC;


SBU2HTTPListner::SBU2HTTPListner(SBU2LoadBalancer * lBalancer)
{
    this->lBalancer = lBalancer;
}

SBU2HTTPListner::~SBU2HTTPListner()
{
}

void SBU2HTTPListner::onGetRequest(HTTPServerRequest *request, 
                              HTTPConnection *client)
{
    this->lBalancer->addMessage(request, client);
}

void SBU2HTTPListner::onPostRequest(HTTPServerRequest *request, 
                            HTTPConnection *client)
{
    this->lBalancer->addMessage(request, client);
}
