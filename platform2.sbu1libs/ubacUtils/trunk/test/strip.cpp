#include <iostream>

#include <ubacutils/IFHelper.h>

using namespace std;

int main()
{
    IFHelper helper;
    string sDate = "2014:03:25";

    helper.lstrip(sDate, ':');

    cout << "sDate after strip = " << sDate << endl;


    helper.gsub(sDate, ":", "");
    cout << "sDate after gsub: " << sDate << endl;

   string symbol = "AALI                ";
    helper.rstrip(symbol, ' ');

    cout << "^" << symbol << "$" << endl;
}

