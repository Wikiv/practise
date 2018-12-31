#include "UBACData.h"

NewPortfolio::NewPortfolio()
{
	isGainToBeCalculated = false;
}

NewPortfolio::~NewPortfolio()
{
}

void NewPortfolio::addValue( string mName, string mValue )
{
	upcase( mName );
	nameValues.insert( make_pair( mName, mValue ) );
}

void NewPortfolio::setGainCalculationFlag( bool mFlag )
{
	isGainToBeCalculated = mFlag;
}

string NewPortfolio::getValue( string mName )
{
	string mValue("");
	map < string, string >::iterator iData = nameValues.find( mName );
	if ( iData != nameValues.end() )
		mValue.append( iData->second );
	return mValue;
}

string NewPortfolio::convertToString( double mVal )
{
	string sVal;
	formatDouble( mVal, sVal, 2 );
	return sVal;
}

void NewPortfolio::calculateGainAndGainPercentage()
{
	double last,close,paid,gl,glv,dgl,dglv;
	uint32_t qty, multiplier;
	last = atof( (getValue("LAST")).c_str() );
	close = atof( (getValue("CLOSE")).c_str() );
	paid = atof( (getValue( "PAIDPRICE")).c_str() );
	qty = atoi( (getValue("QUANTITY")).c_str() );
	multiplier = atoi( (getValue("MULTIPLIER")).c_str() );
	if ( multiplier == 0 )
		multiplier = 1;
	if ( ( last > 0 ) && ( paid > 0 ) && ( qty != 0 ) ) {
		double totalMktPrice = ( last * qty * multiplier );
		addValue( "TOTALMARKETPRICE", convertToString(totalMktPrice) );
		glv = ( ( last - paid ) * qty  * multiplier );
		gl = ( ( ( last - paid ) * 100 ) / paid );
		addValue( "GAINLOSS" , convertToString(gl) );
		addValue( "GAINLOSSVALUE" , convertToString(glv) );
	} else {
		addValue( "TOTALMARKETPRICE" , "NA" );
		addValue( "GAINLOSS" , "NA" );
		addValue( "GAINLOSSVALUE" , "NA" );
	}
	if ( ( last > 0 ) && ( close > 0 ) && ( qty != 0 ) ) {
		dglv = ( ( last - close ) * qty  * multiplier );
		dgl = ( ( ( last - close ) * 100 ) / close );
		addValue( "DAILYGAINLOSS" , convertToString(dgl) );
		addValue( "DAILYGAINLOSSVALUE" , convertToString(dglv) );
	} else {
		addValue( "DAILYGAINLOSS" , "NA" );
		addValue( "DAILYGAINLOSSVALUE" , "NA" );
	}
}

void NewPortfolio::setID( int iID )
{
	string id( getValue("ID"));
	if ( id.length() == 0 ) {
		char tmpBuf[100];
		sprintf(tmpBuf, "%d", iID);
		id.append(tmpBuf, strlen(tmpBuf));
		memset(tmpBuf, '\0', sizeof(tmpBuf));
		addValue( "ID" , id );
	}
}

void NewPortfolio::toString( string & response, CSVRow cCSVRow, int iID )
{
	setID( iID );
	if(isGainToBeCalculated)
		calculateGainAndGainPercentage();
	CSVRow mCSVRow;
	vector<string>::iterator iHeader;
	for ( iHeader = cCSVRow.begin(); iHeader != cCSVRow.end(); iHeader++ ) {
		string mName( *iHeader );
		upcase( mName );
		mCSVRow.addColumn( getValue( mName ) );
	}
	mCSVRow.toString( response, ',' );
}
