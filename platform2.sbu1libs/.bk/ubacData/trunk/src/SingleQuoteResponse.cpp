#include "UBACData.h"

SingleQuoteResponse::SingleQuoteResponse()
{
}

SingleQuoteResponse::SingleQuoteResponse(string data)
{
	parse(data);
}

SingleQuoteResponse::~SingleQuoteResponse()
{
}

void SingleQuoteResponse::setSymbol(string m_symbol)
{
	symbol.clear();
	symbol.append( m_symbol );
}

void SingleQuoteResponse::setLast(double m_lastPrice, int precision)
{
	lastPrice.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_lastPrice, lastPrice, precision );
	} else {
		CONVERT_TO_STRING( m_lastPrice, lastPrice );
	}
}

void SingleQuoteResponse::setLast( string mLast )
{
	lastPrice.clear();
	lastPrice.append( mLast );
}

void SingleQuoteResponse::setOpen(double m_openPrice, int precision)
{
	open.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_openPrice, open, precision );
	} else {
		CONVERT_TO_STRING( m_openPrice, open );
	}
}

void SingleQuoteResponse::setOpen( string mOpen )
{
	open.clear();
	open.append( mOpen );
}

void SingleQuoteResponse::setDayHigh(double m_dayHigh, int precision)
{
	high.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_dayHigh, high, precision );
	} else {
		CONVERT_TO_STRING( m_dayHigh, high );
	}
}

void SingleQuoteResponse::setDayHigh( string mDayHigh )
{
	high.clear();
	high.append( mDayHigh );
}

void SingleQuoteResponse::setDayLow(double m_dayLow, int precision)
{
	low.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_dayLow, low, precision );
	} else {
		CONVERT_TO_STRING( m_dayLow, low );
	}
}

void SingleQuoteResponse::setDayLow( string mDayLow )
{
	low.clear();
	low.append( mDayLow );
}

void SingleQuoteResponse::setTotalVolume(uint32_t m_volume)
{
	volume.clear();
	CONVERT_TO_STRING( m_volume, volume );
}

void SingleQuoteResponse::setTotalVolume(string m_volume )
{
	volume.clear();
	volume.append( m_volume );
}

void SingleQuoteResponse::setDate(string m_dateStr)
{
	dateStr.clear();
	dateStr.append( m_dateStr );
}

void SingleQuoteResponse::setDate(struct tm tmTime)
{
	formatTime( &tmTime, "%Y/%m/%d %H:%M:%S", dateStr );
}

void SingleQuoteResponse::setDate(time_t epoch_time)
{
	formatTime( epoch_time, "%Y/%m/%d %H:%M:%S", dateStr );
}

void SingleQuoteResponse::setAskPrice(double m_askPrice, int precision)
{
	ask.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_askPrice, ask, precision );
	} else {
		CONVERT_TO_STRING( m_askPrice, ask );
	}
}

void SingleQuoteResponse::setAskPrice(string m_ask)
{
	ask.clear();
	ask.append(m_ask);
}

void SingleQuoteResponse::setBidPrice(double m_bidPrice, int precision)
{
	bid.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_bidPrice, bid, precision );
	} else {
		CONVERT_TO_STRING( m_bidPrice, bid );
	}
}

void SingleQuoteResponse::setBidPrice(string m_bid)
{
	bid.clear();
	bid.append(m_bid);
}

void SingleQuoteResponse::setAskSize(uint32_t m_askSize)
{
	askSize.clear();
	CONVERT_TO_STRING( m_askSize, askSize );
}

void SingleQuoteResponse::setAskSize( string mAskSize )
{
	askSize.clear();
	askSize.append( mAskSize );
}

void SingleQuoteResponse::setBidSize( string mBidSize )
{
	bidSize.clear();
	bidSize.append( mBidSize );
}

void SingleQuoteResponse::setBidSize(uint32_t m_bidSize)
{
	bidSize.clear();
	CONVERT_TO_STRING( m_bidSize, bidSize );
}

void SingleQuoteResponse::setClose(double m_close, int precision)
{
	prevClose.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_close, prevClose, precision );
	} else {
		CONVERT_TO_STRING( m_close, prevClose );
	}
}

void SingleQuoteResponse::setClose( string mClose )
{
	prevClose.clear();
	prevClose.append( mClose );
}

void SingleQuoteResponse::setYearHigh(double m_yearHigh, int precision)
{
	yearHigh.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_yearHigh, yearHigh, precision );
	} else {
		CONVERT_TO_STRING( m_yearHigh, yearHigh );
	}
}

void SingleQuoteResponse::setYearHigh( string mYearHigh )
{
	yearHigh.clear();
	yearHigh.append( mYearHigh );
}

void SingleQuoteResponse::setYearLow(double m_yearLow, int precision)
{
	yearLow.clear();
	if( precision > 0 ) {
		CONVERT_DOUBLE_TO_STRING( m_yearLow, yearLow, precision );
	} else {
		CONVERT_TO_STRING( m_yearLow, yearLow );
	}
}

void SingleQuoteResponse::setYearLow( string mYearLow )
{
	yearLow.clear();
	yearLow.append( mYearLow );
}

string SingleQuoteResponse::getSymbol()
{
	return symbol;
}

string SingleQuoteResponse::getLast()
{
	return lastPrice;
}

string SingleQuoteResponse::getOpen()
{
	return open;
}

string SingleQuoteResponse::getDayHigh()
{
	return high;
}

string SingleQuoteResponse::getDayLow()
{
	return low;
}

string SingleQuoteResponse::getTotalVolume()
{
	return volume;
}

string SingleQuoteResponse::getDate()
{
	return dateStr;
}

string SingleQuoteResponse::getAskPrice()
{
	return ask;
}

string SingleQuoteResponse::getBidPrice()
{
	return bid;
}

string SingleQuoteResponse::getAskSize()
{
	return askSize;
}

string SingleQuoteResponse::getBidSize()
{
	return bidSize;
}

string SingleQuoteResponse::getClose()
{
	return prevClose;
}

string SingleQuoteResponse::getYearHigh()
{
	return yearHigh;
}

string SingleQuoteResponse::getYearLow()
{
	return yearLow;
}

void SingleQuoteResponse::toString(string &response)
{
	char c_response[1024] = {'\0'};
	if(lastPrice.length() == 0 ) lastPrice.append("%");
	if(ask.length() == 0 ) ask.append("%");
	if(bid.length() == 0 ) bid.append("%");
	if(low.length() == 0 ) low.append("%");
	if(high.length() == 0 ) high.append("%");
	if(volume.length() == 0 ) volume.append("0");
	if(askSize.length() == 0) askSize.append("%");
	if(bidSize.length() == 0) bidSize.append("%");
	if(yearHigh.length() == 0) yearHigh.append("%");
	if(yearLow.length() == 0) yearLow.append("%");
	if(prevClose.length() == 0) prevClose.append("%");
	if(open.length() == 0) open.append("%");
	if(dateStr.length() == 0) dateStr.append("%");
#ifdef _WIN32
	sprintf_s(c_response, "312 <%s|%s|%s|%s|%s|%s|%s-%s|%s|%s|%sX%s|%s|%s|%s>", symbol.c_str(), lastPrice.c_str(), open.c_str(), low.c_str(), high.c_str(), "%", yearHigh.c_str(), yearLow.c_str(), ask.c_str(), bid.c_str(), askSize.c_str(), bidSize.c_str(), prevClose.c_str(), volume.c_str(), dateStr.c_str());
#else
	sprintf(c_response, "312 <%s|%s|%s|%s|%s|%s|%s-%s|%s|%s|%sX%s|%s|%s|%s>", symbol.c_str(), lastPrice.c_str(), open.c_str(), low.c_str(), high.c_str(), "%", yearHigh.c_str(), yearLow.c_str(), ask.c_str(), bid.c_str(), askSize.c_str(), bidSize.c_str(), prevClose.c_str(), volume.c_str(), dateStr.c_str());
#endif
	response.append(c_response, strlen(c_response));
}

void SingleQuoteResponse::toStringWithDefaultZero(string &response)
{
	char c_response[1024] = {'\0'};
	if(lastPrice.length() == 0 ) lastPrice.append("0.0");
        if(ask.length() == 0 ) ask.append("0.0");
        if(bid.length() == 0 ) bid.append("0.0");
        if(low.length() == 0 ) low.append("0.0");
        if(high.length() == 0 ) high.append("0.0");
        if(volume.length() == 0 ) volume.append("0");
        if(askSize.length() == 0) askSize.append("0");
        if(bidSize.length() == 0) bidSize.append("0");
        if(yearHigh.length() == 0) yearHigh.append("0.0");
        if(yearLow.length() == 0) yearLow.append("0.0");
        if(prevClose.length() == 0) prevClose.append("0.0");
        if(open.length() == 0) open.append("0.0");
        if(dateStr.length() == 0) dateStr.append("0");
#ifdef _WIN32
	sprintf_s(c_response, "312 <%s|%s|%s|%s|%s|%s|%s-%s|%s|%s|%sX%s|%s|%s|%s>", symbol.c_str(), lastPrice.c_str(), open.c_str(), low.c_str(), high.c_str(), "0", yearHigh.c_str(), yearLow.c_str(), ask.c_str(), bid.c_str(), askSize.c_str(), bidSize.c_str(), prevClose.c_str(), volume.c_str(), dateStr.c_str());
#else
	sprintf(c_response, "312 <%s|%s|%s|%s|%s|%s|%s-%s|%s|%s|%sX%s|%s|%s|%s>", symbol.c_str(), lastPrice.c_str(), open.c_str(), low.c_str(), high.c_str(), "0", yearHigh.c_str(), yearLow.c_str(), ask.c_str(), bid.c_str(), askSize.c_str(), bidSize.c_str(), prevClose.c_str(), volume.c_str(), dateStr.c_str());
#endif
	response.append(c_response, strlen(c_response));
}

void SingleQuoteResponse::parse(string data)
{
	int state = 0;
	string tmpBuf;
	for(size_t i = 0; i < data.length(); i++) {
		if( data[i] == '|' ) {
			if( state == 0 ) {
				CONVERT_TO_STRING( tmpBuf, symbol );
			} else if( state == 1 ) {
				CONVERT_TO_STRING( tmpBuf, lastPrice );
			} else if( state == 2 ) {
				CONVERT_TO_STRING( tmpBuf, open );
			} else if( state == 3 ) {
				CONVERT_TO_STRING( tmpBuf, low );
			} else if( state == 4 ) {
				CONVERT_TO_STRING( tmpBuf, high );
			} else if( state == 5 ) {
//				CONVERT_TO_STRING( tmpBuf,  );
			} else if( state == 6 ) {
//				CONVERT_TO_STRING( tmpBuf, lastPrice );
                                vector<string> splitList;
                                IFHelper helper;
                                helper.upcase( tmpBuf );
                                helper.split( tmpBuf, "-" , splitList );
				CONVERT_TO_STRING(splitList.at(0), yearHigh );
				CONVERT_TO_STRING(splitList.at(1), yearLow );
			} else if( state == 7 ) {
				CONVERT_TO_STRING( tmpBuf, ask );
			} else if( state == 8 ) {
				CONVERT_TO_STRING( tmpBuf, bid );
			} else if( state == 9 ) {
				vector<string> splitList;
				IFHelper helper;
				helper.upcase( tmpBuf );
				helper.split( tmpBuf, "X" , splitList );
				askSize.append( splitList.at(0) );
				bidSize.append( splitList.at(1) );
			} else if( state == 10 ) {
				CONVERT_TO_STRING( tmpBuf, prevClose );
			} else if( state == 11 ) {
				CONVERT_TO_STRING( tmpBuf, volume );
			}
			state++;
			tmpBuf.clear();
		} else {
			tmpBuf.append(&data[i], 1);
		}
	}
	if( (state == 12) && (tmpBuf.length() > 0) )
		CONVERT_TO_STRING(tmpBuf, dateStr);

}

