#include "UBACData.h"

BrokerUserRegistrationRequest::BrokerUserRegistrationRequest(string data)
{
	parse(data);
}

BrokerUserRegistrationRequest::~BrokerUserRegistrationRequest()
{
}

void BrokerUserRegistrationRequest::parse(string request)
{
	size_t i;
	string tmpBuffer, name;
	for(i = 0; i < request.length(); i++) {
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

void BrokerUserRegistrationRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "USERID" ) == 0 ) {
		userid.append( value );
	} else if ( strcasecmp( name.c_str() , "PASSWORD" ) == 0 ) {
		password.append( value );
	} else if ( strcasecmp( name.c_str() , "USERNAME" ) == 0 ) {
		username.append( value );
	} else if ( strcasecmp( name.c_str() , "MOBILENUMBER" ) == 0 ) {
		mobilenumber.append( value );
	} else if ( strcasecmp( name.c_str() , "EMAIL" ) == 0 ) {
		emailid.append( value );
	} else if ( strcasecmp( name.c_str() , "CITY" ) == 0 ) {
		city.append( value );
	} else if ( strcasecmp( name.c_str() , "DOB" ) == 0 ) {
		dob.append( value );
	} else {
		upcase( name );
		otherParams.insert( make_pair( name, value) );
	}
}

string BrokerUserRegistrationRequest::getOtherParam(string mKey)
{
	string mVal("");
	upcase( mKey );
	map <string,string>::iterator iData= otherParams.find( mKey );
	if ( iData != otherParams.end() )
		mVal.append( iData->second );
	return mVal;
}

string BrokerUserRegistrationRequest::getUserID()
{
	return userid;
}

string BrokerUserRegistrationRequest::getUserName()
{
	return username;
}

string BrokerUserRegistrationRequest::getPassword()
{
	return password;
}

string BrokerUserRegistrationRequest::getMobileNumber()
{
	return mobilenumber;
}

string BrokerUserRegistrationRequest::getEmailID()
{
	return emailid;
}

string BrokerUserRegistrationRequest::getCity()
{
	return city;
}

string BrokerUserRegistrationRequest::getDOB()
{
	return dob;
}
