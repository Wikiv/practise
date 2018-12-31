#include <vector>
#include <map>
#include <string>
#include <jsonparser/JsonParser.h>
#include <time.h>
#include <ubacutils/IFHelper.h>
#include <fstream>
#include <ubacta/HistoryPrice.h>
#include <ubacta/TAEngine.h>

using namespace std;
using namespace UBACTA;


/*vector<HistoryPrice> getHistoryPrice()
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

}*/

vector<HistoryPrice> getHistoryPriceFromCSV(string sFile)
{
	//Download the csv file from yahoo finance!
	ifstream thefile(sFile.c_str());
	string line;
	IFHelper helper;
	vector<HistoryPrice> historyDatas;
	vector<string> vValues;
	if (thefile.is_open()){ 
		HistoryPrice h;                 
		struct tm tm;
		time_t tm1;		
		string sTime;                                   
		while(getline(thefile,line)) {                          
			if (line != "Date,Open,High,Low,Close,Volume,Adj Close") {          
				helper.split(line,",",vValues);                                                     
				sTime = vValues[0];                                                                                 
				strptime(sTime.c_str(), "%H:%M:%S", &tm);
				tm1 = timegm(&tm);				
				h.setDate(tm1);                                                                                                                      
				h.setOpen(vValues[1]);                                                                                                                              
				h.setHigh(vValues[2]);                                                                                                                                              
				h.setLow(vValues[3]);                                                                                                                                                               
				h.setClose(vValues[4]);

				h.setVolume(vValues[5]);

				vValues.clear();
				sTime.clear();

				historyDatas.push_back(h);
			}                          
	} 
		thefile.close();
	}                                                  
	return  historyDatas;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		cout << "where is the csv file?" <<endl;
		exit(1);
	}

	string sFile = argv[1];
	multimap<string, string> indicatorMap;

	//indicatorMap.insert( make_pair("ROCR100", "14"));
	//inicatorMap.insert( make_pair("BOMP", "10"));
	indicatorMap.insert( make_pair("SWING", "5,2,3"));
	indicatorMap.insert( make_pair("AVGDEV", "10"));
	//indicatorMap.insert( make_pair("RSQUARE", "5,2,3"));

	JsonObject jIndicatorObject;
	jIndicatorObject.iObjectType = JsonObject::JsonObject_ARRAY;


	TAEngine ta;
	vector<UBACTA::HistoryPrice> v;
	//v = getHistoryPrice();
	
	v = getHistoryPriceFromCSV(sFile);
	ta.process(indicatorMap, v, jIndicatorObject);

	/*string name = argv[1];
	ifstream thefile(name.c_str());
	string line;
	IFHelper helper;
	vector<string> vValues;
	if( thefile.is_open() )
	{
			while( getline(thefile,line) )
			{
					if( line!="Date,Open,High,Low,Close,Volume,Adj Close" )
					{
							helper.split(line,",",vValues);
							cout<<vValues[4]<<",";
							vValues.clear();
					}
			}
			thefile.close();
	}*/

	cout << jIndicatorObject.toString() << endl;

}


