#include "UBACData.h"

BrokerPlaceOrderResponse::BrokerPlaceOrderResponse()
{
	status = false;
}

BrokerPlaceOrderResponse::~BrokerPlaceOrderResponse()
{
}

void BrokerPlaceOrderResponse::setOrderID(string m_orderID)
{
	orderID.append( m_orderID );
}

string BrokerPlaceOrderResponse::getOrderID()
{
	return orderID;
}

void BrokerPlaceOrderResponse::setStatus(bool flag)
{
	status = flag;
}

bool BrokerPlaceOrderResponse::getStatus()
{
	return status;
}

void BrokerPlaceOrderResponse::setErrorMessage(string m_errorMessage)
{
	errorMessage.clear();
	errorMessage.append( m_errorMessage );
}

void BrokerPlaceOrderResponse::setCustomMessage(string m_customMessage)
{
	customMessage.clear();
	customMessage.append( m_customMessage );
}

void BrokerPlaceOrderResponse::setThirdPartyMessage( string m_thirdPartyMessage )
{
	thirdPartyMessage.clear();
	thirdPartyMessage.append( m_thirdPartyMessage );
}

void BrokerPlaceOrderResponse::toString(string & response)
{
	response.append("542 <");
	if( status ) {
		if ( customMessage.length() == 0 ) {
			customMessage.append("Order placed successfully.");
		}
	
		// Avoided appending | to custom message than in response.
		// Additional pipes will not come in response on multiple calls

		response.append(customMessage);
		if( orderID.length() > 0 ) {
			response.append("|");
			response.append( orderID );
		}

		if ( thirdPartyMessage.length() != 0 ) {
			response.append("|");
			response.append( thirdPartyMessage );
		}
	} else {
		response.append( errorMessage );
	}
	response.append(">");
}
