
#include <iostream>
#include <vector>

#include "MemcacheUtils.h"

using namespace UBACMEMCACHE;
using namespace std;

struct foo {
    char c_data[40];
    double d;
    uint32_t i;
};

string stringNamespace = "string-namespace";
string structNamespace = "struct-namespace";

void fillData() 
{
    MemCache * m = new MemCache("localhost", 11211, stringNamespace);

    m->setCache("BEAV", "B/E Aerospace, Inc.");
    m->setCache("BOSC", "B.O.S. Better Online Solutions");
    m->setCache("BIDU", "Baidu, Inc.");

    delete m;

    m = new MemCache("localhost", 11211, structNamespace);

	struct foo tmp_foo;
	memset(&tmp_foo, '\0', sizeof(struct foo));
	strcpy(tmp_foo.c_data, "hiran");
	tmp_foo.d = 22.0/7.0;
	tmp_foo.i = 123456789;

    m->setCache("hiran", &tmp_foo, sizeof(tmp_foo));

	memset(&tmp_foo, '\0', sizeof(struct foo));
	strcpy(tmp_foo.c_data, "kathi");
	tmp_foo.d = 22.0;
	tmp_foo.i = 1234;

    m->setCache("kathi", &tmp_foo, sizeof(tmp_foo));

	memset(&tmp_foo, '\0', sizeof(struct foo));
	strcpy(tmp_foo.c_data, "kandhan");
	tmp_foo.d = 2.0;
	tmp_foo.i = 9;
    m->setCache("kandhan", &tmp_foo, sizeof(tmp_foo));

    delete m;
}


int main()
{

    fillData();

    MemcacheUtils * memUtils = new MemcacheUtils("localhost", 11211, structNamespace);

    vector<KeyValue *> keys = memUtils->getKeyValues();

    vector<KeyValue *>::iterator itt = keys.begin();

    while ( itt != keys.end() )
    {
        KeyValue * it = * itt;

        cout << "key -> " << (* it).key << endl;
        cout << "value Length -> " << (* it).valueLen << endl;

        struct foo f;
        memset(&f, '\0', sizeof(struct foo));
        memcpy(&f, (* it).value, (*it).valueLen);
        
        cout << "Value - 1: -> " << f.c_data << endl;
        cout << "Value - 2: -> " << f.d << endl;
        cout << "Value - 3: -> " << f.i << endl;

        // This is very important
        // Delete KeyValue after your usage
        delete it;
    
        itt++;

    }

    delete memUtils;

    memUtils = new MemcacheUtils("localhost", 11211, stringNamespace);

    keys = memUtils->getKeyValues();

    itt = keys.begin();

    while ( itt != keys.end() )
    {
        KeyValue * it = * itt;

        cout << "Key -> " << (* it).key << endl;
        cout << "Value Length -> " << (* it).valueLen << endl;

        string s( (* it).value, ( *it).valueLen);

        cout << "Value -> " << s << endl;
        
        // Delete KeyValue after your usage
        delete it;
    
        itt++;

    }

    delete memUtils;

}
