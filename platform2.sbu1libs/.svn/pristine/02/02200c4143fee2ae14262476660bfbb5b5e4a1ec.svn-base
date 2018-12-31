#include "UBACData.h"

BrokerCancelOrderResponse::BrokerCancelOrderResponse()
{
}

BrokerCancelOrderResponse::~BrokerCancelOrderResponse()
{
}

void BrokerCancelOrderResponse::setOrderId( string mOrderID )
{
	orderId.append( mOrderID );
}

void BrokerCancelOrderResponse::setMessage( string mMessage )
{
	message.append( mMessage );
}

void BrokerCancelOrderResponse::setStatus( bool mStatus )
{
	status = mStatus;
}

bool BrokerCancelOrderResponse::getStatus()
{
	return status;
}

void BrokerCancelOrderResponse::toString(string & response)
{
	response.append("546 <");
	response.append(orderId);
	( status ) ? response.append("|OK|") : response.append("|FAIL|");
	response.append( message );
	response.append(">");
}
