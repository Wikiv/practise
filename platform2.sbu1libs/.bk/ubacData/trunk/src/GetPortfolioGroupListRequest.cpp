#include "UBACData.h"

GetPortfolioGroupListRequest::GetPortfolioGroupListRequest(string data)
{
	parse( data );
}

GetPortfolioGroupListRequest::~GetPortfolioGroupListRequest()
{
}

void GetPortfolioGroupListRequest::parse( string request )
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

void GetPortfolioGroupListRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "USERID" ) == 0 ) {
		userID.append( value );
	}
}

string GetPortfolioGroupListRequest::getUserID()
{
	return userID;
}
