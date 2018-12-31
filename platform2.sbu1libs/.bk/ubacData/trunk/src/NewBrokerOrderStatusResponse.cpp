#include "UBACData.h"

NewBrokerOrderStatusResponse::NewBrokerOrderStatusResponse()
{
}

NewBrokerOrderStatusResponse::~NewBrokerOrderStatusResponse()
{
}

void NewBrokerOrderStatusResponse::toString( string & response )
{
	response.append( "950 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( response, '|' );
	response.append( ">" );
}
