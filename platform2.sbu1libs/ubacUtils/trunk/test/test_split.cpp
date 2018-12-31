#include <vector>
#include <string>
#include "IFHelper.h"

using namespace std;

int main(int argc, char * argv[])
{
	IFHelper i;

	string s(argv[1]);
    string d(argv[2]);

    string input = s;
//    i.readFile(s, input); 

	vector<string> res;
	i.split(input, d, res);

   // exit(0);

    vector<string>::iterator it = res.begin();
    for(; it != res.end(); it++)
        cout << *it << endl;
}
