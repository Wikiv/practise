#include <map>
#include<iostream>
#include<string>
using namespace std;

int main ()
{
//    map<int,int> m{ {1,2} , {2,3} , {3,4} };
    /* creates a map m with keys 1,2,3 and 
        their corresponding values 2,3,4 */  
    
    map<int,string> map_1; 
    /*  creates a map with keys of type character and 
      values of type integer */
    
    map_1[1]="one";    // inserts key = "abc" with value = 100
    map_1[2]="two";      // inserts key = "b" with value = 200
    map_1[3]="three";      // inserts key = "c" with value = 300
    map_1[4]="four";    // inserts key = "def" with value = 400
   // cout<<map_1[4]<<endl;
        for(map<int,string>::iterator it = map_1.begin();it != map_1.end();it++)
{
	cout << it->first << " " << it->second<<endl;
}
  //std::cout<<map->first<<endl;
    //map<char,int> map2 (map1.begin(), map1.end());
    /* creates a map map2 which have entries copied 
        from map1.begin() to map1.end() */ 
    
   // map<char,int> map3 (m);
    /* creates map map3 which is a copy of map m */
}
