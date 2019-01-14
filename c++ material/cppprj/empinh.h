#include<string.h>
#include<map>
using namespace std;
class Emp
{
	public:
    Emp(){}
        string name;
       	string sal;
	    string dept;
	string getname();
    string getsal();
    string getdept();
};
class Permanent:public Emp
{
	public:
         string exp;
		string position;
    Permanent(string n,string d,string s,string e,string p);
        string getexp();
	    string getposition();
        void print();

};

class contract:public Permanent
{
	public:
	string con_p;
    contract(string n,string d,string s,string p,string e);
    string getcon_p();
};
class worker:public contract 
{
	public:
            string shift;
            worker(string n,string d,string s,string e,string sh);
            string getshift();
};

void per_in(int ,string,string,string,string,string);
void con_in(int ,string , string ,string ,string ,string );
void wor_in(int ,string ,string ,string ,string ,string );
void del(int j,map<int,Permanent*> map_p);
     map<int,Permanent*>map_p;
    map<int,contract*>map_c;
	map<int,worker*>map_w;