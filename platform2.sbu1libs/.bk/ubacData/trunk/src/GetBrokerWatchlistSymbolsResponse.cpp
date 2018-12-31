#include "UBACData.h"

GetBrokerWatchlistSymbolsResponse::GetBrokerWatchlistSymbolsResponse()
{
}

GetBrokerWatchlistSymbolsResponse::~GetBrokerWatchlistSymbolsResponse()
{
}

void GetBrokerWatchlistSymbolsResponse::toString( string & response )
{
	response.append( "414 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
