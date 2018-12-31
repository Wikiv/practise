#include "MasterHTTPServer.h"

MasterHTTPListener::MasterHTTPListener(map<string, SBU2WebService *> * serviceMap) 
{ 
    this->serviceMap = serviceMap; 
}

void MasterHTTPListener::onGetRequest(HTTPServerRequest * request, 
        HTTPConnection *client)
{
    map<string, SBU2WebService *>::iterator iService 
        = serviceMap->find( request->url.c_str() );
    if( iService != serviceMap->end() )
        iService->second->onGetRequest(request, client);
    else {

        onServiceNotFound(request, client);
        if ( client->isMarkedForDisconnection() ) return;

        sendError(request, client);
    }
}

void MasterHTTPListener::onPostRequest(HTTPServerRequest * request, 
        HTTPConnection *client)
{
    map<string, SBU2WebService *>::iterator iService 
        = serviceMap->find( request->url.c_str() );

    if( iService != serviceMap->end() )
        iService->second->onPostRequest(request, client);
    else {

        onServiceNotFound(request, client);
        if ( client->isMarkedForDisconnection() ) return;

        sendError(request, client);
    }
}

void MasterHTTPListener::sendError(HTTPServerRequest * request, 
        HTTPConnection *client)
{
    HTTPResponse httpResponse(HTTPResponse::not_found);
    client->send(httpResponse);
    client->release();
}
