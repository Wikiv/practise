#include "UBACData.h"

BrokerBalancesResponse::BrokerBalancesResponse()
{
}

BrokerBalancesResponse::~BrokerBalancesResponse()
{
}

void BrokerBalancesResponse::setCode(string mCode)
{
	code.append(mCode);
}

void BrokerBalancesResponse::addBalancesData(string header, string name, string value)
{
	map<string, map<string, string> >::iterator i = balancesData.find( header );
	if( i == balancesData.end() ) {
		map<string, string> nameValuePair;
		nameValuePair[name] = value;
		balancesData[header] = nameValuePair;
	} else {
		map<string, string>::iterator j = i->second.find( name );
		if( j != i->second.end() ) {
			j->second.clear();
			j->second.append( value );
		} else {
			i->second[name] = value;
		}
	}
}

void BrokerBalancesResponse::toString(string &response)
{
	map<string, map<string, string> >::iterator i;
	map<string, string>::iterator j;
	string tmpStr;
	if ( code.length() == 0 ) {
		response.append("456 <");
	} else {
		response.append( code );
		response.append( " <" );
	}
	response.append("Account ID=");
	response.append(accountID);
	response.append("&");
	for(i = balancesData.begin(); i != balancesData.end() ;i++) {
		tmpStr.append( i->first );
		tmpStr.append( ";" );
		for(j = i->second.begin(); j != i->second.end(); j++) {
			tmpStr.append( j->first );
			tmpStr.append( "=" );
			tmpStr.append( j->second );
			tmpStr.append("|");
		}
		if(tmpStr[tmpStr.length() - 1] == '|') 
			tmpStr[tmpStr.length() - 1] = '&';
		response.append(tmpStr);
		tmpStr.clear();
	}
	if( response[response.length() - 1] == '&' ) {
		string::iterator j = response.end();
		j--;
		response.erase( j );
	}
	response.append(">");
}

void BrokerBalancesResponse::setAccountID(string m_accountID)
{
	CONVERT_TO_STRING(m_accountID, accountID);
}

string BrokerBalancesResponse::getAccountID()
{
	return accountID;
}

map<string, string> BrokerBalancesResponse::getBalancesMap(string m_header)
{
	map<string, map<string, string> >::iterator iHeaderData = balancesData.find( m_header );
	return iHeaderData->second;
}

void BrokerBalancesResponse::toString(string &response, map<string, vector<string> >responseFormat, vector<string>headerOrder)
{
	string tmpStr;
	if ( code.length() == 0 ) {
		response.append("456 <");
	} else {
		response.append( code );
		response.append( "<" );
	}
	response.append("Account ID=");
	response.append(accountID);
	response.append("&");
	vector<string>::iterator iHeaderOrder;
	map<string, vector<string> >:: iterator iResponseFormat;
	vector<string>::iterator jResponseFormat;
	map<string, map<string, string> >::iterator iBalancesData;
	map<string, string>::iterator jBalancesData;
	for( iHeaderOrder = headerOrder.begin(); iHeaderOrder != headerOrder.end();) {
		cout << "Searching for header: " << (*iHeaderOrder) << endl;
		iBalancesData = balancesData.find( (*iHeaderOrder) );
		if( iBalancesData == balancesData.end() ) {
			iHeaderOrder++;
			continue;
		}
		iResponseFormat = responseFormat.find( (*iHeaderOrder) );
		if( iResponseFormat == responseFormat.end() ) {
			iHeaderOrder++;
			continue;
		}
		tmpStr.append( (*iHeaderOrder) );
		tmpStr.append( ";" );
		cout << tmpStr << endl;
		for( jResponseFormat = iResponseFormat->second.begin(); jResponseFormat != iResponseFormat->second.end();  ) {
			cout << *jResponseFormat << endl;
			jBalancesData = iBalancesData->second.find( (*jResponseFormat) );
			if( jBalancesData == iBalancesData->second.end() ) {
				jResponseFormat++;
				continue;
			}
			tmpStr.append( jBalancesData->first );tmpStr.append( "=" );tmpStr.append( jBalancesData->second );tmpStr.append("|");
			iResponseFormat->second.erase( jResponseFormat );
			iBalancesData->second.erase( jBalancesData );
		}
		for(jBalancesData = iBalancesData->second.begin(); jBalancesData != iBalancesData->second.end(); jBalancesData++) {
			tmpStr.append( jBalancesData->first );tmpStr.append( "=" );tmpStr.append( jBalancesData->second );tmpStr.append("|");
		}
		headerOrder.erase( iHeaderOrder );
		cout << tmpStr << endl;
		if(tmpStr[tmpStr.length() - 1] == '|') 
			tmpStr[tmpStr.length() - 1] = '&';
		response.append(tmpStr);
		tmpStr.clear();
	}
	/*
	for(iBalancesData = balancesData.begin(); iBalancesData != balancesData.end(); iBalancesData++) {
		tmpStr.append( iBalancesData->first );
		tmpStr.append( ";" );
		for( jBalancesData = iBalancesData->second.begin(); jBalancesData != iBalancesData->second.end(); jBalancesData++) {
			tmpStr.append( jBalancesData->first );tmpStr.append( "=" );tmpStr.append( jBalancesData->second );tmpStr.append("|");
		}
		if(tmpStr[tmpStr.length() - 1] == '|') 
			tmpStr[tmpStr.length() - 1] = '&';
		response.append(tmpStr);
		tmpStr.clear();
	}*/
	if( response[response.length() - 1] == '&' ) {
		string::iterator j = response.end();
		j--;
		response.erase( j );
	}
	response.append(">");
}
