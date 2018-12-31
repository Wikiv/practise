#include "UBACData.h"

BrokerUserRegistrationResponse::BrokerUserRegistrationResponse()
{
}

BrokerUserRegistrationResponse::~BrokerUserRegistrationResponse()
{
}

void BrokerUserRegistrationResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

bool BrokerUserRegistrationResponse::getFlag()
{
	return flag;
}

void BrokerUserRegistrationResponse::setErrorMessage( string mErrorMessage )
{
	errorMessage.append( mErrorMessage );
}

string BrokerUserRegistrationResponse::getErrorMessage()
{
	return errorMessage;
}

void BrokerUserRegistrationResponse::setCustomRegistrationMessage( string mCustomMessage )
{
	customMessage.clear();
	customMessage.append( mCustomMessage ) ;
}

void BrokerUserRegistrationResponse::toString(string & response)
{
	response.append("490 <");
	if ( !flag ) {
		response.append("FAIL");
		if ( errorMessage.length() > 0 ) {
			response.append("|");
			response.append( errorMessage );
		}
		response.append(">");
		return;
	}
	if ( customMessage.length() == 0 ) 
		customMessage.append( "SUCCESS" );
	response.append(customMessage);
	response.append(">");
}

