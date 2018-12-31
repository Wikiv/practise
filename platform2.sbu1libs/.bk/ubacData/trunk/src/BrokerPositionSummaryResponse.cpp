#include "UBACData.h"

BrokerPositionSummaryResponse::BrokerPositionSummaryResponse():BrokerBalancesResponse()
{
	setCode ( "484" );
}

BrokerPositionSummaryResponse::~BrokerPositionSummaryResponse()
{
}
