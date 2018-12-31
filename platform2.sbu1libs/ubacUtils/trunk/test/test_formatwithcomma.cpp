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

}

