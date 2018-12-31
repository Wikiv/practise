#include <string.h>
#include <iostream>

#include <vector>

//#include "jsonparser/JsonParser.h"

#include "JsonParser.h"
#include <ubacutils/IFHelper.h>

using namespace std;

int main()
{
    Exceptions e;

//    IFHelper ifHelper;

	string data = "{\"Message\":\"Hello\",\"StatusCode\":400,\"bool\":true,\"int\":43,\"double\":3.21, \"null\":null}";

    
    JsonParser jsonParser(data);
	JsonObject json_object = jsonParser.getJsonObject();

    JsonObject jObj = json_object;

    map<string, JsonObject> * pJson = ( map<string, JsonObject> *) & jObj;

    map<string, JsonObject> newMap  = jObj;

    map<string, JsonObject>::iterator it = newMap.begin();

    while (it != newMap.end())
    {
        string s(it->second);
        cout << s << endl;
        it++;
    }

	
	cout << ":::::::::" << json_object.toString() << endl ;
	map<string , JsonObject> j = jsonParser.getJsonObject();

	map<string,JsonObject> :: iterator iter = j.begin();


	while(iter  != j.end()){
		cout << iter->first << (JsonObject)iter->second << endl;
		iter++;
	}

    JsonBool jBool = jObj["bool"];
    //cout << "jBool" << jBool << endl;
    cout << jBool.getValue() << endl;

    exit(0);

	if ( ((vector<JsonObject>)json_object).size() > 0 ) {
		cout << "Message = " << json_object[0]["Message"] << endl;
		cout << "Status Code = " << ((JsonInt) json_object[0]["StatusCode"]).getValue() << endl;

	} 


	cout << json_object.toString() << endl;


	JsonObject jsonObject;

	jsonObject["name"] = JsonObject("hiran");

    cout << "jsonObject size" << jsonObject["name"].size() << endl;


    JsonObject jsonInt( JsonInt(2) );
    cout << "jsonint size " << jsonInt.size() << endl;

    try {
        JsonObject _t = jsonObject.getJsonObject("hello");
    } catch (Exceptions e)
    {
    }


	vector<JsonObject>list;
	list.push_back(JsonObject("1"));
	list.push_back(JsonObject("2"));
	list.push_back(JsonObject("3"));

	JsonObject innerObject;
	innerObject["key"] = (JsonObject) "value";

	list.push_back(innerObject);

	JsonObject complexObject;
	complexObject["address"] = (JsonObject)list;
	jsonObject["temp"] = (JsonObject)complexObject;
	jsonObject["temp"]["city"] = (JsonObject)"Chennai";
	jsonObject["temp"]["age"] = JsonObject(JsonInt(10));
	jsonObject["temp"]["salary"] = JsonObject(JsonDouble(1000.02));

	jsonObject["bool"] = JsonBool(false);
	int i =10;
	JsonObject inte;
	inte["123"] = (JsonObject)JsonInt(10);


	cout << "kk " << inte.toString() << endl;
	cout << jsonObject.toString() << endl;

    cout << jsonObject.size() << endl;
}

// g++ -I include/ src/* test/test_json.cpp -lyajl -lubacutils++
