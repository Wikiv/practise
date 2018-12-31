#include "UBACData.h"

BrokerWatchlistDataActionResponse::BrokerWatchlistDataActionResponse()
{
}

BrokerWatchlistDataActionResponse::~BrokerWatchlistDataActionResponse()
{
}

void BrokerWatchlistDataActionResponse::setCustomMessage( string mCustomMessage )
{
	customMessage.append( mCustomMessage );
}

void BrokerWatchlistDataActionResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

void BrokerWatchlistDataActionResponse::toString( string & response )
{
	response.append( "418 <" );
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
