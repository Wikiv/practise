#ifndef __SBU2_WEBSERVICE_APPLICATION_H__
#define __SBU2_WEBSERVICE_APPLICATION_H__

#include <ubaclogger/SLog.h>
#include <ubacutils/IFHelper.h>
#include <ubachttpclient/HTTPSRequest.h>

#include "MSFRequest.h"
#include "MSFResponse.h"
#include "SBU2HTTPServer.h"

namespace SBU2
{
	class SBU2WebService :
		public WebService
	{
		public:
			SBU2WebService(SLog *sLogID);
			~SBU2WebService();

			virtual void onPostRequest(HTTPServerRequest *request, HTTPConnection *connection);
			virtual void onGetRequest(HTTPServerRequest *request, HTTPConnection *connection);
			virtual void onPostProcessRequest( MSFRequest *msfRequest,
											   MSFResponse * msfResponse,
											   HTTPConnection *connection ) {}
			virtual string getSvcGroup() {}
			virtual string getSvcName() {}
			virtual string getSvcVersion() {}

		protected:
			SLog *sLogID;
			void sendResponse(MSFResponse *, HTTPConnection *);
			void sendErrorResponse(const string, HTTPConnection *);

		private:
			void processRequest( HTTPServerRequest *request, HTTPConnection *connection);
//			Mutex *mMutex;
	};
};

#endif /* __SBU2_WEBSERVICE_APPLICATION_H__ */
