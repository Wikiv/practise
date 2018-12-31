#ifndef __SBU2_WEBSERVICE_APPLICATION_H__
#define __SBU2_WEBSERVICE_APPLICATION_H__

#include <ubaclogger/SLog.h>
#include <ubacutils/IFHelper.h>
#include <ubacipc/HTTPClient.h>
#include <ubacipc/HTTPServer.h>

#include <ubachttpclient/HTTPSRequest.h>

#include "MSFRequest.h"
#include "MSFResponse.h"

namespace SBU2
{
	/// Class SBU2WebService
	class SBU2WebService
	{
		public:
			/** Creates SBU2WebService object. */
            SBU2WebService();
			SBU2WebService(SLog *sLogID);
			~SBU2WebService();

			virtual void onPostRequest( HTTPServerRequest *request, 
                                        HTTPConnection *connection);

			virtual void onGetRequest( HTTPServerRequest *request, 
                                       HTTPConnection *connection);

            virtual void onRawRequest( HTTPServerRequest * request, 
                                       HTTPConnection * connection,
                                       string & rawRequest) {};
                
            virtual void onInvalidJSONRequest( HTTPServerRequest * request, 
                                       HTTPConnection * connection,
                                       string & rawRequest) {};

			virtual void onPostProcessRequest( MSFRequest *msfRequest,
											   MSFResponse * msfResponse,
											   HTTPConnection *connection ) {}

			virtual string getSvcGroup() { return "svcGroup"; }
			virtual string getSvcName() { return "svcName"; }
			virtual string getSvcVersion() { return "1.0.0"; }


		protected:
			SLog *sLogID;
			void sendResponse(MSFResponse *, HTTPConnection *);
	        void sendResponse(MSFResponse *, map<string, string> &,HTTPConnection *);
			void sendErrorResponse(const string, HTTPConnection *);

		private:
			void processRequest( HTTPServerRequest *request, HTTPConnection *connection);
	};
};

#endif /* __SBU2_WEBSERVICE_APPLICATION_H__ */
