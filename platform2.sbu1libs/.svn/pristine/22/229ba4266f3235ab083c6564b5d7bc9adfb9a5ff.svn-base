#include "UBACData.h"

AuthLoginRequest::AuthLoginRequest(string data) : string(data)
{
	parse(data);
}

AuthLoginRequest::~AuthLoginRequest()
{
}

void AuthLoginRequest::parse(string data)
{
	string name, tmpBuffer;
	for ( size_t i = 0; i < data.length(); i++ ) {
		if ( ( data[i] == '|' ) || ( data.length() == i+1 ) ) {
			if ( data.length() == i+1 )
				tmpBuffer.append(&data[i],1);
			if ( name.length() > 0 )
				otherParams.insert( make_pair( name , tmpBuffer ) );
			name.clear();
			tmpBuffer.clear();
		} else if ( data[i] == '=' ) {
			name.append( tmpBuffer );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&data[i],1);
		}
	}
}

string AuthLoginRequest::getOtherParams( string name )
{
	string value;
	map<string, string>::iterator iOtherParams;
	for( iOtherParams = otherParams.begin(); iOtherParams != otherParams.end(); iOtherParams++ ) {
		string nameInReq( iOtherParams->first );
		if ( strcasecmp( nameInReq.c_str(), name.c_str() ) == 0 ) {
			value.append( iOtherParams->second );
			break;
		}
	}
	return value;
}

string AuthLoginRequest::toString()
{
	string s = "582 <";
	s = s + (*this) + ">";
	return s;
}
