#include "UBACData.h"

BrokerNewOptionChainResponse::BrokerNewOptionChainResponse()
{
}

BrokerNewOptionChainResponse::~BrokerNewOptionChainResponse()
{
}

void BrokerNewOptionChainResponse::toString(string & sResponse)
{
	sResponse.append( "558 <" );
	CSVData *ptr = static_cast<CSVData *>(this);
	ptr->toString( sResponse, '|' );
	sResponse.append( ">" );
}
