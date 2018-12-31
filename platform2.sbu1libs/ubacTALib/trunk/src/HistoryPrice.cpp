#include "HistoryPrice.h"

using namespace UBACTA;

HistoryPrice::HistoryPrice()
{
}

HistoryPrice::~HistoryPrice()
{
}

void HistoryPrice::setOpen(string mOpen)
{
	open.clear();
	open.append( mOpen );
}

void HistoryPrice::setHigh(string mHigh)
{
	high.clear();
	high.append( mHigh );
}

void HistoryPrice::setLow(string mLow)
{
	low.clear();
	low.append( mLow );
}

void HistoryPrice::setClose(string mClose)
{
	close.clear();
	close.append( mClose );
}

void HistoryPrice::setVolume(string mVolume)
{
	volume.clear();
	volume.append( mVolume );
}

void HistoryPrice::setOpen(double mOpen)
{
	open = ifHelper.formatDouble( mOpen, 2 );
}

void HistoryPrice::setHigh(double mHigh)
{
	high = ifHelper.formatDouble( mHigh, 2 );
}

void HistoryPrice::setLow(double mLow)
{
	low = ifHelper.formatDouble( mLow, 2);
}

void HistoryPrice::setClose(double mClose)
{
	close = ifHelper.formatDouble( mClose, 2);
}

void HistoryPrice::setOpen(double mOpen, int precision)
{
	open = ifHelper.formatDouble( mOpen, precision );
}

void HistoryPrice::setHigh(double mHigh, int precision)
{
	high = ifHelper.formatDouble( mHigh, precision );
}

void HistoryPrice::setLow(double mLow, int precision)
{
	low = ifHelper.formatDouble( mLow, precision);
}

void HistoryPrice::setClose(double mClose, int precision)
{
	close = ifHelper.formatDouble( mClose, precision);
}

void HistoryPrice::setVolume(uint32_t mVolume)
{
	stringstream tmp;
	tmp << mVolume;
	volume = tmp.str();
}

void HistoryPrice::setDate(time_t timestamp)
{
    this->timestamp = timestamp;
	//memcpy(&timestamp, &mTimestamp, sizeof(struct tm));
}

double HistoryPrice::getOpen()
{
	return atof(open.c_str());
}

double HistoryPrice::getHigh()
{
	return atof(high.c_str());
}

double HistoryPrice::getLow()
{
	return atof(low.c_str());
}

double HistoryPrice::getClose()
{
	return atof(close.c_str());
}

uint32_t HistoryPrice::getVolume()
{
	return atoi(volume.c_str());
}

time_t HistoryPrice::getTime()
{
	return timestamp;
}
