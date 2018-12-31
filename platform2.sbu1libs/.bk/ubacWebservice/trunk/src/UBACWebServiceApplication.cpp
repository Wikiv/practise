#include "UBACWebServiceApplication.h"

UBACWebServiceApplication::UBACWebServiceApplication(string s,
		Application *m_app, SLog *sLogID, int iThreadPool) 
{
	this->sLogID = sLogID;
	this->m_app = m_app;
	loadBalancer = new LoadBalancer(iThreadPool, m_app);
	mMutex = new Mutex();
}

UBACWebServiceApplication::~UBACWebServiceApplication()
{
}

void UBACWebServiceApplication::removeID( string messageID )
{
	mMutex->lock();
	map<string,string>::iterator iter = messageIDtoApiKeyMap.find(messageID);

	if ( iter != messageIDtoApiKeyMap.end() )
		messageIDtoApiKeyMap.erase(iter);

	mMutex->unlock();
}

string UBACWebServiceApplication::getApiKey( string messageID)
{
	map<string,string>::iterator iter = messageIDtoApiKeyMap.find(messageID);

	if ( iter == messageIDtoApiKeyMap.end() )
		return "";

	return (iter->second);
}

void UBACWebServiceApplication::addMessageID(string & sMessage,
		string & log_request, string & sMessageID)
{
	IFHelper helper;
	int code = 0;
	string sData, sExtMod;
	UBACData::crack(sMessage, code, sData, sExtMod);
	cout << "sMessage = " << sMessage << " , code = " << code << " , sData = " <<
		 sData << " , sExtMod = " << sExtMod << endl;
	ExtMod extMod(sExtMod);
	//Generate Message ID.
	Digest digest;
	stringstream sNewRequest, sTime;
	//Use current time to randomize.
	sTime.setf(ios::fixed, ios::floatfield);
	sTime << helper.currentTime();
	digest.digest(sMessage + sTime.str(), Digest::DigestType_MD5, sMessageID);
	//Set MessageID in extended modifier.
	extMod.setValue("MESSAGE_ID", sMessageID);

	sExtMod.clear();
	//Create New Message
	sNewRequest << code << " " << "<" << sData << ">";

	UBACData::createLogMessage(log_request, code, sData);
	cout << " log_request = " << log_request << endl;

	sMessage.clear();
	sMessage = sNewRequest.str();
	extMod.toString( log_request ) ;
	extMod.toString( sMessage );
}

void UBACWebServiceApplication::handleEncryptedRequest( string sUserAgent,
		string sUbacIdent, string data, string & mobileRequest, string &responseKey)
{
	Base64 b64;
	IFHelper helper;
	string sKey,apiKey,mRequest;
	string newKey;
	vector<string> list;
	helper.split(data, "&", list);

	vector<string>::iterator iter;

	for ( iter = list.begin(); iter != list.end(); iter++ ) {
		if( strstr((*iter).c_str(), "mobile_request=") != NULL )
			mRequest.append((char *)(index((*iter).c_str(), '=') + 1));

		else if( strstr((*iter).c_str(), "api_key=") != NULL )
			apiKey.append((char *)(index((*iter).c_str(), '=') + 1));
	}

	b64.encode(sUserAgent.c_str(), sKey, sUserAgent.length() );
	sKey.append( sUbacIdent );

	Gibberish g1( sKey );
	g1.aes_decrypt( apiKey, newKey);

	cout << "newKey = " << newKey << endl;

	responseKey = newKey;

	Gibberish g2( newKey );
	g2.aes_decrypt( mRequest, mobileRequest );
	cout << "mobileRequest = " << mobileRequest << endl;
}

void UBACWebServiceApplication::encryptResponse( string apiKey, string & data )
{
	string encryptedOutput;
	Gibberish g1( apiKey );
	g1.aes_encrypt( data, encryptedOutput);
	data = encryptedOutput;
}

void UBACWebServiceApplication::processRequest( HTTPServerRequest * request,
		HTTPConnection *connection)
{
	string sHeaders = "", sUserAgent =  "", sUbacIdent = "",data = "",
		   mRequest = "", apiKey, sMessageID;
	HTTPSRequest httrequest;
	IFHelper helper;
	bool isEncrypted = false;

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

	if ( ( sUserAgent.length() != 0) && (sUbacIdent.length() != 0) ) {
		handleEncryptedRequest(sUserAgent, sUbacIdent, data, mRequest, apiKey);
		apiKey.append( sUbacIdent );
		isEncrypted = true;

	} else {
		mRequest = data;
	}

	sLogID->debug("Headers = %s\n", sHeaders.c_str());
	cout << "Headers = " <<  sHeaders << " , Request = " << mRequest << endl;
	string sRequest, log_request;

	if( strstr(mRequest.c_str(), "mobile_request=") != NULL ) {
		sRequest.append((char *)(index(mRequest.c_str(), '=') + 1));

	} else {
		sRequest = mRequest;
	}

	addMessageID( sRequest, log_request, sMessageID );

	if ( isEncrypted ) {
		mMutex->lock();
		messageIDtoApiKeyMap.insert(make_pair(sMessageID, apiKey ) );
		mMutex->unlock();
	}

	sLogID->debug(" Request = %s\n", log_request.c_str());
	cout << "sRequest = " << sRequest << endl;
	helper.rstrip(sRequest, '\n');
	loadBalancer->addMessage(sRequest, connection);
}

void UBACWebServiceApplication::onPostRequest(HTTPServerRequest * request,
		HTTPConnection *connection)
{
	processRequest( request, connection );
}

void UBACWebServiceApplication::onGetRequest(HTTPServerRequest * request,
		HTTPConnection *connection)
{
	processRequest( request, connection );
}

