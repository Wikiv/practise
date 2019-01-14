#include "empinh.h"
#include<iostream>

       string Emp::getname()
        {
            return name;
        }
        string Emp::getsal()
        {
            return sal;
        }
        string Emp::getdept()
        {
            return dept;
        }

    Permanent::Permanent(string n="nill",string d="nill",string s="nill",string e="nill",string p="nill")
	{
	name=n;
	dept=d;
	sal=s;
	exp=e;
	position=p;
	
	}
    void Permanent::print(){
            cout<<name<<sal<<dept<<exp<<position<<endl;
        }
   string Permanent::getexp()
    {
        return exp;
    }
	string Permanent::getposition()
    {
        return position;
    }
  contract::contract(string n="nill",string d="nill",string s="nill",string p="nill",string e="nill")
{
name=n;
dept=d;
sal=s;
position=p;
con_p=e;

}
string contract::getcon_p()
{
    return con_p;
}
worker::worker(string n,string d,string s,string e,string sh)
{
name=n;
dept=d;
sal=s;
con_p=e;
shift=sh;
}
string worker::getshift()
{
    return shift;
}
void del(int j,map<int,Permanent*> map_p)
        {
		map<int,Permanent*>::iterator itp=map_p.begin();
                cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"exp="<<(itp->second)->getexp()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
		 
	}
	void per_in(int i,string n,string d,string sa,string e,string pp)
	{
		
		Permanent *p=new Permanent(n,d,sa,e,pp);
        cout<<"size bef insert"<<map_p.size()<<endl;
        map_p.insert(pair<int,Permanent*>(i,p));	
	}
	void con_in(int i,string nn, string dd,string saa,string pp,string ee )
	{
 		
 		contract *co=new contract(nn,dd,saa,pp,ee);
		cout<<"size bef insert"<<map_c.size()<<endl;
        map_c.insert(pair<int,contract*>(i,co));
		cout<<"size after insert"<<map_c.size()<<endl;
	
	}
	void wor_in(int i,string nn,string dd,string saa,string ee,string shs )
	{
		
		worker *w=new worker(nn,dd,saa,ee,shs);
        cout<<"size bef insert"<<map_w.size()<<endl;
        map_w.insert(pair<int,worker*>(i,w));
		cout<<"size after insert"<<map_w.size()<<endl;
	}