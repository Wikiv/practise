#include <iostream>
#include <string>

#include <unistd.h>

#include "MemCache.h"

using namespace std;

struct foo {
	char c_data[40];
	double d;
	uint32_t i;
};


struct custom_quote_packet {
    char symbol[15];
    double bidPrice;
    double offerPrice;
    double highPrice;
    double lowPrice;
    double spread;
    double swapRates;
} __attribute__((packed));

int main()
{
	UBACMEMCACHE::MemCache *testMemCache;
	testMemCache = new MemCache( "localhost" ,11211 , "CX_PAIR" );

    bool b = testMemCache->setCache("name", "kathi");

    cout << b << endl;

	delete testMemCache;
}
