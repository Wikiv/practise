#include "QuotePacketUtils.h"

void QuotePacketUtils::convert_proxy_to_push(struct proxy_quote_packet_t
		*proxy_quote, struct quote_packet_t *push_quote)
{
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
    sOI<<std::fixed;
    sOI.precision(0);
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

	dataJsonObject["spotPrc"] = JsonObject( helper.formatDouble(proxy_quote->dSpotPrice, proxy_quote->precision));
	dataJsonObject["futPrc"] = JsonObject( helper.formatDouble(proxy_quote->dFutPrice, proxy_quote->precision));
	dataJsonObject["premDsc"] = JsonObject( helper.formatDouble(proxy_quote->dPremiumDiscount, proxy_quote->precision));
	level1JsonObject["data"] = dataJsonObject;

	return level1JsonObject;
}
