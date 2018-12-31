#include "QuotePacketUtils.h"

void QuotePacketUtils::convert_proxy_to_push(struct proxy_quote_packet_t
		*proxy_quote, struct quote_packet_t *push_quote)
{
}

string QuotePacketUtils::getMarketDepth(struct market_depth_t market_depth,
										ExtMod *extMod)
{
	string sResponse;
	/*
	stringstream symbol, totalbid, totalask;

	symbol << market_depth.c_symbol;
	totalbid << market_depth.totalBidQty;
	totalask << market_depth.totalAskQty;

	MarketDepthResponse marketDepthResponse;
	marketDepthResponse.setSymbol( symbol.str() );
	marketDepthResponse.setTotalBidQty( totalbid.str() );
	marketDepthResponse.setTotalAskQty( totalask.str() );
	marketDepthResponse.setAskBidEntry( market_depth.noOfEntries, &(market_depth.ask_entry[0]), &(market_depth.bid_entry[0]) );

	marketDepthResponse.toString( sResponse );
	extMod->toString( sResponse );
	*/
	return sResponse;
}

string QuotePacketUtils::getMarketDepthWithYield(struct proxy_quote_packet_t
		*proxy_quote)
{
	string sResponse;
	return sResponse;
}

string QuotePacketUtils::getLevel1Quote(struct proxy_quote_packet_t
										*proxy_quote, ExtMod *extMod)
{
	string sResponse;
	SingleQuoteResponse singleQuoteResponse;
	int precision = proxy_quote->precision;
	stringstream symbol;
	symbol << proxy_quote->c_symbol;
	singleQuoteResponse.setSymbol( symbol.str() );
	singleQuoteResponse.setOpen ( proxy_quote->dOpenPrice, precision);
	singleQuoteResponse.setDayHigh( proxy_quote->dHighPrice , precision);
	singleQuoteResponse.setDayLow( proxy_quote->dLowPrice , precision);
	singleQuoteResponse.setLast( proxy_quote->dLastPrice , precision);
	singleQuoteResponse.setAskPrice( proxy_quote->ask_entry[0].dPrice, precision );
	singleQuoteResponse.setAskSize( proxy_quote->ask_entry[0].lQty);
	singleQuoteResponse.setBidPrice( proxy_quote->bid_entry[0].dPrice, precision);
	singleQuoteResponse.setBidSize( proxy_quote->bid_entry[0].lQty);
	singleQuoteResponse.setTotalVolume( proxy_quote->lTotalVolume );
	singleQuoteResponse.setYearHigh( proxy_quote->dYearHigh, precision );
	singleQuoteResponse.setYearLow( proxy_quote->dYearLow, precision );
	singleQuoteResponse.setClose( proxy_quote->dClosePrice, precision );
	IFHelper helper;
	time_t tmtime = (time_t )proxy_quote->lLastTradedTime;
	string time;
	string dateFormat = "%Y/%m/%d %H:%M:%S";
	helper.formatTime(tmtime, dateFormat.c_str(), time);
	singleQuoteResponse.setDate(time);
	singleQuoteResponse.toStringWithDefaultZero(sResponse);

	return sResponse;
}

JsonObject QuotePacketUtils::getMarketDepth(struct market_depth_t
		*market_depth)
{
	JsonObject level2JsonObject;
	JsonObject dataJsonObject;

	IFHelper helper;

	stringstream totalAskQty, totalBidQty;
	totalBidQty << market_depth->totalBidQty;
	totalAskQty << market_depth->totalAskQty;

	dataJsonObject["symbol"] = JsonObject(string(market_depth->c_symbol));
	dataJsonObject["taq"] = JsonObject(totalAskQty.str());
	dataJsonObject["tbq"] = JsonObject(totalBidQty.str());

	string sTime;
	helper.formatTime( (time_t)market_depth->lLastTradedTime, "%d/%m/%Y %H:%M:%S",
					   sTime);
	dataJsonObject["ltt"] = sTime;

	JsonObject bidAskObject;

	for(int i = 0; i < market_depth->noOfEntries; i++) {
		stringstream sAskQty, sBidQty, sAskNumber, sBidNumber;
		sAskQty << market_depth->ask_entry[i].lQty;
		sAskNumber << market_depth->ask_entry[i].lNumberOfOrders;
		sBidQty << market_depth->bid_entry[i].lQty;
		sBidNumber << market_depth->bid_entry[i].lNumberOfOrders;

		JsonObject tempObject;
		tempObject["ask"]["price"] = JsonObject( string(
										 market_depth->ask_entry[i].dPrice) );
		tempObject["ask"]["qty"] = JsonObject( sAskQty.str() );
		tempObject["ask"]["no"] = sAskNumber.str();

		tempObject["bid"]["price"] = JsonObject( string(
										 market_depth->bid_entry[i].dPrice) );
		tempObject["bid"]["qty"] = JsonObject( sBidQty.str() );
		tempObject["bid"]["no"] = sBidNumber.str();

		bidAskObject[i] = tempObject;
	}

	dataJsonObject["level2"] = bidAskObject;
	level2JsonObject["data"] = dataJsonObject;
	return level2JsonObject;
}

JsonObject QuotePacketUtils::getLevel2Quote(struct proxy_quote_packet_t
		*proxy_quote)
{
	JsonObject level2JsonObject;
	JsonObject dataJsonObject;

	IFHelper helper;

	stringstream totalAskQty, totalBidQty;
	totalBidQty << proxy_quote->lTotalBuyQty;
	totalAskQty << proxy_quote->lTotalSellQty;

	dataJsonObject["symbol"] = JsonObject(string(proxy_quote->c_symbol));
	dataJsonObject["taq"] = JsonObject(totalAskQty.str());
	dataJsonObject["tbq"] = JsonObject(totalBidQty.str());

	string sTime;
	helper.formatTime( (time_t)proxy_quote->lLastTradedTime, "%d/%m/%Y %H:%M:%S",
					   sTime);
	dataJsonObject["ltt"] = sTime;

	vector<JsonObject> bidAskObject;

	for(int i = 0; i < 5; i++) {
		stringstream sAskQty, sBidQty, sAskNumber, sBidNumber;
		sAskQty << proxy_quote->ask_entry[i].lQty;
		sAskNumber << proxy_quote->ask_entry[i].lNumber;
		sBidQty << proxy_quote->bid_entry[i].lQty;
		sBidNumber << proxy_quote->bid_entry[i].lNumber;

		JsonObject tempObject;
		tempObject["ask"]["price"] = JsonObject( helper.formatDouble(
										 proxy_quote->ask_entry[i].dPrice, proxy_quote->precision) );
		tempObject["ask"]["qty"] = JsonObject( sAskQty.str() );
		tempObject["ask"]["no"] = sAskNumber.str();

		tempObject["bid"]["price"] = JsonObject( helper.formatDouble(
										 proxy_quote->bid_entry[i].dPrice, proxy_quote->precision) );
		tempObject["bid"]["qty"] = JsonObject( sBidQty.str() );
		tempObject["bid"]["no"] = sBidNumber.str();

		bidAskObject.push_back( tempObject );
	}

	dataJsonObject["level2"] = bidAskObject;
	level2JsonObject["data"] = dataJsonObject;
	return level2JsonObject;
}

JsonObject QuotePacketUtils::getLevel1Quote(struct proxy_quote_packet_t
		*proxy_quote)
{
	IFHelper helper;
	JsonObject level1JsonObject;
	stringstream sAskQty, sBidQty, sTotalQty, sOI;
	sAskQty << proxy_quote->ask_entry[0].lQty;
	sBidQty << proxy_quote->bid_entry[0].lQty;
	sTotalQty << proxy_quote->lTotalVolume;
	sOI << proxy_quote->lOpenInterest;

	string sTime;
	helper.formatTime((time_t)proxy_quote->lLastTradedTime, "%d/%m/%Y %H:%M:%S",
					  sTime);

	JsonObject dataJsonObject;
	dataJsonObject["symbol"] = JsonObject(string(proxy_quote->c_symbol));
	dataJsonObject["exch"] = JsonObject(string(proxy_quote->c_exchange));
	dataJsonObject["name"] = JsonObject(string(proxy_quote->name));
	dataJsonObject["asset_type"] = JsonObject(string(proxy_quote->c_assettype));
	dataJsonObject["open"] = JsonObject( helper.formatDouble(
			proxy_quote->dOpenPrice, proxy_quote->precision) );
	dataJsonObject["high"] = JsonObject( helper.formatDouble(
			proxy_quote->dHighPrice, proxy_quote->precision) );
	dataJsonObject["low"] = JsonObject( helper.formatDouble(proxy_quote->dLowPrice,
										proxy_quote->precision) );
	dataJsonObject["last"] = JsonObject( helper.formatDouble(
			proxy_quote->dLastPrice, proxy_quote->precision) );
	dataJsonObject["ask"] = JsonObject( helper.formatDouble(
											proxy_quote->ask_entry[0].dPrice, proxy_quote->precision) );
	dataJsonObject["askqty"] = JsonObject( sAskQty.str() );
	dataJsonObject["bid"] = JsonObject( helper.formatDouble(
											proxy_quote->bid_entry[0].dPrice, proxy_quote->precision) );
	dataJsonObject["bidqty"] = JsonObject( sBidQty.str() );
	dataJsonObject["yhigh"] = JsonObject( helper.formatDouble(
			proxy_quote->dYearHigh, proxy_quote->precision) );
	dataJsonObject["ylow"] = JsonObject( helper.formatDouble(proxy_quote->dYearLow,
										 proxy_quote->precision) );
	dataJsonObject["close"] = JsonObject( helper.formatDouble(
			proxy_quote->dClosePrice, proxy_quote->precision) );
	dataJsonObject["tot_vol"] = JsonObject( sTotalQty.str() );
	dataJsonObject["change"] = JsonObject( helper.formatDouble(
			proxy_quote->dChange, proxy_quote->precision) );
	dataJsonObject["p_change"] = JsonObject( helper.formatDouble(
									 proxy_quote->dChangePercent, 2) );
	dataJsonObject["oi"] = JsonObject( sOI.str() );
	dataJsonObject["ltt"] = JsonObject( sTime );

	level1JsonObject["data"] = dataJsonObject;

	return level1JsonObject;
}
