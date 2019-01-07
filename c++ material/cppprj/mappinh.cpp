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
	 string& getworkmode()
        {
                return workmode;
        }

        


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

/*class contract:public Permanent
{
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
class worker:public Permanent 
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
};*/
void del(int j,map<int,Emp*> map_e)
        {
                        map<int,Emp*>::iterator it=map_e.begin();
                it=map_e.find(j);
                 map_e.erase(j);
                cout<<"size aft del"<<map_e.size()<<endl;

}
int main()
{
        string nn,ee,rr,pp,saa,shs,dd;
        char c;
        int i=0,choice;
        map<int,Emp*>map_e;
        Emp *E,*D;
        while(1)
        {
        cout<<"1.Insert Id and name"<<endl;
        cout<<"2.Modify Id"<<endl;
        cout<<"3..Delete the Id"<<endl;
        cout<<"4.Print all Id"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your Choice: "<<endl;
        cin>>choice;

                switch(choice)
                {

                case 1:

                        do{

                                cout<<"enter the id,exp,rating,sal,shift,dept"<<endl;
                                cin>>nn,ee,rr,pp,saa,shs,dd;
                                Emp *E=new Permanent(nn,ee,rr,pp,saa,shs,dd);
                                cout<<"size bef insert"<<map_e.size()<<endl;
                                map_e.insert(pair<int,Emp*>(i,E));
                                cout<<"size after insert"<<map_e.size()<<endl;
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

                        for (map<int,Emp*>::iterator it=map_e.begin(); it != map_e.end(); it++)

                        {
                                cout <<"ID="<< it->first<<"\n"<<"name= "<< (it->second)->getname()<<"\n"<<"worktype="<<(it->second)->getworkmode()<<"\n"<<"salary="<<(it->second)->getsal()<<endl;


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

