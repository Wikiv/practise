#include "SBU2WebService.h"

using namespace SBU2;

SBU2WebService::SBU2WebService()
{
}

SBU2WebService::SBU2WebService(SLog *sLogID)
{
    this->sLogID = sLogID;
}

SBU2WebService::~SBU2WebService()
{
}

void SBU2WebService::processRequest( HTTPServerRequest *request,
        HTTPConnection *connection)
{
    string sUrl = request->url;
    string sRequest = request->sContent;
    
    //TODO - URL decoding is not required. 
    //But some devices can send POST body with encoding, which is wrong.
    //This could create problem, when raw Json contains url special characters.
	// Commenting out below lines since this create issues when special characters are sent.
	// Also requests are not sent with "mobile_request" keywords

    /*HTTPRequest::url_decode(mRequest);
    string sRequest;
    if( strstr(mRequest.c_str(), "mobile_request=") != NULL ) {
        sRequest.append((char *)(index(mRequest.c_str(), '=') + 1));

    } else {
        sRequest = mRequest;
    } */

    onRawRequest(request, connection, sRequest);

    // Derived class can analize and release the connection if they want.
    // if it is released No point in continuing.
    if ( connection->isMarkedForDisconnection() ) return;


    MSFRequest msfRequest(sRequest);
    
    if( msfRequest.isValidJson() )
    {
	string sMsg= sUrl+sRequest;
	msfRequest.setMsgID(sMsg);
        msfRequest.setHTTPServerReq(request);

        MSFResponse msfResponse( &msfRequest );
        msfResponse.setSvcGroup( getSvcGroup() );
        msfResponse.setSvcName( getSvcName() );
        msfResponse.setSvcVersion( getSvcVersion() );

        onPostProcessRequest( &msfRequest, &msfResponse, connection );

    } else {

        onInvalidJSONRequest(request, connection, sRequest);

        if (connection->isMarkedForDisconnection()) return;

        sendErrorResponse(HTTPResponse::bad_request, connection);
    }
}

void SBU2WebService::onPostRequest(HTTPServerRequest *request,
        HTTPConnection *connection)
{
    processRequest( request, connection );
}

void SBU2WebService::onGetRequest(HTTPServerRequest *request,
        HTTPConnection *connection)
{
    processRequest( request, connection );
}

void SBU2WebService::sendErrorResponse(const string sError,
        HTTPConnection * connection)
{
    HTTPResponse httpResponse(sError);
    connection->send(httpResponse);
    connection->release();
}

void SBU2WebService::sendResponse(MSFResponse * msfResponse,
        HTTPConnection * connection)
{
    string sResponse(msfResponse->toString());
    HTTPResponse httpResponse(HTTPResponse::ok);
    httpResponse.setContent(sResponse);
    httpResponse.setHeader("Content-Type", "text/json");
    connection->send(httpResponse);
    connection->release();
}

void SBU2WebService::sendResponse(MSFResponse * msfResponse, 
        map<string, string> & headers,
        HTTPConnection * connection)
{
    string sResponse(msfResponse->toString());
    HTTPResponse httpResponse(HTTPResponse::ok);
    httpResponse.setContent(sResponse);
    httpResponse.setHeaders(headers);
    httpResponse.setHeader("Content-Type", "text/json");
    connection->send(httpResponse);
    connection->release();
}
