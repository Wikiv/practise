#include "UBACData.h"

BrokerSwitchAccountRequest::BrokerSwitchAccountRequest(string sRequest)
{
	parse( sRequest );
}

string BrokerSwitchAccountRequest::getSessionID()
{
	return sSessionID;
}

string BrokerSwitchAccountRequest::getAccountID()
{
	return sAccountID;
}

string BrokerSwitchAccountRequest::getAccountNumber()
{
	return sAccountNumber;
}

string BrokerSwitchAccountRequest::getUsername()
{
	return sUsername;
}

string BrokerSwitchAccountRequest::getPassword()
{
	return sPassword;
}

void BrokerSwitchAccountRequest::setNameValue(string sName, string sValue)
{
	if( strcasecmp(sName.c_str(), "AccountID") == 0 ) {
		sAccountID.append( sValue );
	} else if( strcasecmp(sName.c_str(), "AccountNumber") == 0 ) {
		sAccountNumber.append( sValue );
	} else if( strcasecmp(sName.c_str(), "username") == 0 ) {
		sUsername.append( sValue );
	} else if( strcasecmp(sName.c_str(), "password") == 0 ) {
		sPassword.append( sValue );
	} else if( strcasecmp(sName.c_str(), "sessionID") == 0 ) {
		sSessionID.append( sValue );
	}
}

void BrokerSwitchAccountRequest::parse(string sRequest)
{
	string sName, sValue;
	bool isName = true;
	for(size_t i = 0;i < sRequest.length(); i++) {
		if( sRequest[i] == '|' ) {
			setNameValue(sName, sValue);
			sName.clear(); sValue.clear();
			isName = true;
		} else if( sRequest[i] == '=' ) {
			isName = false;
		} else {
			(isName) ? sName.append(&sRequest[i], 1) : sValue.append(&sRequest[i], 1);
		}
	}
	setNameValue(sName, sValue);
}
