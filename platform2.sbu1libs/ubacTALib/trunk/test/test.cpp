#include <vector>
#include <map>
#include <string>
#include <jsonparser/JsonParser.h>
#include <time.h>

#include "HistoryPrice.h"
//#include "TAEngine.h"

using namespace std;
using namespace UBACTA;

/*
vector<HistoryPrice> getHistoryPrice()
{

	vector<HistoryPrice> historyDatas;

	for(size_t i = 0; i < 30; i++) {
		HistoryPrice h;

		//h.setSymbol("GOOG");
		h.setOpen(rand() % 1000 + 1000);
		h.setHigh(rand() % 1000 + 1000);
		h.setLow(rand() % 1000 + 1000);
		h.setClose(rand() % 1000 + 1000);
		h.setVolume(rand() % 1000 + 1000);

		time_t now = time(0);
		struct tm * ts = localtime(&now);
		h.setDate( *ts );

		historyDatas.push_back(h);

	}

	return  historyDatas;

}

*/
int main()
{

	multimap<string, string> indicatorMap;

	//indicatorMap.insert( make_pair("EMA", "10"));
	indicatorMap.insert( make_pair("VEMA", "20"));

	JsonObject jIndicatorObject;
	jIndicatorObject.iObjectType = JsonObject::JsonObject_ARRAY;

    HistoryPrice v;

	//TAEngine ta;
	//vector<UBACTA::HistoryPrice> v;
//	vector<HistoryPrice> v = getHistoryPrice();
//	ta.process(indicatorMap, v, jIndicatorObject);

//	cout << jIndicatorObject.toString() << endl;

}

