#include "UBACData.h"

NewBrokerOrderStatusRequest::NewBrokerOrderStatusRequest(string data) : string(data)
{
	parse(data);
}

NewBrokerOrderStatusRequest::~NewBrokerOrderStatusRequest()
{
}

void NewBrokerOrderStatusRequest::parse(string data)
{
	size_t i;
	string buffer = "", name = "";
	for(i = 0;i < data.length(); i++) {
		if( data[i] == '=' ) {
			name = buffer;
			buffer.clear();
		} else if( data[i] == '|' ) {
			setNameValueData( name , buffer );
			name.clear();
			buffer.clear();
		} else {
			buffer.append(&data[i], 1);
		}
	}

	if ( ( name.length() ) && ( buffer.length() ) )
		setNameValueData( name , buffer );
}


void NewBrokerOrderStatusRequest::setNameValueData( string mName, string mValue )
{
	if( strcasecmp(mName.c_str(), "accountid") == 0 ) {
		accountID = mValue;
	} else if( strcasecmp(mName.c_str(), "type") == 0 ) {
		durationType = mValue;
	} else {
		otherParams.insert( make_pair(mName, mValue) );
	}
}

string NewBrokerOrderStatusRequest::getAccountID()
{
	return accountID;
}

string NewBrokerOrderStatusRequest::getDurationType()
{
	return durationType;
}

string NewBrokerOrderStatusRequest::getParam(string sKey)
{
	map<string, string>::iterator iParam = otherParams.find( sKey );
	if( iParam == otherParams.end() )
		return "";
	else
		return iParam->second;
}

string NewBrokerOrderStatusRequest::toString()
{
	stringstream sRequest;
	sRequest << UBACData::Protocol_ORDER_STATUS << " <" << (*this) << ">";
	return sRequest.str();
}
