#include "UBACData.h"

BrokerCancelOrderRequest::BrokerCancelOrderRequest(string data) : string(data)
{
	parse(data);
}

BrokerCancelOrderRequest::~BrokerCancelOrderRequest()
{
}

void BrokerCancelOrderRequest::setValue(string name, string value)
{
}

string BrokerCancelOrderRequest::getAccountID()
{
	return accountId;
}

string BrokerCancelOrderRequest::getPassword()
{
	return sPassword;
}

string BrokerCancelOrderRequest::getOrderID()
{
	return orderId;
}

string BrokerCancelOrderRequest::getSymbol()
{
	return sSymbol;
}

string BrokerCancelOrderRequest::getUsername()
{
	return sUsername;
}

string BrokerCancelOrderRequest::getSide()
{
	return sSide;
}

string BrokerCancelOrderRequest::getExchange()
{
	return sExchange;
}

string BrokerCancelOrderRequest::getInstrumentType()
{
	return sInstrumentType;
}

string BrokerCancelOrderRequest::getType()
{
	return sType;
}

string BrokerCancelOrderRequest::getParam(string sKey)
{
	for(map<string, string>::iterator iParam = otherParams.begin(); iParam != otherParams.end(); iParam++) {
		if( strcasecmp(sKey.c_str(), iParam->first.c_str()) == 0 )
			return iParam->second;
	}
	return "";
}

void BrokerCancelOrderRequest::handleOtherParams(string sName, string sValue)
{
	if( strcasecmp(sName.c_str(), "password") == 0 ) {
		sPassword.append(sValue);
	} else if( strcasecmp(sName.c_str(), "symbol") == 0 ) {
		sSymbol.append(sValue);
	} else if( strcasecmp(sName.c_str(), "marketexchange") == 0 ) {
		sExchange.append(sValue);
	} else if( strcasecmp(sName.c_str(), "instrumenttype") == 0 ) {
		sInstrumentType.append(sValue);
	} else if( strcasecmp(sName.c_str(), "type") == 0 ) {
		sType.append(sValue);
	} else if( strcasecmp(sName.c_str(), "username") == 0 ) {
		sUsername = sValue;
	} else if( strcasecmp(sName.c_str(), "action") == 0 ) {
		sSide = sValue;
	} else {
		otherParams.insert( make_pair(sName, sValue) );
	}
}

void BrokerCancelOrderRequest::parse(string data)
{
	size_t i = 0, state = 0;
	string buffer, sName;
	bool isName = true;
	for( ; i < data.length(); i++) {
		if(data[i] == '|') {
			if(state == 0) {
				orderId.append(buffer);
			} else if( state == 1 ) {
				accountId.append(buffer);
			} else {
				handleOtherParams(sName, buffer);
			}
			buffer.clear();sName.clear();
			state++;
			isName = true;
		} else if( data[i] == '=' ) {
			if( isName ) {
				sName.append(buffer);
				buffer.clear();
				isName = false;
			} else {
				buffer.append(&data[i], 1);
			}
		} else {
			buffer.append(&data[i], 1);
		}
	}
	if(state == 0) {
		orderId.append(buffer);
	} else if( state == 1 ) {
		accountId.append(buffer);
	} else {
		handleOtherParams(sName, buffer);
	}
}

string BrokerCancelOrderRequest::toString()
{
	string s = "544 <";
	s = s + (*this) + ">";
	return s;
}
