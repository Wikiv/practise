#include<iostream>
#include<string.h>
#include<map>
using namespace std;
class Emp
{
	public:
        string name;
       	//string workmode;
        string sal;
	string dept;
	string shift;

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
        string& getshift()
        {
                return shift;
        }
	/* string& getworkmode()
        {
                return workmode;
        }*/

//~Emp(){}

};
class Permanent:public Emp
{
	public:
		string exp;
		string rating;
		string position;

Permanent(string n,string e,string r,string p,string s,string sh,string d)
	{
	name=n;
	exp=e;
	rating=r;
	position=p;
	sal=s;
	dept=d;
	shift=sh;
	//workmode=&Permanent;
	}
	string& getexp()
        {
                return exp ;
        }
	string& getrating()
        {
                return rating;
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
contract(string n,string y,string r,string p,string d,string s)
{
name=n;
con_p=y;
rating=r;
position=p;
dept=d;
sal=s;
}
 string& getcon_p()
        {
                return con_p ;
        }

};
/*class worker:public contract 
{
	public:
		string year;

worker(string n,string y,string d,string sh,string s)
{
name=n;
year=y;
dept=d;
shift=sh;
sal=s;
}
string& getyear()
        {
               return year;
        }
};
void del(int j,map<int,Emp*> map_e)
        {
                        map<int,Emp*>::iterator it=map_e.begin();
                it=map_e.find(j);
                 map_e.erase(j);
                cout<<"size aft del"<<map_e.size()<<endl;

		}*/
int main()
{
        string nn,ee,rr,pp,saa,shs,dd;
        char c;
        int i=0,choice;
        map<int,Permanent*>map_p;
	map<int,contract*>map_c;
//	map<int,worker*>map_w;
	Permanent *p;
        contract *co;
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
							cout<<"enter the id,name,exp,rating,position,sal,shift,dept"<<endl;
			                  		cin>>i>>nn>>ee>>rr>>pp>>saa>>shs>>dd;
                        	        		Permanent *p=new Permanent(nn,ee,rr,pp,saa,shs,dd);
                                			cout<<"size bef insert"<<map_p.size()<<endl;
                                			map_p.insert(pair<int,Permanent*>(i,p));
                                			cout<<"size after insert"<<map_p.size()<<endl;
						}		
						break;
					case 2:
							{
								cout<<"enter the id,name,years,rating,sal,shift,dept"<<endl;
                                                		cin>>i>>nn>>ee>>rr>>pp>>saa>>dd;
                                				contract *co=new contract(nn,ee,rr,pp,dd,saa);
								cout<<"size bef insert"<<map_c.size()<<endl;
                                                		map_c.insert(pair<int,contract*>(i,co));
								cout<<"size after insert"<<map_c.size()<<endl;
							}
							break;
					/*case 3:
							{
							       	cout<<"enter the id,name,years,rating,sal,shift,dept"<<endl;
                                                		cin>>i>>nn>>ee>>saa>>shs>>dd;
                                                 		worker *w=new worker(nn,ee,dd,shs,saa);
                                               			cout<<"size bef insert"<<map_w.size()<<endl;
                                                 		map_w.insert(pair<int,worker*>(i,w));
                                                 		cout<<"size after insert"<<map_w.size()<<endl;
							}
							break;*/
				}
			cout<<"do u need to insert again[y/n]"<<endl;
                        cin>>c;

                        }while(c=='y');

                        break;
           /*     case 2:

                        {
                                cout<<"enter to modifiy"<<endl;
                        cin>>i;
                        del(i,map_e);
                        cout<<"enter the id ,name, worktype, salary"<<endl;
                        cin>>i>>na>>ww>>saa;
                                Emp *D=new Emp(na,ww,saa);
                        map_e.insert(pair<int,Emp*>(i,D));
                        cout<<"size after insert"<<map_e.size()<<endl;
                        }
                        break;

                case 3:
                        {
                                cout<<"enter the id to delete"<<endl;
                        cin>>i;
                        map<int,Emp*>::iterator it=map_e.begin();
                        del(i,map_e);
                        }
                        break;
             */   case 4:

                        for (map<int,Permanent*>::iterator it=map_p.begin(); it != map_p.end(); it++)

                        {
                                cout <<"ID="<< it->first<<"\n"<<"name= "<< (it->second)->getname()<<"\n"<<"exp="<<(it->second)->getexp()<<"\n"<<"salary="<<(it->second)->getsal()<<"\n"<<"rating="<<(it->second)->getrating()<<"\n"<<"dept= "<< (it->second)->getdept()<<"\n"<<"position= "<< (it->second)->getposition()<<"\n"<<"shift= "<< (it->second)->getshift()<<"\n"<<"\n"<<endl;


                        }
                        break;
                case 5:
                        exit(1);
                default:
                        cout<<"wrong choice"<<endl;
                }
//      delete E;
//      delete D;
        }
return 0;
}


