#include "UBACData.h"

Level3Response::Level3Response()
{
	
}

Level3Response::~Level3Response()
{

}

void Level3Response::setSymbol(string m_symbol)
{
        symbol.clear();
        symbol.append( m_symbol );
}

void Level3Response::setTotalBidQty( string m_total_bid_qty )
{
	totalBidQty.clear();
	totalBidQty.append( m_total_bid_qty );
}

void Level3Response::setTotalAskQty ( string m_total_ask_qty )
{
	totalAskQty.clear();
	totalAskQty.append( m_total_ask_qty );
}

void Level3Response::setLastUpdatedTime( int32_t m_last_updated_time, string sDateFormat )
{
	sTime.clear();
	time_t tmtime = (time_t )m_last_updated_time;
        formatTime(tmtime, sDateFormat.c_str(), sTime);
}

void Level3Response::setAskBidEntry ( int no_of_entry, struct market_depth_ask_bid_entry *ask_entry, struct market_depth_ask_bid_entry *bid_entry )
{
	askBidEntry.clear();
	stringstream ask_bid;
	for (int i = 0; ( (i < no_of_entry ) && ( i < 50 ) ); i++ ) {
		ask_bid << (bid_entry + i)->dPrice << "," << (bid_entry + i)->lQty << "," << (bid_entry + i)->fYield << "," << (bid_entry + i)->lNumber << "&" << (ask_entry + i)->dPrice << "," << (ask_entry + i)->lQty << "," << (ask_entry + i)->fYield << "," << (ask_entry + i)->lNumber << ";";	
	}
	askBidEntry.append( ask_bid.str() );
	rstrip( askBidEntry, ';');
}

void Level3Response::toString(string &response)
{
	char c_response[1024] = {'\0'};
	if (totalBidQty.length() == 0 ) totalBidQty.append("0");
	if (totalAskQty.length() == 0 ) totalAskQty.append("0");

	sprintf(c_response, "316 <%s|%s|%s|%s|%s>", symbol.c_str(), askBidEntry.c_str(), totalBidQty.c_str(), totalAskQty.c_str(), sTime.c_str());
	
	response.append(c_response, strlen(c_response));
}
