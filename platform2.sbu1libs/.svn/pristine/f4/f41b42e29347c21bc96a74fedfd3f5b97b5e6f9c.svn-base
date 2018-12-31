#include "UBACData.h"

GetBrokerWatchlistResponse::GetBrokerWatchlistResponse()
{
}

GetBrokerWatchlistResponse::~GetBrokerWatchlistResponse()
{
}

void GetBrokerWatchlistResponse::toString( string & response )
{
	response.append( "406 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
