#include <map>
#include<iostream>
using namespace std;

int main ()
{
    map<int,std::string> map_1;
    /*  creates a map with keys of type character and 
      values of type integer */

    map_1[1]="one";    // inserts key = "abc" with value = 100
    map_1[2]="two";      // inserts key = "b" with value = 200
    map_1[3]="three";      // inserts key = "c" with value = 300
    map_1[4]="four";    // inserts key = "def" with value = 400
    for(std::map<int,std::string>::iterator it = map_1.begin();it != map_1.end();it++)
{
        std::cout << it->first << " " << it->second<<std::endl;
}
return 0;
}