#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <time.h>
#include <ta-lib/ta_libc.h>

using namespace std;


int main()
{

    double dInputPrices[1024] = {0,0,0,0,1103.4,1115.2,1155,1135.65,1135.65,1135.65,1120,1120,1120,1120,1084.8,1100,1094.5,1108.75,1108.45,1097.6,1088.95,1000,1085,1085.2,1083.35,1054,1034.25,1037.15,1019.25,1029.35,1032.35,1027.65,1130,1029.85,1031.05,1023.65,1020,999.45};

    int outBeg = 0;
    int outNb = 0;
    int maPeriod = 37; 
    int inputLength = 38; 

    double dOutputPrices[1024 * 10];


    TA_SMA(0, inputLength - 1, dInputPrices, maPeriod, &outBeg, &outNb,
                                     dOutputPrices);
    
    cout << "outBeg : " << outBeg << endl;
    cout << "outNb : " << outNb << endl;
}
