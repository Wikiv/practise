#include "UBACData.h"

HistoryDataResponse::HistoryDataResponse()
{
}

HistoryDataResponse::HistoryDataResponse(string sData)
{
	parse( sData );
}

HistoryDataResponse::~HistoryDataResponse()
{
}

void HistoryDataResponse::addHistoryData(HistoryData histData)
{
	dataList.push_back( histData );
}

void HistoryDataResponse::clearHistoryData()
{
	dataList.clear();
}

void HistoryDataResponse::toString( string & response )
{
	vector<HistoryData>::iterator i;
	bool symbolAdded = false;
	response.append( "342 <" );
	for(i = dataList.begin(); i != dataList.end(); i++) {
		string buffer;
		(*i).toString( buffer, symbolAdded , false );
		symbolAdded = true;
		response.append( buffer );
		response.append("&");
	}
	IFHelper helper;
	helper.rstrip( response , '&' );
	response.append( ">" );
}

void HistoryDataResponse::toString( string & response , string url )
{
	response.append( "342 <" );
	response.append(url);
	response.append(">");
}

size_t HistoryDataResponse::getNoOfElements()
{
	return dataList.size();
}

vector<HistoryData> HistoryDataResponse::getHistoryData()
{
	return dataList;
}

void HistoryDataResponse::handle_state(string sBuffer, int state)
{
	cout << dataList.size() << ", " << state << ", " << sBuffer << endl;
	HistoryData histData;
	vector<HistoryData>::iterator iHist = dataList.end();
	iHist--;
	histData = *iHist;
	dataList.erase( iHist );


	if( state == 0 ) {
		histData.setSymbol( sBuffer );
	} else if( state == 1 ) {
		histData.setOpen( sBuffer );
	} else if( state == 2 ) {
		histData.setHigh( sBuffer );
	} else if( state == 3 ) {
		histData.setLow( sBuffer );
	} else if( state == 4 ) {
		histData.setClose( sBuffer );
	} else if( state == 5 ) {
		histData.setVolume( sBuffer );
	} else if( state == 6 ) {
		IFHelper helper;
		struct tm tmTime;
		memset(&tmTime, '\0', sizeof(struct tm));
		helper.parseTime(sBuffer, "%Y/%m/%d %H:%M:%S", &tmTime);
		histData.setDate( tmTime );
	}
	dataList.push_back( histData );
}

void HistoryDataResponse::parse(string sData)
{
	if( sData.length() == 0 )
		return;
	string sBuffer;
	int state = 0;

	HistoryData tmpHistData;
	dataList.push_back( tmpHistData );
	for(size_t i = 0; i < sData.length(); i++) {
		if( sData[i] == '|' ) {
			handle_state(sBuffer, state);
			state++;
			sBuffer.clear();
		} else if( sData[i] == '&' ) {
			handle_state(sBuffer, state);
			sBuffer.clear();
			HistoryData tmpHistData;
			dataList.push_back( tmpHistData );
			state = 1;
		} else {
			sBuffer.append(&sData[i], 1);
		}
	}
	handle_state(sBuffer, state);
}
