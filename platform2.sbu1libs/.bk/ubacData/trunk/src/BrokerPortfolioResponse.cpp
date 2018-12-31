#include "UBACData.h"

BrokerPortfolioResponse::BrokerPortfolioResponse()
{
}

BrokerPortfolioResponse::~BrokerPortfolioResponse()
{
}

void BrokerPortfolioResponse::addPortfolioEntry(Portfolio entry)
{
	this->push_back( entry );
}

string BrokerPortfolioResponse::getNetPaidValue()
{
	return netPaidValue;
}

string BrokerPortfolioResponse::getNetMarketValue()
{
	return netMarketValue;
}

string BrokerPortfolioResponse::getNetGainValue()
{
	return netGainValue;
}

string BrokerPortfolioResponse::getNetGainValuePer()
{
	return  netGainValuePer;
}

void BrokerPortfolioResponse::toString( string & response )
{
	double paidPrice, marketPrice, dNetGainValue, dNetGainPercent;
	paidPrice = marketPrice = dNetGainValue = dNetGainPercent = (double)0;
	vector<Portfolio>::iterator i;
	response.append("480 <");
	if( this->size() == 0 ) {
		netPaidValue.append("NA");
		netMarketValue.append("NA");
		netGainValue.append("NA");
		netGainValuePer.append("NA");
		response.append(">");
		return;
	}
	for(i = this->begin(); i != this->end(); i++) {
		string tmpStr( (*i) );
		
		string sPaid, sMarket, sGainVal;
		UBACData::TotalMarketPrice ubacTotalMarketPrice;
		(*i).getField( ubacTotalMarketPrice );
		UBACData::TotalPaidPrice ubacTotalPaidPrice;
		(*i).getField( ubacTotalPaidPrice );
		UBACData::GainLossValue ubacGainLossValue;
		(*i).getField( ubacGainLossValue );
		paidPrice += atof( ubacTotalPaidPrice.c_str() );
		marketPrice += atof( ubacTotalMarketPrice.c_str() );
		dNetGainValue += atof( ubacGainLossValue.c_str() );
		
		response.append(tmpStr);
		response.append("&");
	}
	
	dNetGainPercent = (dNetGainValue * (double)100)/paidPrice;

	CONVERT_TO_STRING(paidPrice, netPaidValue);
	CONVERT_TO_STRING(marketPrice, netMarketValue);
	CONVERT_TO_STRING(dNetGainValue, netGainValue)
	CONVERT_TO_STRING(dNetGainPercent, netGainValuePer);

	IFHelper helper;
	helper.rstrip(response, '&');
	response.append(">");
}


void BrokerPortfolioResponse::toStringInCSVFormat( CSVRow headers , string & response )
{
	IFHelper helper;
	vector<string>::iterator iHeaders;
	vector<Portfolio>::iterator i;
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
	for(i = this->begin(); i != this->end(); i++) {
		CSVRow row;
		iHeaders = headers.begin();
		while ( iHeaders != headers.end() ) {
			string headerValue( *iHeaders );
			cout << "headerValue=" << headerValue << ", value = " << (*i).getDataField( headerValue ) << endl;
			row.addColumn ( (*i).getDataField( headerValue ) );
			iHeaders++;
		}
		
		string sPaid, sMarket, sGainVal;
		UBACData::TotalMarketPrice ubacTotalMarketPrice;
		(*i).getField( ubacTotalMarketPrice );
		UBACData::TotalPaidPrice ubacTotalPaidPrice;
		(*i).getField( ubacTotalPaidPrice );
		UBACData::GainLossValue ubacGainLossValue;
		(*i).getField( ubacGainLossValue );
		paidPrice += atof( ubacTotalPaidPrice.c_str() );
		marketPrice += atof( ubacTotalMarketPrice.c_str() );
		dNetGainValue += atof( ubacGainLossValue.c_str() );
			
		row.toString( rowData, ',' );
		response.append( rowData );
		response.append( "|" );
		rowData.clear();
	}
	dNetGainPercent = (dNetGainValue * (double)100)/paidPrice;
	CONVERT_TO_STRING(paidPrice, netPaidValue);
	CONVERT_TO_STRING(marketPrice, netMarketValue);
	CONVERT_TO_STRING(dNetGainValue, netGainValue)
	CONVERT_TO_STRING(dNetGainPercent, netGainValuePer);
	helper.rstrip(response, '|');
	response.append(">");
}
