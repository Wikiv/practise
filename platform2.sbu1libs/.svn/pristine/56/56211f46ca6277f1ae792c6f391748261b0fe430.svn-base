#include "UBACData.h"

BrokerWatchlistActionRequest::BrokerWatchlistActionRequest(string data)
{
	parse( data );
}

BrokerWatchlistActionRequest::~BrokerWatchlistActionRequest()
{
}

void BrokerWatchlistActionRequest::parse( string request )
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

void BrokerWatchlistActionRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "ACCOUNTID" ) == 0 ) {
		accountID.append( value );
	} else if ( strcasecmp( name.c_str() , "WATCHLISTNAME" ) == 0 ) {
		watchlistName.append( value );
	} else if ( strcasecmp( name.c_str() , "WATCHLISTID" ) == 0 ) {
		watchlistID.append( value );
	} else if ( strcasecmp( name.c_str() , "WATCHLISTNEWNAME" ) == 0 ) {
		watchlistNewName.append( value );
	} else {
		IFHelper helper;
		helper.upcase(name);
		otherParams.insert( make_pair(name, value) );
	}
}

string BrokerWatchlistActionRequest::getParam(string sKey)
{
	string sResult = "";
	IFHelper helper;
	helper.upcase(sKey);
	map<string, string>::iterator iOtherParam = otherParams.find( sKey );
	if( iOtherParam != otherParams.end() )
		sResult.append( iOtherParam->second );
	return sResult;
}

string BrokerWatchlistActionRequest::getAccountID()
{
	return accountID;
}

string BrokerWatchlistActionRequest::getAction()
{
	return action;
}

string BrokerWatchlistActionRequest::getWatchlistID()
{
	return watchlistID;
}

string BrokerWatchlistActionRequest::getWatchlistName()
{
	return watchlistName;
}

string BrokerWatchlistActionRequest::getWatchlistNewName()
{
	return watchlistNewName;
}
