#include "UBACData.h"

GetBrokerWatchlistRequest::GetBrokerWatchlistRequest(string data)
{
	parse( data );
}

GetBrokerWatchlistRequest::~GetBrokerWatchlistRequest()
{
}

void GetBrokerWatchlistRequest::parse( string request )
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

void GetBrokerWatchlistRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "ACCOUNTID" ) == 0 ) {
		accountID.append( value );
	}
}

string GetBrokerWatchlistRequest::getAccountID()
{
	return accountID;
}
