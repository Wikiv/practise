#include "SharedMemory.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int nSID, nKey, nSize;
    char *sRegionName;
    nKey = 9999;
    nSize = 1;
    SharedMemory s;
    nSID = s.initSharedMemory(nKey, nSize, true);
    cout << "Shared Memory ID :: " << nSID << endl;
    sRegionName = (char *) s.attachSharedMemory(nSID, true);
    char c;
    while(1)
    {
        cout << "Enter an input :: ";
        c=getchar();
        cout << endl;
        if(c == '\n')
        {
            c = getchar();
        }
        strncpy(sRegionName, &c, nSize);
        if(isalnum(*sRegionName))
        {
            s.detachSharedMemory(sRegionName);
            s.destroySharedMemory(nSID);
            exit(1);
        }
    }
    return 0;
}
