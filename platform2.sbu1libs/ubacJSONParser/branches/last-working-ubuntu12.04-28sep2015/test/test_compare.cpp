#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <vector>

#include "JsonParser.h"

//#include "ubacutils/IFHelper.h"

using namespace std;

int main()
{
    JsonObject obj;
    obj["name"] = string("kathi");

    vector<JsonObject> array;
    array.push_back(string("sridharan"));
    array.push_back(string("bharath"));

    obj["array"] = array; 

    cout << obj.toString() << endl;

    vector<JsonObject> sArray = obj["array"];

    cout << obj["name"] << endl;
    cout << "sArray : " << sArray.size() << endl;

    vector<JsonObject>::iterator it = std::find(sArray.begin(), sArray.end(), JsonObject("bharath"));

    if ( it == sArray.end() )
    {
        cout << "Not found" << endl;

    } else {

        cout << "Found " << endl;
    }
    
}
