#include <iostream>

#include "IFHelper.h"

using namespace std;

int findSpace(const char * ptr, size_t rIndex)
{
    while(rIndex >= 0) {

        if (0x20 != ptr[rIndex])
            return rIndex;
        rIndex--;
    }

    return 0;
}

int main()
{
    double d = -1002.234;

    string value;

    IFHelper ifHelper;

    ifHelper.formatDouble(d, value, 2);

    cout << value << endl;

    value = "-123.234";
    ifHelper.formatFloatWithComma(value);
    cout << value << endl;
    cout << value.length() << endl;

    value = "12123.234";
    ifHelper.formatFloatWithComma(value);
    cout << value << endl;
    cout << value.length() << endl;

    value = "+12123.234";
    ifHelper.formatFloatWithComma(value);
    cout << value << endl;
    cout << value.length() << endl;

    value = "";
    ifHelper.formatFloatWithComma(value);
    cout << value << endl;

    value = "content contain's this's. what to do";
    ifHelper.substitute(value, "'", "\\'");
    cout << value << endl;

    time_t t;

    ifHelper.parseTime("12 March 2014 16:51:41", "%d %B %Y %H:%M:%S", &t);
    cout << t << endl;
    
    value.clear();
    ifHelper.currentTime("%d %B %Y", value);
    cout << value << endl;

    ifHelper.parseTime("16:51:41", "%H:%M:%S", &t);
    cout << t << endl;
}

