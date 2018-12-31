#include "UBACData.h"

GlobalMarkets::GlobalMarkets()
{
}

GlobalMarkets::GlobalMarkets(string sResponse)
{
	parse(sResponse);
}

GlobalMarkets::~GlobalMarkets()
{
}

void GlobalMarkets::setDate(string sDate)
{
	date.append(sDate);
}

void GlobalMarkets::setIndex(string sIndex)
{
	index.append(sIndex);
}

void GlobalMarkets::setIndexName(string sIndexName)
{
	indexName.append(sIndexName);
}

void GlobalMarkets::setCountryCode(string sCountryCode)
{
	countryCode.append(sCountryCode);
}

void GlobalMarkets::setLast(string sLast)
{
	last.append(sLast);
}

void GlobalMarkets::setChange(string sChange)
{
	change.append(sChange);
}

void GlobalMarkets::setChangePercent(string sChangePercent)
{
	changePercent.append(sChangePercent);
}
/*
string GlobalMarkets::getDate()
{
	return date;
}

string GlobalMarkets::getIndex()
{
	return index;
}

string GlobalMarkets::getIndexName()
{
	return indexName;
}

string GlobalMarkets::getCountryCode()
{
	return countryCode;
}

string GlobalMarkets::getLast()
{
	return last;
} */

void GlobalMarkets::toString(string & sResponse)
{
	stringstream sRes;
	sRes << "^" << index << "|" << countryCode << "|" << indexName << "|" << last << "|" << change << "|" << changePercent << "|" << date;
	sResponse.append(sRes.str());
}

void GlobalMarkets::parse(string sResponse)
{
}

