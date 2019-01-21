//#include<iostream>
#include<string.h>
#include<map>
using namespace std;
class Emp
{
	public:
        string name;
       	string sal;
	string dept;
	Emp(){}

	string& getname()
        {
                return name;
        }
        string& getsal()
        {
                return sal;
        }
        string& getdept()
        {
                return dept ;
        }
    
};
class Permanent:public Emp
{
	public:
		string exp;
		string position;

Permanent(string n="NiLL",string d="NiLL",string s="NiLL",string e="NiLL",string p="NiLL")
	{
	name=n;
	dept=d;
	sal=s;
	exp=e;
	position=p;
	
	}
	string& getexp()
        {
                return exp ;
        }
	string& getposition()
        {
                return position ;
        }
	

};

class contract:public Permanent
{
	public:
	string con_p;
contract(string n="nill",string d="nill",string s="nill",string p="nill",string e="nill")
{
name=n;
dept=d;
sal=s;
position=p;
con_p=e;

}

 string& getcon_p()
        {
                return con_p ;
        }

};
class worker:public contract 
{
	public:
		string shift;
worker(string n,string d,string s,string e,string sh)
{
name=n;
dept=d;
sal=s;
con_p=e;
shift=sh;
}
string& getshift()
        {
               return shift;
        }
};
