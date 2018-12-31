#include "UBACData.h"

BrokerPortfolioRequest::BrokerPortfolioRequest(string data) : string(data)
{
	 parse(data);
}

BrokerPortfolioRequest::~BrokerPortfolioRequest()
{
}

string BrokerPortfolioRequest::getParam(string sKey)
{
	map<string, string>::iterator iParam;
	for(iParam = otherParams.begin(); iParam != otherParams.end(); iParam++) {
		if( strcasecmp(sKey.c_str(), iParam->first.c_str()) == 0 ) 
			return iParam->second;
	}
	return "";
}

string BrokerPortfolioRequest::getAccountID()
{
	return accountID;
}

void BrokerPortfolioRequest::handleOtherParams(string sName, string sValue)
{
	if( strcasecmp(sName.c_str(), "type") == 0 ) {
		sRequestType.append(sValue);
	} else if( strcasecmp(sName.c_str(), "exchange") == 0 ) {
		sExchange.append(sValue);
	} else {
		otherParams.insert( make_pair(sName, sValue) );
	}
}

void BrokerPortfolioRequest::parse(string data)
{
	string sBuffer, sName;
	int state = 0;
	for(size_t i = 0 ; i < data.length(); i++) {
		if( data[i] == '|' ) {
			if( state == 0 ) {
				accountID.append( sBuffer );
			} else {
				handleOtherParams(sName, sBuffer);
			}
			sBuffer.clear(); sName.clear();
			state++;
		} else if( data[i] == '=' ) {
			sName.append(sBuffer);
			sBuffer.clear();
		} else {
			sBuffer.append(&data[i], 1);
		}
	}
	if( state == 0 ) {
		accountID.append(sBuffer);
	} else {
		handleOtherParams(sName, sBuffer);
	}
}

string BrokerPortfolioRequest::getRequestType()
{
	return sRequestType;
}

string BrokerPortfolioRequest::getExchange()
{
	return sExchange;
}

string BrokerPortfolioRequest::toString()
{
	stringstream sPortfolioRequest;
	sPortfolioRequest << Protocol_BROKER_POSITIONS << " <" << (*this) << ">";
	return sPortfolioRequest.str();
}
