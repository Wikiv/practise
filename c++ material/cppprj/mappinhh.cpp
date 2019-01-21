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
map<int,Permanent*>map_p;
	map<int,contract*>map_c;
	map<int,worker*>map_w;
void del(int j,map<int,Permanent*> map_p)
        {
		map<int,Permanent*>::iterator itp=map_p.begin();
                cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"exp="<<(itp->second)->getexp()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
		 
	}
	void per_in(int i,string n,string d,string sa,string e,string pp)
	{
		
		 map<int,Permanent*>map_p;
	Permanent *p=new Permanent(n,d,sa,e,pp);
        cout<<"size bef insert"<<map_p.size()<<endl;
        map_p.insert(pair<int,Permanent*>(i,p));	
	}
	void con_in(int i,string nn, string dd,string saa,string pp,string ee )
	{
 		
 		map<int,contract*>map_c;
		contract *co=new contract(nn,dd,saa,pp,ee);
		cout<<"size bef insert"<<map_c.size()<<endl;
                map_c.insert(pair<int,contract*>(i,co));
		cout<<"size after insert"<<map_c.size()<<endl;
	
	}
	void wor_in(int i,string nn,string dd,string saa,string ee,string shs )
	{
		
		map<int,worker*>map_w;
		worker *w=new worker(nn,dd,saa,ee,shs);
                cout<<"size bef insert"<<map_w.size()<<endl;
                map_w.insert(pair<int,worker*>(i,w));
		cout<<"size after insert"<<map_w.size()<<endl;
	}