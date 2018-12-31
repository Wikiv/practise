#include "UBACData.h"

BrokerWatchlistDataActionRequest::BrokerWatchlistDataActionRequest(string data)
{
	parse( data );
}

BrokerWatchlistDataActionRequest::~BrokerWatchlistDataActionRequest()
{
}

void BrokerWatchlistDataActionRequest::parse( string request )
{
	int state = 0;
	string name, tmpBuffer;
	for ( size_t i = 0; i<request.length(); i++ ) {
		if ( ( request[i] == '|' ) || ( request.length() == i+1 ) ) {
			if ( request.length() == i+1 )
				tmpBuffer.append(&request[i],1);
			if ( state == 0 ) {
				action.append( tmpBuffer );
			} else {
				setValues( name, tmpBuffer );
			}
			name.clear();
			tmpBuffer.clear();
			state++;
		} else if ( request[i] == '=' ) {
			name.append( tmpBuffer );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&request[i],1);
		}
	}
}

void BrokerWatchlistDataActionRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "ACCOUNTID" ) == 0 ) {
		accountID.append( value );
	} else if ( strcasecmp( name.c_str() , "WATCHLISTNAME" ) == 0 ) {
		watchlistName.append( value );
	} else if ( strcasecmp( name.c_str() , "WATCHLISTID" ) == 0 ) {
		watchlistID.append( value );
	} else if ( strcasecmp( name.c_str() , "SYMBOL" ) == 0 ) {
		symbols.append( value );
	} else if ( strcasecmp( name.c_str() , "EXCH" ) == 0 ) {
		exchange.append( value );
	} else if ( strcasecmp( name.c_str() , "SECURITYWATCHLISTID" ) == 0 ) {
		securityWatchlistID.append( value );
	}
}

string BrokerWatchlistDataActionRequest::getExchange()
{
	return exchange;
}

string BrokerWatchlistDataActionRequest::getAccountID()
{
	return accountID;
}

string BrokerWatchlistDataActionRequest::getAction()
{
	return action;
}

string BrokerWatchlistDataActionRequest::getWatchlistID()
{
	return watchlistID;
}

string BrokerWatchlistDataActionRequest::getWatchlistName()
{
	return watchlistName;
}

string BrokerWatchlistDataActionRequest::getSymbols()
{
	return symbols;
}

string BrokerWatchlistDataActionRequest::getSecurityWatchlistID()
{
	return securityWatchlistID;
}
