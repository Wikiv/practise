#include "UBACData.h"

PortfolioGroupListActionResponse::PortfolioGroupListActionResponse()
{
}

PortfolioGroupListActionResponse::~PortfolioGroupListActionResponse()
{
}

void PortfolioGroupListActionResponse::setFlag( bool mFlag )
{
	flag = mFlag;
}

void PortfolioGroupListActionResponse::setCustomMessage(string mCustomMessage )
{
	customMessage.append( mCustomMessage );
}

void PortfolioGroupListActionResponse::toString( string & response )
{
	response.append( "570 <" );
	if ( flag ) {
		if ( customMessage.length() > 0 ) {
			response.append("SUCCESS");
			response.append("|");
			response.append( customMessage );
		} else {
			response.append("SUCCESS");
		}
	} else {
		if ( customMessage.length() > 0 ) {
			response.append("FAILED");
			response.append("|");
			response.append( customMessage );
		} else {
			response.append("FAILED");
		}
	}
	response.append( ">" );
}
