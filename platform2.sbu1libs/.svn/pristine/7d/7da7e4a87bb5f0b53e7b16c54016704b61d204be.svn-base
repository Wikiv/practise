#ifndef __SBU2_REQUEST_CACHE_H__
#define __SBU2_REQUEST_CACHE_H__

#include <iostream>
#include <map>

using namespace std;

#include "SBU2StreamingRequest.h"

/// Class SBU2RequestCache stores the streaming requests along with the request type in the map.
class SBU2RequestCache :
	public map<uint8_t, SBU2StreamingRequest>
{
	public:
		SBU2RequestCache();
		~SBU2RequestCache();

		/** Deletes the 'request' if present from the map and adds the 'request' to the map. */
		void add(SBU2StreamingRequest request);
		/** Deletes the streaming request from the cache. */
		void del(SBU2StreamingRequest request);
		/** Stores the streaming request in 'request' based on 'iRequestType'.
                * Request type can be either subscription or unsubscription. */
		bool get(uint8_t iRequestType, SBU2StreamingRequest & request);
};

#endif /* __SBU2_REQUEST_CACHE_H__ */
