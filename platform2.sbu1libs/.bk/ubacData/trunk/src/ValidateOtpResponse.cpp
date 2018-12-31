#include "UBACData.h"

ValidateOtpResponse::ValidateOtpResponse()
{
}

ValidateOtpResponse::~ValidateOtpResponse()
{
}

void ValidateOtpResponse::setCustomMessage( string mCustomMessage )
{
	customMessage.append( mCustomMessage );
}

void ValidateOtpResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

void ValidateOtpResponse::toString( string & response )
{
	response.append( "450 <" );
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
