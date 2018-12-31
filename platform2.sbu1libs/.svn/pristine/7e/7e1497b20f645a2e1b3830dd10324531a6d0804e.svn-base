#ifndef __QUOTE_PACKET_H__
#define __QUOTE_PACKET_H__

#include <iostream>
#include <stdint.h>

/// Ask bid entry structure
struct ask_bid_entry_t {
	char dPrice[20];
	int32_t lQty;
	int32_t lNumberOfOrders;
	double dYield;
}__attribute__((packed));

/// Market depth structure
struct market_depth_t {
	int32_t iToken;
	char c_symbol[40];
	int32_t totalAskQty;
	int32_t totalBidQty;
	int16_t noOfEntries;
	struct ask_bid_entry_t ask_entry[50];
	struct ask_bid_entry_t bid_entry[50];
	int32_t lLastTradedTime;
	int16_t precision;
}__attribute__((packed));

/// Quote packet structure
struct quote_packet_t {
	int32_t iToken;
	char c_symbol[40];
	char dOpenPrice[20];
	char dHighPrice[20];
	char dLowPrice[20];
	char dLastPrice[20];
	char dClosePrice[20];
	struct ask_bid_entry_t ask_entry[5];
	struct ask_bid_entry_t bid_entry[5];
	int32_t lTotalVolume;
	int32_t lLastTradedVolume;
	char dYearHigh[20];
	char dYearLow[20];
	int32_t lOpenInterest;
	int32_t lLastTradedTime;
	int32_t lStrikePrice;
	int32_t lExpiry;
	char cOptionType;
	char c_exchange[8];
	char dChange[20];
	char dChangePercent[20];
	bool bPreOpen;
	bool bPreOpenEnded;
	bool bMarketOpen;
	char dAvgPrice[20];
	int32_t lTotalBuyQty;
	int32_t lTotalSellQty;
	char name[50];
	char c_assettype[8];
	int16_t precision;
	char dTotalTradedValue[20];
	char uLimit[20];
	char lLimit[20];
	char dSpotPrice[20];
	char dFutPrice[20];
	char dPremiumDiscount[20];
	char dPClosePrice[20];
}__attribute__((packed));

/// Ask bid entry structure for proxy
struct proxy_ask_bid_entry_t {
	double dPrice;
	int32_t lQty;
	int32_t lNumber;
	double dYield;
}__attribute__((packed));

/// Quote packet structure for proxy
struct proxy_quote_packet_t {
	int32_t iToken;
	char c_symbol[32];
	double dOpenPrice;
	double dHighPrice;
	double dLowPrice;
	double dLastPrice;
	double dClosePrice;
	struct proxy_ask_bid_entry_t ask_entry[5];
	struct proxy_ask_bid_entry_t bid_entry[5];
	uint32_t lTotalVolume;
	uint32_t lLastTradedVolume;
	double dYearHigh;
	double dYearLow;
	double lOpenInterest;
	uint32_t lLastTradedTime;
	uint32_t lStrikePrice;
	uint32_t lExpiry;
	char cOptionType;
	char c_exchange[8];
	double dChange;
	double dChangePercent;
	bool bPreOpen;
	bool bPreOpenEnded;
	bool bMarketOpen;
	double dAvgPrice;
	uint32_t lTotalBuyQty;
	uint32_t lTotalSellQty;
	char name[50];
	char c_assettype[8];
	int packet_type;
	double dTotalTradedValue;
	int16_t precision;
	double dSpotPrice;
	double dFutPrice;
	double dPremiumDiscount;
}__attribute__((packed));


#endif /* __QUOTE_PACKET_H__ */
