#include "UBACData.h"

MarketDepthResponse::MarketDepthResponse()
{
	
}

MarketDepthResponse::~MarketDepthResponse()
{

}

void MarketDepthResponse::setSymbol(string m_symbol)
{
        symbol.clear();
        symbol.append( m_symbol );
}

void MarketDepthResponse::setTotalBidQty( string m_total_bid_qty )
{
	totalBidQty.clear();
	totalBidQty.append( m_total_bid_qty );
}

void MarketDepthResponse::setTotalAskQty ( string m_total_ask_qty )
{
	totalAskQty.clear();
	totalAskQty.append( m_total_ask_qty );
}

void MarketDepthResponse::setAskBidEntry ( int no_of_entry, struct market_depth_ask_bid_entry *ask_entry, struct market_depth_ask_bid_entry *bid_entry )
{
	askBidEntry.clear();
	stringstream ask_bid;
	for (int i = 0; ( (i < no_of_entry ) && ( i < 50 ) ); i++ ) {
		ask_bid << (bid_entry + i)->dPrice << "," << (bid_entry + i)->lQty << "," << (bid_entry + i)->lNumber << "," << (ask_entry + i)->dPrice << "," << (ask_entry + i)->lQty << "," << (ask_entry + i)->lNumber << ";";
	}
	askBidEntry.append( ask_bid.str() );
	rstrip( askBidEntry, ';');
}

void MarketDepthResponse::toString(string &response)
{
	char c_response[1024] = {'\0'};
	if (totalBidQty.length() == 0 ) totalBidQty.append("0");
	if (totalAskQty.length() == 0 ) totalAskQty.append("0");

	sprintf(c_response, "314 <%s|%s|%s|%s>", symbol.c_str(), askBidEntry.c_str(), totalBidQty.c_str(), totalAskQty.c_str());
	
	response.append(c_response, strlen(c_response));
}
