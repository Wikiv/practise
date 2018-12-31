#include "UBACData.h"

BrokerGetWatchListResponse::BrokerGetWatchListResponse()
{
}

BrokerGetWatchListResponse::~BrokerGetWatchListResponse()
{
}

void BrokerGetWatchListResponse::setAccountID(string mAccountId)
{
	if(accountId.length() > 0)
		accountId.clear();
	accountId.append( mAccountId );
}

void BrokerGetWatchListResponse::addWatchListGroup(WatchListGroup list)
{
	groupList.push_back( list );
}

void BrokerGetWatchListResponse::toString(string & response)
{
	response.append("472 <");
	response.append(accountId);
	vector<WatchListGroup>::iterator i;
	for(i = groupList.begin(); i != groupList.end(); i++) {
		response.append("&");
		(*i).toString(response);
	}
	response.append(">");
}
