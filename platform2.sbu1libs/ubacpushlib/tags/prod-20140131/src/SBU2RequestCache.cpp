#include "SBU2RequestCache.h"

SBU2RequestCache::SBU2RequestCache()
{
}

SBU2RequestCache::~SBU2RequestCache()
{
}

void SBU2RequestCache::add(SBU2StreamingRequest request)
{
	del(request);
	this->insert( make_pair(request.getRequestType(), request) );
}

void SBU2RequestCache::del(SBU2StreamingRequest request)
{
	map<uint8_t, SBU2StreamingRequest>::iterator iRequest = this->find(
				request.getRequestType() );

	if( iRequest != this->end() )
		this->erase( iRequest->first );
}

bool SBU2RequestCache::get(uint8_t iRequestType,
						   SBU2StreamingRequest & request)
{
	map<uint8_t, SBU2StreamingRequest>::iterator iRequest = this->find(
				iRequestType );

	if( iRequest == this->end() ) {
		return false;

	} else {
		request = iRequest->second;
		return true;
	}
}
