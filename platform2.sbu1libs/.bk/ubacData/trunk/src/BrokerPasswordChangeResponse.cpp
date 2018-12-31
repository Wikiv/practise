#include "UBACData.h"

BrokerPasswordChangeResponse::BrokerPasswordChangeResponse()
{
}

BrokerPasswordChangeResponse::~BrokerPasswordChangeResponse()
{
}

void BrokerPasswordChangeResponse::setCustomMessage( string mCustomMessage )
{
	customMessage.append( mCustomMessage );
}

void BrokerPasswordChangeResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

void BrokerPasswordChangeResponse::toString( string & response )
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
