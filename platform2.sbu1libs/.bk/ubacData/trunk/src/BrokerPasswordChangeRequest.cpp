#include "UBACData.h"

BrokerPasswordChangeRequest::BrokerPasswordChangeRequest(string data)
{
	parse(data);
}

BrokerPasswordChangeRequest::~BrokerPasswordChangeRequest()
{
}

void BrokerPasswordChangeRequest::setNameValue( string name , string value )
{
	if ( strcasecmp( name.c_str() , "requesttype" ) == 0 ) {
		requestType.append( value );
	} else if ( strcasecmp( name.c_str() , "username" ) == 0 ) {
		username.append( value );
	} else if ( strcasecmp( name.c_str() , "oldpassword" ) == 0 ) {
		oldPassword.append( value );
	} else if ( strcasecmp( name.c_str() , "newpassword" ) == 0 ) {
		newPassword.append( value );
	} else {
		IFHelper helper;
		helper.upcase(name);
		otherParams.insert( make_pair( name, value ) );
	}
}

string BrokerPasswordChangeRequest::getParam(string sKey)
{
	IFHelper helper;
	helper.upcase( sKey );
	string sValue;
	map<string, string>::iterator iValue = otherParams.find( sKey );
	if(iValue != otherParams.end())
		sValue.append( iValue->second );
	return sValue;
}

void BrokerPasswordChangeRequest::parse(string data)
{
	size_t i;
	string name,tmp_buffer = "";
	for(i = 0; i < data.length(); i++) {
		if(data[i] == '|') {
			setNameValue( name, tmp_buffer );
			name.clear();
			tmp_buffer.clear();
		} else if ( data[i] == '=' ) {
			name.append( tmp_buffer );
			tmp_buffer.clear();
		} else {
			tmp_buffer.append(&data[i], 1);
		}
	}

	if ( tmp_buffer.length() > 0 )
		setNameValue( name, tmp_buffer );
}

bool BrokerPasswordChangeRequest::isOldAndNewPasswordSame()
{
	return ( strcmp( oldPassword.c_str(), newPassword.c_str() ) == 0 );
}

string BrokerPasswordChangeRequest::getRequestType()
{
	return requestType;
}

string BrokerPasswordChangeRequest::getUsername()
{
	return username;
}

string BrokerPasswordChangeRequest::getOldPassword()
{
	return oldPassword;
}

string BrokerPasswordChangeRequest::getNewPassword()
{
	return newPassword;
}
