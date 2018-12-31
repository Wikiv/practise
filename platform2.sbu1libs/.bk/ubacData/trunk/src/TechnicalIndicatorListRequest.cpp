#include "UBACData.h"

TechnicalIndicatorListRequest::TechnicalIndicatorListRequest(string sRequest)
{
	this->append(sRequest);
}

TechnicalIndicatorListRequest::~TechnicalIndicatorListRequest()
{
}

string TechnicalIndicatorListRequest::getIndicatorType()
{
	return (*this);
}
