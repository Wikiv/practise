#include<iostream>
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
                	
int main()
{
        string nn,ee,rr,pp,saa,shs,dd;
        char c;
        int i=0,choice;
        map<int,Permanent*>map_p;
	map<int,contract*>map_c;
	map<int,worker*>map_w;
while(1)
        {
		cout<<"1.Insert details"<<endl;
		cout<<"2.Modify details"<<endl;
		cout<<"3..Delete the details"<<endl;
		cout<<"4.Print all details"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your Choice: "<<endl;
		cin>>choice;

                switch(choice)

                {

                case 1:

                        do{
				cout<<"1.permanent 2.contract 3.worker"<<endl;
				cin>>choice;
				switch(choice)
				{
					case 1:
						{
							cout<<"enter the id,name,dept,salary,exp,position"<<endl;
			                  		cin>>i>>nn>>dd>>saa>>ee>>pp;
                        	        		 per_in(i,nn,dd,saa,ee,pp);
						}		
						break;
					case 2:
							{
								cout<<"enter the id,name,dept,sal,position,year"<<endl;
                                                		cin>>i>>nn>>dd>>saa>>pp>>ee;
                                				con_in(i,nn,dd,saa,pp,ee);
							}
							break;
					case 3:
							{
							       	cout<<"enter the id,name,dept,sal,year,shift"<<endl;
                                                		cin>>i>>nn>>dd>>saa>>ee>>shs;
                                                 		wor_in(i,nn,dd,saa,ee,shs);
                                                 		
							}
							break;
				}
			cout<<"do u need to insert again[y/n]"<<endl;
                        cin>>c;

                        }while(c=='y');

                        break;
                
		case 2:

		 {
                                cout<<"enter to modify"<<endl;
                        	cin>>i;
				map<int,Permanent*>::iterator itp=map_p.begin();
				itp=map_p.find(i);
				if(itp!=map_p.end())
			{
				map_p.erase(i);
				cout<<"enter the id,name,dept,salary,exp,position"<<endl;
			        cin>>i>>nn>>dd>>saa>>ee>>pp;
                        	 per_in(i,nn,dd,saa,ee,pp);
				cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"dept="<<(itp->second)->getdept()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
				
			}
			else
			{
			map<int,contract*>::iterator itc=map_c.begin();
			itc=map_c.find(i);
			if(itc!=map_c.end())
			{
				map_c.erase(i);
				cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
				cout<<"enter the id,name,dept,sal,position,year"<<endl;
                                cin>>i>>nn>>dd>>saa>>pp>>ee;
                                contract *co=new contract(nn,dd,saa,pp,ee);
				cout<<"size bef insert"<<map_c.size()<<endl;
                                map_c.insert(pair<int,contract*>(i,co));
				cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
			}
			else
			{
			map<int,worker*>::iterator itw=map_w.begin();
                        if(itw!=map_w.find(i))
			{
					cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";
					map_w.erase(i);
					cout<<"enter the id,name,dept,sal,year,shift"<<endl;
                                        cin>>i>>nn>>dd>>saa>>ee>>shs;
                                        worker *w=new worker(nn,dd,saa,ee,shs);
                                	cout<<"size bef insert"<<map_w.size()<<endl;
                                        map_w.insert(pair<int,worker*>(i,w));
                                        cout<<"size after insert"<<map_w.size()<<endl;
					cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";
			}
			else
				cout<<"id not found"<<endl;
			
			}}
			cout<<"id deleted"<<endl;
                        }
                        break;
		
		case 3:

                        {
                                cout<<"enter to id del"<<endl;
                        cin>>i;
			map<int,Permanent*>::iterator itp=map_p.begin();
			itp=map_p.find(i);
			if(itp!=map_p.end())
			{
				cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"dept="<<(itp->second)->getdept()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
				map_p.erase(i);
			}
			else
			{
			map<int,contract*>::iterator itc=map_c.begin();
			itc=map_c.find(i);
			if(itc!=map_c.end())
			{
				 cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
				map_c.erase(i);
			}
			else
			{
			map<int,worker*>::iterator itw=map_w.begin();
                        if(itw!=map_w.find(i))
			{
				cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";
				map_w.erase(i);
			}
			else
				cout<<"id not found"<<endl;
			
			}}
			cout<<"id deleted"<<endl;
                        }
                        break;

                case 4:
			cout<<"1.permanent 2.contract 3.worker"<<endl;
			cin>>choice;
                        switch(choice)
		{
				case 1:
				for (map<int,Permanent*>::iterator itp=map_p.begin(); itp != map_p.end(); itp++)                    
				cout <<"ID="<< itp->first<<"\n"<<"name= "<< (itp->second)->getname()<<"\n"<<"dept="<<(itp->second)->getdept()<<"\n"<<"salary="<<(itp->second)->getsal()<<"\n"<<"exp= "<< (itp->second)->getexp()<<"\n"<<"position= "<< (itp->second)->getposition()<<"\n";
                        	break;
				case 2:
				for (map<int,contract*>::iterator itc=map_c.begin(); itc != map_c.end(); itc++)
                {
			 	cout <<"ID="<< itc->first<<"\n"<<"name= "<< (itc->second)->getname()<<"\n"<<"dept="<<(itc->second)->getdept()<<"\n"<<"salary="<<(itc->second)->getsal()<<"\n"<<"contract period= "<< (itc->second)->getcon_p()<<"\n"<<"position= "<< (itc->second)->getposition()<<"\n";
		}
				break;
				case 3:
		for (map<int,worker*>::iterator itw=map_w.begin(); itw != map_w.end(); itw++)
		{
			cout <<"ID="<< itw->first<<"\n"<<"name= "<< (itw->second)->getname()<<"\n"<<"dept="<<(itw->second)->getdept()<<"\n"<<"salary="<<(itw->second)->getsal()<<"\n"<<"con_p= "<< (itw->second)->getcon_p()<<"\n"<<"shift= "<< (itw->second)->getshift()<<"\n";	
		}
		}
		break;
	
		case 5:
                        {
				exit(1);
			}
                default:
                        cout<<"wrong choice"<<endl;
                }
		}			
	return 0;
		}