#include "UBACData.h"

HistoryDataRequest::HistoryDataRequest(string request)
{
	parse( request );
}

HistoryDataRequest::~HistoryDataRequest()
{
}

string HistoryDataRequest::getSymbol()
{
	return symbol;
}

string HistoryDataRequest::getResolution()
{
	return resolution;
}

string HistoryDataRequest::getStringFromDate()
{
	return from_date;
}

string HistoryDataRequest::getStringToDate()
{
	return to_date;
}

struct tm HistoryDataRequest::getFromDate()
{
	struct tm fromDate;
	parseTime( from_date.c_str(), "%Y/%m/%d", &fromDate);
	return fromDate;
}

struct tm HistoryDataRequest::getToDate()
{
	struct tm toDate;
	parseTime( to_date.c_str(), "%Y/%m/%d", &toDate);
	return toDate;
}

time_t HistoryDataRequest::getFromDateInTime_T()
{
	time_t fromDate;
	parseTime( from_date.c_str(), "%Y/%m/%d", &fromDate );
	return fromDate;
}

time_t HistoryDataRequest::getToDateInTime_T()
{
	time_t toDate;
	parseTime( to_date.c_str(), "%Y/%m/%d", &toDate);
	return toDate;
}

double HistoryDataRequest::getFromToDateDifference()
{
	string format("%Y/%m/%d");
	time_t from,to;
	parseTime( from_date, format, &from);
	parseTime( to_date, format, &to);
	double timeDiff = (double)( to - from );
	return timeDiff;
}

void HistoryDataRequest::parse(string request)
{
	int state = 0;
	string tmpBuffer;
	size_t i=0;
	for(; i < request.length(); i++) {
		if ( ( request[i] == '|' ) || ( request[i] == '-' ) || ( request[i] == ',' ) ) {
			if ( state == 0 ) {
				symbol.append( tmpBuffer );
			} else if ( state == 1 ) {
				from_date.append( tmpBuffer );
			} else if ( state == 2 ) {
				to_date.append( tmpBuffer );
			}
			state++;
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&request[i], 1);
		}
	}
	if ( ( i == request.length() ) || ( state == 3 ) )
		resolution.append( tmpBuffer );
}

void HistoryDataRequest::getRequest( string & mRequest )
{
	mRequest.append( "340 <" );
	mRequest.append( symbol );
	mRequest.append("|");
	mRequest.append( from_date );
	mRequest.append("-");
	mRequest.append( to_date );
	mRequest.append("|");
	mRequest.append( resolution );
	mRequest.append( ">" );
}

