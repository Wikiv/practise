#include "SharedMemory.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int nKey, nSize, nSID;
    nKey = 9999;
    nSize = 1;
    SharedMemory s;
    nSID = s.initSharedMemory(nKey, nSize, false);
    char *detectKey;
    detectKey = (char *)s.attachSharedMemory(nSID, false);
    char c;
    c = *detectKey;
    while(1)
    {
        if(c != *detectKey)
        {
            if(isalnum(detectKey[0]))
            {
                cout << "Key detected is :: " << detectKey << endl;
                s.detachSharedMemory(detectKey);
                s.destroySharedMemory(nSID);
                exit(1);
            }
            else
            {
                
                cout << "Key detected is :: " << detectKey << endl;
            }
            c = *detectKey;
        }
    }
    return 0;
}
