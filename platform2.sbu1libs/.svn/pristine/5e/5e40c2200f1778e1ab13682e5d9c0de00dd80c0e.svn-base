#include "SBU2HTTPServer.h"

using namespace SBU2;

SBU2HTTPServer::SBU2HTTPServer(int port, SBU2LoadBalancer *balancer
        , bool bForceHttps) 
{
    fax = new EventFax();
    httpServer = new HTTPServer(port, fax, new SBU2HTTPListner(balancer), bForceHttps);
}

SBU2HTTPServer::~SBU2HTTPServer()
{
    delete httpServer;
    delete fax;
}

void SBU2HTTPServer::run()
{
    fax->addTCPServer(httpServer);
    fax->run();
}

EventFax* SBU2HTTPServer::getEventFax()
{
    return fax;
}
