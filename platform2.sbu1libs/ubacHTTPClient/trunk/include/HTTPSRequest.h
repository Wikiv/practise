#ifndef __UBAC_HTTPS_REQUEST_H__
#define __UBAC_HTTPS_REQUEST_H__

#include "HTTPRequest.h"

namespace UBAC {
	/// Class HTTPSRequest. Implements HTTPS client.
	class HTTPSRequest :
		public HTTPRequest
	{
		public:
			HTTPSRequest();
			~HTTPSRequest();
	
			/** Call this function to disable certificate validation */
			void disableVerifyCertificate();

            void enableVerifyCertificate();

            void enableVerifyPeer();

            void disableVerifyPeer();


	};
};

using namespace UBAC;

#endif /* __UBAC_HTTPS_REQUEST_H__ */
