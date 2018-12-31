#include "UBACData.h"

BrokerOrderStatusRequest::BrokerOrderStatusRequest(string data) : string( data )
{
	parse(data);
}

BrokerOrderStatusRequest::~BrokerOrderStatusRequest()
{
}

void BrokerOrderStatusRequest::parse(string data)
{
	size_t i;
	string buffer = "", name = "";
	int state = 0;
	for(i = 0;i < data.length(); i++) {
		if( data[i] == '=' ) {
			name = buffer;
			buffer.clear();
		} else if( data[i] == '|' ) {
			if( state == 0 ) {
				accountID = buffer;
			} else {
				if( strcasecmp(name.c_str(), "type") == 0 ) {
					durationType = buffer;
				} else {
					otherParams.insert( make_pair(name, buffer) );
				}
			}
			name.clear();
			buffer.clear();
			state++;
		} else {
			buffer.append(&data[i], 1);
		}
	}
	if( state == 0 ) {
		accountID = buffer;
	} else {
		if( strcasecmp(name.c_str(), "type") == 0 ) {
			durationType = buffer;
		} else {
			otherParams.insert( make_pair(name, buffer) );
		}
	}
}

string BrokerOrderStatusRequest::getAccountID()
{
	return accountID;
}

string BrokerOrderStatusRequest::getDurationType()
{
	return durationType;
}

string BrokerOrderStatusRequest::getParam(string sKey)
{
	map<string, string>::iterator iParam = otherParams.find( sKey );
	if( iParam == otherParams.end() )
		return "";
	else
		return iParam->second;
}

string BrokerOrderStatusRequest::toString()
{
	stringstream sOrderRequest;
	sOrderRequest << UBACData::Protocol_BROKER_VIEW_ORDERS << " <" << (*this) << ">";
	return sOrderRequest.str();
}
