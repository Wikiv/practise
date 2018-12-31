#include <string.h>
#include <iostream>

#include <vector>

//#include "jsonparser/JsonParser.h"
#include "JsonParser.h"

using namespace std;

int main()
{

	string data = "[{\"Message\":\"Hello\",\"StatusCode\":400,\"bool\":false,\"int\":43,\"double\":3.21, \"null\":null}]";

    
    JsonParser jsonParser(data);
	JsonObject json_object = jsonParser.getJsonObject();

//    exit(0);

	if ( ((vector<JsonObject>)json_object).size() > 0 ) {
		cout << "Message = " << json_object[0]["Message"] << endl;
		cout << "Status Code = " << ((JsonInt) json_object[0]["StatusCode"]).getValue() << endl;

	} 


	cout << json_object.toString() << endl;


	JsonObject jsonObject;

	jsonObject["name"] = JsonObject("hiran");


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
}

// g++ -I include/ src/JsonParser.cpp test/test_json.cpp -lyajl
