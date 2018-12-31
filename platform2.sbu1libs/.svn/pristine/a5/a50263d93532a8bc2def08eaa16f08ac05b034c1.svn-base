#include "UBACData.h"

AcceptDisclaimerRequest::AcceptDisclaimerRequest(string data)
{
	parse(data);
}

AcceptDisclaimerRequest::~AcceptDisclaimerRequest()
{
}

string AcceptDisclaimerRequest::getAccountID()
{
	return accountID;
}

string AcceptDisclaimerRequest::getParam(string sKey)
{
	upcase( sKey );
	map<string, string>::iterator iParam = otherValues.find( sKey );
	if(iParam == otherValues.end())
		return "";
	else
		return iParam->second;
}

void AcceptDisclaimerRequest::handleOtherParams(string sName, string sValue)
{
	if( strcasecmp(sName.c_str(), "accountid") == 0 ) {
		accountID.append(sValue);
	} else {
		upcase( sName );
		otherValues.insert( make_pair( sName, sValue) );
	}
}

void AcceptDisclaimerRequest::parse(string data)
{
	string sBuffer, sName;
	for(size_t i = 0 ; i < data.length(); i++) {
		if( data[i] == '|' ) {
			handleOtherParams(sName, sBuffer);
			sBuffer.clear(); sName.clear();
		} else if( data[i] == '=' ) {
			sName.append(sBuffer);
			sBuffer.clear();
		} else {
			sBuffer.append(&data[i], 1);
		}
	}
	handleOtherParams(sName, sBuffer);
}
