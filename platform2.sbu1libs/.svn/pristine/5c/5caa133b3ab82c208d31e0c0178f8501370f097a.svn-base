#include "UBACData.h"

BrokerBalancesRequest::BrokerBalancesRequest(string data) : std::string(data)
{
	parse(data);
}

BrokerBalancesRequest::~BrokerBalancesRequest()
{
}

string BrokerBalancesRequest::getAccountID()
{
	return accountID;
}

string BrokerBalancesRequest::getUserName()
{
	return sUserName;
}

string BrokerBalancesRequest::getParam(string sKey)
{
	map<string, string>::iterator iParam = otherParams.find( sKey );
	if(iParam == otherParams.end())
		return "";
	else
		return iParam->second;
}

string BrokerBalancesRequest::getPassword()
{
	return sPassword;
}

string BrokerBalancesRequest::getType()
{
	return sType;
}

void BrokerBalancesRequest::handleOtherParams(string sName, string sValue)
{
	if( strcasecmp(sName.c_str(), "username") == 0 ) {
		sUserName.append(sValue);
	} else if( strcasecmp(sName.c_str(), "password") == 0 ) {
		sPassword.append(sValue);
	} else if( strcasecmp(sName.c_str(), "type") == 0 ) {
		sType.append(sValue);
	} else {
		otherParams.insert( make_pair(sName, sValue) );
	}
}

void BrokerBalancesRequest::parse(string data)
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

string BrokerBalancesRequest::toString()
{
	string s("454 <");
	s = s + (*this) + ">";
	return s;
}
