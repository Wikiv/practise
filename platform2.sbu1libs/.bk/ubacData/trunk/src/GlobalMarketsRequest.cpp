#include "UBACData.h"

GlobalMarketsRequest::GlobalMarketsRequest()
{
}

GlobalMarketsRequest::GlobalMarketsRequest(string sRequest)
{
	parse(sRequest);
}

GlobalMarketsRequest::~GlobalMarketsRequest()
{
}

void GlobalMarketsRequest::parse(string sRequest)
{
	type.append(sRequest);
}

string GlobalMarketsRequest::getType()
{
	return type;
}

