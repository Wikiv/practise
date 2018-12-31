#include "UBACData.h"

BrokerOptionsChainResponse::BrokerOptionsChainResponse()
{
}

BrokerOptionsChainResponse::~BrokerOptionsChainResponse()
{
}

void BrokerOptionsChainResponse::trimProtocolHeaderTrailer(string & response)
{
	string tmpResponse;
	size_t iterator = 0;
	bool flag = false;
	while( iterator < response.length() ) {
		if( response[iterator] == '>' ) {
			break;
		} else if( response[iterator] == '<' ) {
			flag = true;
		} else {
			if(flag)
				tmpResponse.append(&response[iterator], 1);
		}
		iterator++;
	}
	response.clear();
	response.append( tmpResponse );
}

void BrokerOptionsChainResponse::toString(string & response, string expiryFromFormat, string expiryToFormat, uint8_t limit)
{
	uint8_t uLimit = 0;
	IFHelper helper;
	string quoteResponse;
	underlyingQuote.toString( quoteResponse );
	cout << quoteResponse << endl;
	trimProtocolHeaderTrailer( quoteResponse );
	response.append("554 <");
	response.append( quoteResponse );
	response.append("|");
	map<string, vector<OptionsChain> >::iterator i;
	for(i = optionsChainList.begin(); i != optionsChainList.end(); i++) {
		time_t uExpiryTime;
		string sNewExpiry;
		helper.parseTime(i->first, expiryFromFormat, &uExpiryTime);
		helper.formatTime(uExpiryTime, expiryToFormat.c_str(), sNewExpiry);
		response.append(sNewExpiry);
		response.append("&");
		response.append("REGULAR");
		response.append("&");
		response.append( (*i->second.begin()).getNoOfDaysToExpire() );
		response.append( "&" );
		vector<OptionsChain>::iterator j;
		for(j = i->second.begin(); j != i->second.end(); j++) {
			(*j).toString( response );
		}
		if(response[response.length()-1] == '~')
			response[response.length()-1] = '|';
		uLimit++;
		if( (limit > 0) && (uLimit == limit) ) break;
	}
	if( (response[response.length()-1] == '|') || (response[response.length()-1] == '~') )
		response[response.length()-1] = '>';
}

void BrokerOptionsChainResponse::toString(string & response)
{
	string quoteResponse;
	underlyingQuote.toString( quoteResponse );
	cout << quoteResponse << endl;
	trimProtocolHeaderTrailer( quoteResponse );
	response.append("554 <");
	response.append( quoteResponse );
	response.append("|");
	map<string, vector<OptionsChain> >::iterator i;
	for(i = optionsChainList.begin(); i != optionsChainList.end(); i++) {
		response.append(i->first);
		response.append("&");
		response.append("REGULAR");
		response.append("&");
		response.append( (*i->second.begin()).getNoOfDaysToExpire() );
		response.append( "&" );
		vector<OptionsChain>::iterator j;
		for(j = i->second.begin(); j != i->second.end(); j++) {
			(*j).toString( response );
		}
		if(response[response.length()-1] == '~')
			response[response.length()-1] = '|';
	}
	if( (response[response.length()-1] == '|') || (response[response.length()-1] == '~') )
		response[response.length()-1] = '>';
}

void BrokerOptionsChainResponse::addOptionsChain(string expiryDate, OptionsChain optionsChainData)
{
	map<string, vector<OptionsChain> >::iterator i = optionsChainList.find(expiryDate);
	if(i != optionsChainList.end()) {
		i->second.push_back( optionsChainData );
	} else {
		optionsChainList[expiryDate].push_back( optionsChainData );
	}
}
