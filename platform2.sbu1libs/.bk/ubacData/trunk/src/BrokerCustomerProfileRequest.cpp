#include "UBACData.h"

BrokerCustomerProfileRequest::BrokerCustomerProfileRequest(string data)
{
	sAccountID = data;
}

BrokerCustomerProfileRequest::~BrokerCustomerProfileRequest()
{
}

string BrokerCustomerProfileRequest::getAccountID()
{
	return sAccountID;
}
