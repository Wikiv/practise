#include "UBACData.h"

AcceptDisclaimerResponse::AcceptDisclaimerResponse()
{
}

AcceptDisclaimerResponse::~AcceptDisclaimerResponse()
{
}

void AcceptDisclaimerResponse::setCustomMessage( string mCustomMessage )
{
	customMessage.append( mCustomMessage );
}

void AcceptDisclaimerResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

void AcceptDisclaimerResponse::toString( string & response )
{
	response.append( "494 <" );
	if ( flag ) {
		response.append("SUCCESS");
	} else {
		response.append("FAILED");
	}
	if ( customMessage.length() > 0 ) {
		response.append( "|" );
		response.append( customMessage );
	}
	response.append( ">" );
}
