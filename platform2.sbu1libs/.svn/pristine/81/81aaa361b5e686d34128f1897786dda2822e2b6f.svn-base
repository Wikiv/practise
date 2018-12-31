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
	testMemCache = new MemCache( "localhost" ,11211);
	//bool status = testMemCache->setCache( "cpair" , "Tested", 1 );
    //cout << "status = " <<  status << endl;
	//cout << "Memcache updated " << endl;
	string value;
	testMemCache->getCache( "cx_pair", value );
	//testMemCache->getCache( "EUR/AUD", value );
	cout << "value retrieved from memcache= " << value << endl;

    struct custom_quote_packet packet;
    memset(&packet, '\0', sizeof(struct custom_quote_packet));

    char *quotedata = NULL;
    size_t quotelen = 0;
    cout << "got = " << testMemCache->getCache("EUR/AUD", quotedata, quotelen);
    cout << "quotelen = " << quotelen << endl;

    memcpy(&packet, quotedata, quotelen);
    cout << "symbol " << packet.symbol << endl;

    cout << "got = " << testMemCache->getCache("EU", quotedata, quotelen) << endl;
	struct foo tmp_foo;
	memset(&tmp_foo, '\0', sizeof(struct foo));
	strcpy(tmp_foo.c_data, "hiran");
	tmp_foo.d = 22.0/7.0;
	tmp_foo.i = 123456789;

	testMemCache->setCache("bin_data", (void *)&tmp_foo, sizeof(struct foo));
	memset(&tmp_foo, '\0', sizeof(struct foo));

	size_t len = 0;
	char *c_data = NULL;
	testMemCache->getCache("bin_data", c_data, len);
	cout << len << endl;
	memcpy(&tmp_foo, c_data, len);
	free(c_data);

	cout << tmp_foo.c_data << endl;
	cout << tmp_foo.d << endl;
	cout << tmp_foo.i << endl;
	delete testMemCache;
}
