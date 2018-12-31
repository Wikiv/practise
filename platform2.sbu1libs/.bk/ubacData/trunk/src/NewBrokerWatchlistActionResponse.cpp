#include "UBACData.h"

BrokerWatchlistActionResponse::BrokerWatchlistActionResponse()
{
}

BrokerWatchlistActionResponse::~BrokerWatchlistActionResponse()
{
}

void BrokerWatchlistActionResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

void BrokerWatchlistActionResponse::setCustomMessage( string mCustomMessage )
{
	customMessage.append( mCustomMessage );
}

void BrokerWatchlistActionResponse::toString( string & response )
{
	response.append( "410 <" );
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
