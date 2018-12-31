#include "UBACData.h"

BrokerSetPortfolioResponse::BrokerSetPortfolioResponse()
{
	flag=false;
}

BrokerSetPortfolioResponse::~BrokerSetPortfolioResponse()
{
}

void BrokerSetPortfolioResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

void BrokerSetPortfolioResponse::setCustomMessage( string mCustomMessage )
{
	customMessage.append( mCustomMessage );
}

void BrokerSetPortfolioResponse::toString(string & sResponse)
{
	sResponse.append("574 <");
	if ( flag ) {
		sResponse.append("SUCCESS");
	} else {
		sResponse.append("FAILED");
	}
	if ( customMessage.length() > 0 ) {
		sResponse.append("|");
		sResponse.append( customMessage );
	}
	sResponse.append(">");
}
