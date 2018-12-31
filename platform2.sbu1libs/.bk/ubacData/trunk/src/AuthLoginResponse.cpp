#include "UBACData.h"

AuthLoginResponse::AuthLoginResponse()
{
}

AuthLoginResponse::~AuthLoginResponse()
{
}

void AuthLoginResponse::toString( string & response )
{
	response.append( "584 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
