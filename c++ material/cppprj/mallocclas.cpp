#include<iostream>
#include<string.h>
using namespace std;
class  Test
{
public:
    string c1;
    
    /*    Test()
    {
       strcpy(t2,c1);
       cout<<"t2-"<<t2;
    }
    ~Test()
    {
        cout  <<  "Test 2";
    }*/
    char cpy(Test*t2,string c1)
    {
       strcpy(t2,c1);
       cout<<"t2-"<<t2;
    }
    //char cnt(string c1);
};

int  main()
{
   
  Test*  t2  =  (Test*)  malloc(sizeof  (Test));
  cout<<"enter the char"<<endl;
  string c;
  cin>>c;
  t2->cpy(t2,c);
  cout<<"enter the string to con"<<endl;
  cin>>c;
  //cnt(c);
  free(t2);

  return  0;
}