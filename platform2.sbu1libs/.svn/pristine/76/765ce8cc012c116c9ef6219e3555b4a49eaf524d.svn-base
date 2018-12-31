#include "UBACData.h"

GlobalMarketsResponse::GlobalMarketsResponse()
{
}

GlobalMarketsResponse::~GlobalMarketsResponse()
{
}

void GlobalMarketsResponse::setType(string sType)
{
	type.append(sType);
}

void GlobalMarketsResponse::addEntry(GlobalMarkets entry)
{
	this->push_back(entry);
}

void GlobalMarketsResponse::toString(string & sResponse)
{
	sResponse.append("400 <");
	sResponse.append(type);
	sResponse.append("|");
	for(vector<GlobalMarkets>::iterator iGlobal = this->begin(); iGlobal != this->end(); iGlobal++) {
		string sData;
		(*iGlobal).toString(sData);
		sResponse.append(sData);
		sResponse.append("&");
	}
	IFHelper helper;
	helper.rstrip(sResponse, '&', 1);
	sResponse.append(">");
}

