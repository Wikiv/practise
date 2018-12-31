
#include "Intraday.h"
#include "IFHelper.h"

#include "iostream"
#include "stdio.h"
#include "string"

using namespace std;
using namespace UBACINTRADAY;

int main()
{

//    Intraday intraday(5) // for five minute intraday;
//    default is one minute
    Intraday intraday;
    IFHelper ifHelper;

    for (int j = 0; ; j++) {

        QuoteData quoteData;
        quoteData.sSymbol = "hello";
        quoteData.lVolume = 12345;

        time_t t = time(NULL);

        cout << "time : " << t << endl;

        quoteData.lLastTradedTime = t ;
        quoteData.dLastTradedPrice = 123.5;

        IntradayData intradayData;

        uint8_t status = intraday.compute(quoteData, intradayData);

        if (Intraday::MINUTE_DATA == status)
        {
            // Insert minute data into database;
            cout << "Insert data into database" << endl;
            
            string sTime;

            ifHelper.formatTime(intradayData.lTime, 
                        "%Y/%m/%d %H:%M:%S", sTime);

            char c_query[1024] = {'\0'};

            sprintf(c_query, "insert into intraday (symbol, open, high, low, \
                close, volume, time) values ('%s', %f, %f, %f, %f, \
                    %d, '%s')", intradayData.sSymbol.c_str(), 
                    intradayData.dOpen, intradayData.dHigh, intradayData.dLow, 
                    intradayData.dClose, intradayData.lVolume, sTime.c_str());

            cout << "Query : " << c_query << endl;
        }

        sleep(1);
    }

}
// g++ -I include/ test/test_intraday.cpp src/Intraday.cpp src/IFHelper.cpp
