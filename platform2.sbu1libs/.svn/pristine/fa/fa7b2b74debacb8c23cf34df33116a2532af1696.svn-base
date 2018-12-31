#include "UBACData.h"

ValidateUserResponse::ValidateUserResponse()
{
}

ValidateUserResponse::~ValidateUserResponse()
{
}

void ValidateUserResponse::toString( string & response )
{
	response.append( "580 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
