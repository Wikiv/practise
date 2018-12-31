#include "UBACData.h"

GetPortfolioGroupListResponse::GetPortfolioGroupListResponse()
{
}

GetPortfolioGroupListResponse::~GetPortfolioGroupListResponse()
{
}

void GetPortfolioGroupListResponse::toString( string & response )
{
	response.append( "566 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
