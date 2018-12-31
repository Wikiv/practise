#include "UBACData.h"

CommonCsvResponse::CommonCsvResponse()
{
}

CommonCsvResponse::~CommonCsvResponse()
{
}

void CommonCsvResponse::toString( string & response )
{
	response.append( "592 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
