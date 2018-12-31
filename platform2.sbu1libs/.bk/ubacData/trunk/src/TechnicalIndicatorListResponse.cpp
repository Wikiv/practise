#include "UBACData.h"

TechnicalIndicatorListResponse::TechnicalIndicatorListResponse()
{
}

TechnicalIndicatorListResponse::~TechnicalIndicatorListResponse()
{
}

void TechnicalIndicatorListResponse::addIndicator(string sIndicator)
{
	vIndicator.push_back( sIndicator );
}

void TechnicalIndicatorListResponse::toString(string & sResponse)
{
	sResponse.append("818 <");
	vector<string>::iterator iIndicator = vIndicator.begin();
	while(iIndicator != vIndicator.end()) {
		sResponse.append( *iIndicator );
		sResponse.append( "&" );
		iIndicator++;
	}
	IFHelper helper;
	helper.rstrip(sResponse, '&');
	sResponse.append(">");
}
