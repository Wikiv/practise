
#include "Intraday.h"
#include <string.h>

#include <iostream>
using namespace std;

using namespace UBACINTRADAY;

const uint8_t Intraday::MINUTE_DATA = 0;
const uint8_t Intraday::DATA_CACHED = 1;

uint8_t Intraday::compute(const QuoteData & quoteData, 
                            IntradayData & outputIntradayData)
{
    map<string, IntradayData>::iterator iCache = 
                        this->cache.find(quoteData.sSymbol);

    if (iCache == this->cache.end())
    {
        // Assigning values
        IntradayData intradayData;
        intradayData.sSymbol = quoteData.sSymbol;
        intradayData.dOpen = quoteData.dLastTradedPrice;
        intradayData.dHigh = quoteData.dLastTradedPrice;
        intradayData.dLow = quoteData.dLastTradedPrice;
        intradayData.dClose = quoteData.dLastTradedPrice;
        intradayData.lVolume = quoteData.lVolume;

        intradayData.lTime = quoteData.lLastTradedTime + (this->seconds 
                                - (quoteData.lLastTradedTime % this->seconds));

        this->cache.insert( make_pair(quoteData.sSymbol, intradayData));

        return DATA_CACHED;

    } else {

        uint8_t status = 255;

        IntradayData intradayData = iCache->second;
        
        struct tm newTime, oldTime;
        memset( &newTime, '\0', sizeof(struct tm));
        memset( &oldTime, '\0', sizeof(struct tm));

        localtime_r( (time_t *) & intradayData.lTime, &oldTime);

        time_t tNewTime = quoteData.lLastTradedTime + (this->seconds 
                                - (quoteData.lLastTradedTime % this->seconds));


        localtime_r(&tNewTime, &newTime);

        // If the last packet is in the same time boundary
        if (oldTime.tm_min == newTime.tm_min)
        {
            status =  DATA_CACHED;

            intradayData.dHigh = (intradayData.dHigh > quoteData.dLastTradedPrice) 
                                    ? intradayData.dHigh : quoteData.dLastTradedPrice;

            intradayData.dLow = (intradayData.dLow < quoteData.dLastTradedPrice) 
                                    ? intradayData.dLow : quoteData.dLastTradedPrice;

            intradayData.dClose = quoteData.dLastTradedPrice;

            intradayData.lVolume += quoteData.lVolume;


        } else {

            status = MINUTE_DATA;
            
            // Shallow copy is enough
            outputIntradayData = intradayData;

            intradayData.dOpen = quoteData.dLastTradedPrice;
            intradayData.dHigh = quoteData.dLastTradedPrice;
            intradayData.dLow = quoteData.dLastTradedPrice;
            intradayData.dClose = quoteData.dLastTradedPrice;
            intradayData.lVolume = quoteData.lVolume;

            intradayData.lTime = tNewTime;
        }

        this->cache.erase(iCache);
        this->cache.insert(make_pair(quoteData.sSymbol, intradayData));

        return status;
    }
}
