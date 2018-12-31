#include <string.h>
#include <iostream>

#include <vector>

//#include "jsonparser/JsonParser.h"
#include "JsonParser.h"
#include "limits.h"

using namespace std;

int main()
{

    JsonObject sub;

    sub["name"] = (string) "kathi";
    sub["age"] = (string) "25";



    exit(0);

    vector<JsonObject> pointObj;

    pointObj.push_back(JsonObject(JsonInt(1)));
    pointObj.push_back(JsonObject(JsonInt(2)));
    pointObj.push_back(JsonObject(JsonInt(3)));

    sub["points"] = pointObj;

    JsonObject jsonObject;
    jsonObject.iObjectType = JsonObject::JsonObject_ARRAY;

	vector<JsonObject> * list  = & jsonObject;

	list->push_back(sub);
    
    pointObj.push_back(JsonObject(JsonInt(4)));
    sub["points"] = pointObj;

	list->push_back(sub);

    pointObj.push_back(JsonObject(JsonInt(5)));
    sub["points"] = pointObj;

	list->push_back(sub);

	cout << jsonObject.toString() << endl;

    vector<JsonObject>::iterator it = list->begin();

    size_t nLows = USHRT_MAX;
    while (it != list->end() ) 
    {
        vector<JsonObject> * s = &  (it->operator[]("points"));
        
        nLows = nLows > s->size() ? s->size() : nLows;
        it++;
    }

    cout << "nLows " << nLows << endl;

    it = list->begin();

    while (it != list->end())
    {

        vector<JsonObject> * s = &  (it->operator[]("points"));

        size_t diff = s->size() - nLows;
        if ( diff > 0 )
        {
            s->erase(s->begin(), s->begin() + diff);
        }    

        it++;
    }

	cout << jsonObject.toString() << endl;
}

// g++ -I include/ src/JsonParser.cpp test/test_json.cpp -lyajl
