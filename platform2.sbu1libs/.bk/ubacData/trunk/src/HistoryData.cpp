#include "UBACData.h"

HistoryData::HistoryData()
{
}

HistoryData::~HistoryData()
{
}

void HistoryData::setSymbol(string mSymbol)
{
	symbol.append( mSymbol );
}

void HistoryData::setOpen(string mOpen)
{
	open.clear();
	open.append( mOpen );
}

void HistoryData::setHigh(string mHigh)
{
	high.clear();
	high.append( mHigh );
}

void HistoryData::setLow(string mLow)
{
	low.clear();
	low.append( mLow );
}

void HistoryData::setClose(string mClose)
{
	close.clear();
	close.append( mClose );
}

void HistoryData::setVolume(string mVolume)
{
	volume.clear();
	volume.append( mVolume );
}

void HistoryData::setOpen(double mOpen)
{
	open = formatDouble( mOpen, 2 );
}

void HistoryData::setHigh(double mHigh)
{
	high = formatDouble( mHigh, 2 );
}

void HistoryData::setLow(double mLow)
{
	low = formatDouble( mLow, 2);
}

void HistoryData::setClose(double mClose)
{
	close = formatDouble( mClose, 2);
}

void HistoryData::setOpen(double mOpen, int precision)
{
	open = formatDouble( mOpen, precision );
}

void HistoryData::setHigh(double mHigh, int precision)
{
	high = formatDouble( mHigh, precision );
}

void HistoryData::setLow(double mLow, int precision)
{
	low = formatDouble( mLow, precision);
}

void HistoryData::setClose(double mClose, int precision)
{
	close = formatDouble( mClose, precision);
}

void HistoryData::setVolume(uint32_t mVolume)
{
	stringstream tmp;
	tmp << mVolume;
	volume = tmp.str();
}

void HistoryData::setDate(struct tm mTimestamp)
{
	memcpy(&timestamp, &mTimestamp, sizeof(struct tm));
}

string HistoryData::getSymbol()
{
	return symbol;
}

double HistoryData::getOpen()
{
	return atof(open.c_str());
}

double HistoryData::getHigh()
{
	return atof(high.c_str());
}

double HistoryData::getLow()
{
	return atof(low.c_str());
}

double HistoryData::getClose()
{
	return atof(close.c_str());
}

uint32_t HistoryData::getVolume()
{
	return atoi(volume.c_str());
}

struct tm HistoryData::getTime()
{
	return timestamp;
}

void HistoryData::toString(string & response, bool flag , bool isIntraday )
{
	stringstream responseStream;
	char c_timeBuf[64] = {'\0'};
	if ( isIntraday ) {
		strftime(c_timeBuf, sizeof(c_timeBuf), "%Y/%m/%d %H:%M:%S", &timestamp);
	} else {
		strftime(c_timeBuf, sizeof(c_timeBuf), "%Y/%m/%d", &timestamp);
	}
	if( !flag ) responseStream << symbol << "|";
	responseStream << open << "|" << high << "|" << low << "|" << close << "|" << volume << "|" << c_timeBuf;
	response.append( responseStream.str() );
}
