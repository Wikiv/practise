#include "UBACData.h"

GetBrokerWatchlistSymbolsRequest::GetBrokerWatchlistSymbolsRequest(string data) : string(data)
{
	parse( data );
}

GetBrokerWatchlistSymbolsRequest::~GetBrokerWatchlistSymbolsRequest()
{
}

void GetBrokerWatchlistSymbolsRequest::parse( string request )
{
	string name, tmpBuffer;
	for ( size_t i = 0; i<request.length(); i++ ) {
		if ( ( request[i] == '|' ) || ( request.length() == i+1 ) ) {
			if ( request.length() == i+1 )
				tmpBuffer.append(&request[i],1);
			setValues( name, tmpBuffer );
			name.clear();
			tmpBuffer.clear();
		} else if ( request[i] == '=' ) {
			name.append( tmpBuffer );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&request[i],1);
		}
	}
}

void GetBrokerWatchlistSymbolsRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "ACCOUNTID" ) == 0 ) {
		accountID.append( value );
	} else if ( strcasecmp( name.c_str() , "WATCHLISTID" )  == 0 ) {
		watchlistID.append( value );
	} else if ( strcasecmp( name.c_str() , "WATCHLISTNAME" ) == 0 ) {
		watchlistName.append( value );
	} else {
		IFHelper helper;
		helper.upcase(name);
		otherParams.insert( make_pair(name, value) );
	}
}

string GetBrokerWatchlistSymbolsRequest::getAccountID()
{
	return accountID;
}

string GetBrokerWatchlistSymbolsRequest::getWatchlistID()
{
	return watchlistID;
}

string GetBrokerWatchlistSymbolsRequest::getWatchlistName()
{
	return watchlistName;
}

string GetBrokerWatchlistSymbolsRequest::getParam(string sKey)
{
	string sResult = "";
	IFHelper helper;
	helper.upcase(sKey);
	map<string, string>::iterator iOtherParam = otherParams.find( sKey );
	if( iOtherParam != otherParams.end() )
			sResult.append( iOtherParam->second );
	return sResult;
}

string GetBrokerWatchlistSymbolsRequest::toString()
{
	string s("412 <");
	s = s + (*this) + ">";
	return s;
}
