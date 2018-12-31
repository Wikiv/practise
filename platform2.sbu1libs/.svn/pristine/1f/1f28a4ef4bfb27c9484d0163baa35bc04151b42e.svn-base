#include "UBACData.h"

BrokerCustomerProfileResponse::BrokerCustomerProfileResponse()
{
}

BrokerCustomerProfileResponse::~BrokerCustomerProfileResponse()
{
}

void BrokerCustomerProfileResponse::toString(string & response)
{
	response = "562 <";
	map<string, string>::iterator iData;
	for(iData= dataMap.begin(); iData != dataMap.end(); iData++) {
		response.append( iData->first );
		response.append( "=" );
		response.append( iData->second );
		response.append("|");
	}
	IFHelper helper;
	helper.rstrip(response, '|');
	response.append(">");
}

void BrokerCustomerProfileResponse::setData(string response, string field)
{
	dataMap.insert( make_pair(response, field) );
}
