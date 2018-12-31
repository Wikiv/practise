#include "UBACData.h"

NewBrokerPortfolioResponse::NewBrokerPortfolioResponse()
{
}

NewBrokerPortfolioResponse::~NewBrokerPortfolioResponse()
{
}

void NewBrokerPortfolioResponse::addPortfolioEntry(NewPortfolio entry)
{
	this->push_back( entry );
}

string NewBrokerPortfolioResponse::getNetPaidValue()
{
	return netPaidValue;
}

string NewBrokerPortfolioResponse::getNetMarketValue()
{
	return netMarketValue;
}

string NewBrokerPortfolioResponse::getNetGainValue()
{
	return netGainValue;
}

string NewBrokerPortfolioResponse::getNetGainValuePer()
{
	return  netGainValuePer;
}

void NewBrokerPortfolioResponse::toString( CSVRow headers , string & response )
{
	IFHelper helper;
	vector<string>::iterator iHeaders;
	vector<NewPortfolio>::iterator i;
	string headerData, rowData;
	double paidPrice, marketPrice, dNetGainValue, dNetGainPercent;
	paidPrice = marketPrice = dNetGainValue = dNetGainPercent = (double)0;
	response.append("980 <");
	headers.toString( headerData, ',' );
	response.append( headerData );
	response.append( "|" );
	if( this->size() == 0 ) {
		netPaidValue.append("NA");
		netMarketValue.append("NA");
		netGainValue.append("NA");
		netGainValuePer.append("NA");
		helper.rstrip(response, '|');
		response.append(">");
		return;
	}
	int iID = 0;
	for(i = this->begin(); i != this->end(); i++) {
		(*i).toString( rowData, headers, iID );
		string sPaid, sMarket, sGainVal;
		sPaid.append( (*i).getValue( "TOTALPAIDPRICE" ) );
		sMarket.append( (*i).getValue( "TOTALMARKETPRICE") );
		sGainVal.append( (*i).getValue( "GAINLOSSVALUE" ) );
		paidPrice += atof( sPaid.c_str() );
		marketPrice += atof( sMarket.c_str() );
		dNetGainValue += atof( sGainVal.c_str() );
		response.append( rowData );
		response.append( "|" );
		rowData.clear();
		iID++;
	}
	dNetGainPercent = (dNetGainValue * (double)100)/paidPrice;
	CONVERT_TO_STRING(paidPrice, netPaidValue);
	CONVERT_TO_STRING(marketPrice, netMarketValue);
	CONVERT_TO_STRING(dNetGainValue, netGainValue)
	CONVERT_TO_STRING(dNetGainPercent, netGainValuePer);
	helper.rstrip(response, '|');
	response.append(">");
}
