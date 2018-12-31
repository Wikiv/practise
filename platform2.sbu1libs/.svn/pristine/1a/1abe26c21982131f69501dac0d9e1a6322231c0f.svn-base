#include <ubacutils/IFHelper.h>


using namespace std;

string convertCurrentTimetoGMTtime()
{
    IFHelper helper;
    time_t tGmt = helper.getGMTime();
    cout << "GMT time = " << tGmt << endl;
    
    string sGMTTime;
    helper.formatTime(tGmt, "%Y-%m-%dT%T", sGMTTime);
    return sGMTTime;

}

int main()
{

    cout << convertCurrentTimetoGMTtime() << endl;
    cout << "Current time = " << time(NULL) << endl;

}
