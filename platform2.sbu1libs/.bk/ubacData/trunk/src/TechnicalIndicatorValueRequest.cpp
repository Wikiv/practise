#include "UBACData.h"

TechnicalIndicatorValueRequest::TechnicalIndicatorValueRequest(string request)
{
	parse( request );
}

TechnicalIndicatorValueRequest::~TechnicalIndicatorValueRequest()
{
}

string TechnicalIndicatorValueRequest::getSymbol()
{
	return symbol;
}

string TechnicalIndicatorValueRequest::getResolution()
{
	return resolution;
}
/*
string TechnicalIndicatorValueRequest::getIndicatorCode()
{
	return indicator_code;
}

string TechnicalIndicatorValueRequest::getIndicatorInput()
{
	return indicator_input;
}
*/

multimap<string, string> TechnicalIndicatorValueRequest::getIndicators()
{
	return indicatorRequest;
}

string TechnicalIndicatorValueRequest::getStringFromDate()
{
	return from_date;
}

string TechnicalIndicatorValueRequest::getStringToDate()
{
	return to_date;
}

struct tm TechnicalIndicatorValueRequest::getFromDate()
{
	struct tm fromDate;
	memset(&fromDate, '\0', sizeof(struct tm));
	parseTime( from_date, "%Y/%m/%d", &fromDate);
	return fromDate;
}

struct tm TechnicalIndicatorValueRequest::getToDate()
{
	struct tm toDate;
	memset(&toDate, '\0', sizeof(struct tm));
	parseTime( to_date, "%Y/%m/%d", &toDate);
	return toDate;
}

double TechnicalIndicatorValueRequest::getFromToDateDifference()
{
	string format("%Y/%m/%d");
	time_t from,to;
	parseTime( from_date, format, &from);
	parseTime( to_date, format, &to);
	double timeDiff = (double)( to - from );
	return timeDiff;
}

void TechnicalIndicatorValueRequest::parse(string request)
{
	int state = 0;
	IFHelper helper;
	string tmpBuffer;
	size_t i=0;
	vector<string>sList;
	for(; i < request.length(); i++) {
		if ( ( request[i] == '|' ) /*|| ( request[i] == '-' ) */) {
			if ( state == 0 ) {
				symbol.append( tmpBuffer );
			} else if ( state == 1 ) {
				vector<string> list;
				helper.split( tmpBuffer, "-", list );
				from_date.append( list[0] );
//			} else if ( state == 2 ) {
				to_date.append( list[1] );
			} else if ( state == 2 ) {
				resolution.append( tmpBuffer );
			} else {
				sList.clear();
				if(tmpBuffer.length() > 0) {
					helper.split(tmpBuffer, ",", sList);
					string sIndicatorName, sIndicatorValue;
					sIndicatorName = *(sList.begin());
					sList.erase( sList.begin() );
					helper.join(sList, ',', sIndicatorValue);
					cout << sIndicatorName << " = " << sIndicatorValue << endl;
					indicatorRequest.insert( make_pair( sIndicatorName, sIndicatorValue ) );
				}
			}	
			state++;
			tmpBuffer.clear();
		} else if( request[i] == '>' ) {
		} else {
			tmpBuffer.append(&request[i], 1);
		}
	}
	if( state == 2 ) {
		resolution.append( tmpBuffer );
	} else if( state > 2 ) {
		sList.clear();
		if(tmpBuffer.length() > 0) {
			helper.split(tmpBuffer, ",", sList);
			string sIndicatorName, sIndicatorValue;
			sIndicatorName = sList[0];
			sList.erase( sList.begin() );
			helper.join(sList, ',', sIndicatorValue);
			cout << sIndicatorName << " = " << sIndicatorValue << endl;
			indicatorRequest.insert( make_pair( sIndicatorName, sIndicatorValue ) );
		}
	}
}

void TechnicalIndicatorValueRequest::getRequest( string & mRequest )
{
	mRequest.append( "812 <" );
	mRequest.append( symbol );
	mRequest.append("|");
	mRequest.append( from_date );
	mRequest.append("-");
	mRequest.append( to_date );
	mRequest.append("|");
	mRequest.append( resolution );
	mRequest.append("|");
	multimap<string,string>::iterator iIndicators = indicatorRequest.begin();
	if ( iIndicators != indicatorRequest.end() ) {
		mRequest.append( iIndicators->first );
		mRequest.append(",");
		mRequest.append( iIndicators->second );
		mRequest.append("|");
	}
	if( mRequest[mRequest.length() - 1] == '|' ) {
		string::iterator j = mRequest.end();
		j--;
		mRequest.erase( j );
	}
	mRequest.append( ">" );
}

