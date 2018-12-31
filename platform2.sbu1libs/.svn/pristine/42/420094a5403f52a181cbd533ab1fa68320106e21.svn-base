#include "UBACData.h"

BrokerLogoutResponse::BrokerLogoutResponse()
{
}

BrokerLogoutResponse::~BrokerLogoutResponse()
{
}

void BrokerLogoutResponse::toString(string & response)
{
        if ( customMessage.length() > 0 ) {
                response.append( "446 <" );                                
                response.append( customMessage );
                response.append( ">" );
        } else                        
	        response.append("446 <Logged Out>");
}

void BrokerLogoutResponse::setCustomMessage( string mCustomMessage )
{
        customMessage.append( mCustomMessage );
}

