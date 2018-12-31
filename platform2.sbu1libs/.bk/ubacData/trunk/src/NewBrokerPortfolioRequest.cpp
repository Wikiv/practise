#include "UBACData.h"

NewBrokerPortfolioRequest::NewBrokerPortfolioRequest(string data) : string(data)
{
	 parse(data);
}

NewBrokerPortfolioRequest::~NewBrokerPortfolioRequest()
{
}

string NewBrokerPortfolioRequest::getParam(string sKey)
{
	map<string, string>::iterator iParam;
	for(iParam = otherParams.begin(); iParam != otherParams.end(); iParam++) {
		if( strcasecmp(sKey.c_str(), iParam->first.c_str()) == 0 ) 
			return iParam->second;
	}
	return "";
}

string NewBrokerPortfolioRequest::getAccountID()
{
	return accountID;
}

void NewBrokerPortfolioRequest::handleOtherParams(string sName, string sValue)
{
	if( strcasecmp(sName.c_str(), "accountid" ) == 0 ) {
		accountID.append( sValue );
	} else if( strcasecmp(sName.c_str(), "type") == 0 ) {
		sRequestType.append(sValue);
	} else if( strcasecmp(sName.c_str(), "exchange") == 0 ) {
		sExchange.append(sValue);
	} else {
		otherParams.insert( make_pair(sName, sValue) );
	}
}

void NewBrokerPortfolioRequest::parse(string data)
{
	string sBuffer, sName;
	int state = 0;
	for(size_t i = 0 ; i < data.length(); i++) {
		if( data[i] == '|' ) {
			handleOtherParams(sName, sBuffer);
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

string NewBrokerPortfolioRequest::getRequestType()
{
	return sRequestType;
}

string NewBrokerPortfolioRequest::getExchange()
{
	return sExchange;
}

string NewBrokerPortfolioRequest::toString()
{
	string s = "978 <" + (*this) + ">";
	return s;
}
