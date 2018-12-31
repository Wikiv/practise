#include "UBACData.h"

IndexRequest::IndexRequest(string request)
{
	countryCode.append( request );
}

IndexRequest::~IndexRequest()
{
}

string IndexRequest::getCountryCode()
{
	return countryCode;
}
