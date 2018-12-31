#include "SBU2WebService.h"

using namespace SBU2;

SBU2WebService::SBU2WebService(SLog *sLogID)
{
	this->sLogID = sLogID;
//	mMutex = new Mutex();
}

SBU2WebService::~SBU2WebService()
{
}

void SBU2WebService::processRequest( HTTPServerRequest *request,
									 HTTPConnection *connection)
{
	string sHeaders = "", sUserAgent =  "", sUbacIdent = "",data = "",
		   mRequest = "";
	HTTPSRequest httrequest;
	IFHelper helper;

	for(map<string, string>::iterator iHeaders = request->headers.begin();
			iHeaders != request->headers.end(); iHeaders++) {
		sHeaders = sHeaders + iHeaders->first + "=" + iHeaders->second + ",";

		if ( strcasecmp(iHeaders->first.c_str(), "X-Ubac-Ident") == 0 )
			sUbacIdent = iHeaders->second;

		else if ( strcasecmp(iHeaders->first.c_str(),"User-Agent") == 0 )
			sUserAgent = iHeaders->second;
	}

	data = request->sContent;
	httrequest.url_decode(data);
	mRequest = data;
	sLogID->debug("Headers = %s\n", sHeaders.c_str());
	cout << "Headers = " <<  sHeaders << " , Request = " << mRequest << endl;
	string sRequest, log_request;

	if( strstr(mRequest.c_str(), "mobile_request=") != NULL ) {
		sRequest.append((char *)(index(mRequest.c_str(), '=') + 1));

	} else {
		sRequest = mRequest;
	}


	cout << "sRequest = " << sRequest << endl;
	sLogID->debug(" Request = %s\n", sRequest.c_str());
	MSFRequest msfRequest(sRequest);

	MSFResponse msfResponse( &msfRequest );
	msfResponse.setSvcGroup( getSvcGroup() );
	msfResponse.setSvcName( getSvcName() );
	msfResponse.setSvcVersion( getSvcVersion() );

	cout << "status of isValidJson() = " << msfRequest.isValidJson() << endl;

	if (msfRequest.isValidJson()) {
		onPostProcessRequest( &msfRequest, &msfResponse, connection );

	} else {
		cout << "(HTTPResponse::bad_request" << HTTPResponse::bad_request << endl;
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
    sLogID->debug("sResponse = %s\n", sResponse.c_str());
	HTTPResponse httpResponse(HTTPResponse::ok);
	httpResponse.setContent(sResponse);
	httpResponse.setHeader("Content-Type", "text/json");
	connection->send(httpResponse);
	connection->release();
}
