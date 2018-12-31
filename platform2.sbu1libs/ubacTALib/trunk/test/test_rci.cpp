#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <time.h>
#include <ubacta/TAEngine.h>


using namespace std;
using namespace UBACTA;


int main()
{

    double dInputPrices[10] = {2,4,5,4,4,3,6,8,1,3};
    time_t dTime[10] = {1,2,3,4,5,6,7,8,9,10};

    int inputLength = 10; 

    map <string, vector<double> > vOutputmap;

    TAEngine engine;
    engine.rci(dInputPrices, dTime, inputLength, 3, vOutputmap);

    vector<double> output = vOutputmap["RCI"];
    for(vector<double>::iterator itr = output.begin(); itr!=output.end(); itr++) {
        cout << *itr << endl;

    }

}
