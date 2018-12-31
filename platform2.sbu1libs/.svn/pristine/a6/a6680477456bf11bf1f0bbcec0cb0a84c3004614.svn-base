#include "UBACData.h"

SymbolSearchResponse::SymbolSearchResponse()
{
}

SymbolSearchResponse::~SymbolSearchResponse()
{
}

void SymbolSearchResponse::toString( string & response )
{
	response.append( "374 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
