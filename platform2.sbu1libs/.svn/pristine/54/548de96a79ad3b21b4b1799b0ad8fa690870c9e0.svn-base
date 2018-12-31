#include <ubacutils/IFHelper.h>
#include "JsonParser.h"
#include <iostream>

int main()
{
    IFHelper ifHelper;

    double startTime = ifHelper.currentTime();

//    map<string, JsonObject>  obj;
    JsonObject  obj;

    cout << sizeof(obj) << endl;

    for(int i = 0; i < 1000000; i++) 
    {
        stringstream ss;
        ss << i;

        obj[ ss.str() ] = "hello";
    }

    cout << " Helper " << ifHelper.currentTime() - startTime << endl;
}
