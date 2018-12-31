#ifndef __QUOTE_PACKET_H__
#define __QUOTE_PACKET_H__

#include <stdint.h>

struct log_values {
	int32_t noOfClients;
	int32_t noOfBytes;
};

struct ask_bid_entry {
	char dPrice[20];
	int32_t lQty;
	int32_t lNumber;
};

struct market_depth_ask_bid_entry {
	char dPrice[20];
	int32_t lQty;
	int32_t lNumber;
	float fYield;
};

struct market_depth {
	int32_t iToken;
	char c_symbol[40];
	int32_t totalAskQty;
	int32_t totalBidQty;
/* number of ask or bid entry i.e size of the array of market_depth_ask_bid_entry structure */
	int16_t noOfEntries;
/* address of the array of ask and bid entry structure 
	struct market_depth_ask_bid_entry *ask_entry;
	struct market_depth_ask_bid_entry *bid_entry;
*/
	struct market_depth_ask_bid_entry ask_entry[50];
	struct market_depth_ask_bid_entry bid_entry[50];	
	int32_t lLastTradedTime;

};

struct quote_packet {
	int32_t iToken;
	char c_symbol[40];
	char dOpenPrice[20];
	char dHighPrice[20];
	char dLowPrice[20];
	char dLastPrice[20];
	char dClosePrice[20];
	struct ask_bid_entry ask_entry[5];
	struct ask_bid_entry bid_entry[5];
	int32_t lTotalVolume;
	int32_t lLastTradedVolume;
	char dYearHigh[20];
	char dYearLow[20];
	int32_t lOpenInterest;
	int32_t lLastTradedTime;
	int32_t lStrikePrice;
	int32_t lExpiry;
	char cOptionType;
	char cExchange[8];
	char dChange[20];
	char dChangePercent[20];
	bool bPreOpen;
	bool bPreOpenEnded;
	bool bMarketOpen;
	char dAvgPrice[20];
	int32_t lTotalBuyQty;
	int32_t lTotalSellQty;
	char name[50];
	char assettype[8];
	int precision;
	char dTotalTradedValue[20];
        char uLimit[20];
	char lLimit[20];
};

#endif /* __QUOTE_PACKET_H__ */
