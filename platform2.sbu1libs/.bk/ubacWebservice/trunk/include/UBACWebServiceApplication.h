#ifndef __UBAC_WEBSERVICE_APPLICATION_H__
#define __UBAC_WEBSERVICE_APPLICATION_H__

#include <ubacipc/HTTPServer.h>
#include <ubaclogger/SLog.h>
#include <ubacutils/IFHelper.h>
#include <ubacsslinterface/Gibberish.h>
#include <ubachttpclient/HTTPSRequest.h>

#include "LoadBalancer.h"
#include "Application.h"

class UBACWebServiceApplication :
	public HTTPListner
{
	public:
		UBACWebServiceApplication(string s, Application * m_app, SLog *sLogID,
								  int iThreadPool = 50);
		~UBACWebServiceApplication();

		void onPostRequest(HTTPServerRequest * request, HTTPConnection *connection);
		void onGetRequest(HTTPServerRequest * request, HTTPConnection *connection);

		string getApiKey( string messageID);
		void removeID( string messageID );
		void encryptResponse( string apiKey, string & data );

	private:
		SLog *sLogID;
		Application *m_app;
		LoadBalancer *loadBalancer;
		void addMessageID(string & sMessage, string & log_request, string &sMessageID);
		void handleEncryptedRequest( string sUserAgent, string sUbacIdent, string data,
									 string & mobileRequest, string &responsekey);
		void processRequest( HTTPServerRequest * request, HTTPConnection *connection);
		map <string, string> messageIDtoApiKeyMap;
		Mutex *mMutex;
};

#endif /* __UBAC_WEBSERVICE_APPLICATION_H__ */
