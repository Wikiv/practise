#include "UBACData.h"

SingleQuoteRequest::SingleQuoteRequest(string data)
{
	this->append(data);
	symbol.append(data);
}

SingleQuoteRequest::~SingleQuoteRequest()
{
}

string SingleQuoteRequest::getSymbol()
{
	return symbol;
}

string SingleQuoteRequest::toString()
{
	string s = "310 <";
	s = s + (*this) + ">";
	return s;
}
