#include "UBACData.h"

BrokerCommissionResponse::BrokerCommissionResponse()
{
}

BrokerCommissionResponse::~BrokerCommissionResponse()
{
}

void BrokerCommissionResponse::setCommission( string mCommission )
{
	commission.append("COMMISSION=");
	commission.append( mCommission );
}

void BrokerCommissionResponse::setCommissionData(string sName, string sValue)
{
	IFHelper helper;
	commission_data_map.insert( make_pair(sName, sValue) );
}

void BrokerCommissionResponse::toString(string & response)
{
	map<string, string>::iterator iCommissionData = commission_data_map.begin();
	response.append("538 <");
	response.append(commission);
	// Adding | only if commission has value & commission_data also has values
	if(commission.length() > 0 && iCommissionData != commission_data_map.end())
		response.append("|");
	while(iCommissionData != commission_data_map.end()) {
		// Appending | only from second commission_data onwards
		if(iCommissionData != commission_data_map.begin())
			response.append("|");
		response.append(iCommissionData->first + "=" + iCommissionData->second);
		iCommissionData++;
	}
	response.append(">");
}
