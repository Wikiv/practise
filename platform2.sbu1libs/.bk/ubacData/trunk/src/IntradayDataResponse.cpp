#include "UBACData.h"

IntradayDataResponse::IntradayDataResponse()
{
}

IntradayDataResponse::IntradayDataResponse(string sData)
{
	parse(sData);
}

IntradayDataResponse::~IntradayDataResponse()
{
}

void IntradayDataResponse::addHistoryData(HistoryData histData)
{
	dataList.push_back( histData );
}

void IntradayDataResponse::clearHistoryData()
{
	dataList.clear();
}

void IntradayDataResponse::toString(string & response)
{
	vector<HistoryData>::iterator i;
	bool symbolAdded = false;
	response.append("392 <");
	for(i = dataList.begin(); i != dataList.end(); i++) {
		string buffer;
		(*i).toString( buffer, symbolAdded , true );
		symbolAdded = true;
		response.append( buffer );
		response.append("&");
	}
	rstrip( response, '&' );
	response.append(">");
}

void IntradayDataResponse::toString(string & response,string url)
{
	response.append("392 <");
	response.append(url);
	response.append(">");
}

size_t IntradayDataResponse::getNoOfElements()
{
	return dataList.size();
}

void IntradayDataResponse::handle_state(string sBuffer, int state)
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

void IntradayDataResponse::parse(string sData)
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

vector<HistoryData> IntradayDataResponse::getHistoryData()
{
	return dataList;
}
