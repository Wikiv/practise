#ifndef __UBAC_INTRADAY_H__
#define __UBAC_INTRADAY_H__

#include <map>
#include <stdint.h>
#include <string>

namespace UBACINTRADAY
{
    using namespace std;

    class QuoteData
    {
        public:
            string sSymbol;
            uint64_t lVolume;
            double dLastTradedPrice;
            int32_t lLastTradedTime;

    };

    class IntradayData
    {
        public:
            string sSymbol;
            double dOpen;
            double dHigh;
            double dLow;
            double dClose;
            uint64_t lVolume;
            int32_t lTime;
    };

    class Intraday
    {
        public:
            const static uint8_t MINUTE_DATA;
            const static uint8_t DATA_CACHED;

            Intraday(uint64_t minute = 1) { this->seconds = minute * 60; };
            ~Intraday() {};

            uint8_t compute(const QuoteData &, IntradayData & );

            void clearCache();
            map<string, IntradayData> getCache();

        private:
            map<string, IntradayData> cache;

            uint64_t seconds;

    };

}

#endif /* __UBAC_INTRADAY_H__ */
