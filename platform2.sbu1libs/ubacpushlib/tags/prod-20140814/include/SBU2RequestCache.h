#ifndef __SBU2_REQUEST_CACHE_H__
#define __SBU2_REQUEST_CACHE_H__

#include <iostream>
#include <map>

using namespace std;

#include "SBU2StreamingRequest.h"

class SBU2RequestCache :
	public map<uint8_t, SBU2StreamingRequest>
{
	public:
		SBU2RequestCache();
		~SBU2RequestCache();

		void add(SBU2StreamingRequest request);
		void del(SBU2StreamingRequest request);
		bool get(uint8_t iRequestType, SBU2StreamingRequest & request);
};

#endif /* __SBU2_REQUEST_CACHE_H__ */
