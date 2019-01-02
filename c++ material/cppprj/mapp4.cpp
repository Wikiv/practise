#include<iostream>
#include<string.h>
#include<map>
using namespace std;
class Emp
{
	public:
	string name;
	string workmode;
	string sal;
Emp(string n,string wm,string s)
{
	name=n;
	workmode=wm;
	sal=s;
}
const string& getworkmode() 
        {
                return workmode ;
        }
        const std::string& getname() 
        {
                return name;
        }
        const string& getsal() 
        {
                return sal;
        }
};
int main()
{       map<int,Emp>map_e;
	string na,ww,saa;
	int i;
	cin>>i>>na>>ww>>saa;
	Emp *E=new Emp(na,ww,saa);
	map_e.insert(pair<int,Emp>(i,*E));
	map<int,Emp>::iterator it =map_e.begin(); 
        for (; it != map_e.end(); it++)
                        {
                                 cout <<"ID="<< it->first<<"\n"<<"name= "<< it->second.getname()<<"\n"<<"worktype="<<it->second.getworkmode()<<"\n"<<"salary="<<it->second.getsal()<<endl;


			}
	delete E;
}

