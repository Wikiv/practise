#include<iostream>
#include<map>
#include<string>
using namespace std;

class Emp
{

	public: 
		string type,name,sal;
		void init(string n,string t,string s)
		{
			name =n;
			type=t;
			sal=s;
		}
		
	public:		
		void print()
			{
    				cout<<name<<type<<sal<<endl;
				
			}
	const string& gettype() const
	{
		return type;
	}
	const std::string& getname() const
	{
		return name;
	}				
	const string& getsal() const
	{
		return sal; 
	}  		
};	
int main()
{
	char c;
	string n,t,s;
	int choice, i=0;
	map<int , Emp> map_m;
	Emp E1;
    while (1)
    {
		
	cout<<"1.Insert Id and name"<<endl;
    	cout<<"2.Modify Id"<<endl;
	cout<<"3.Find name of given Id "<<endl;
        cout<<"4.Delete the Id"<<endl;
        cout<<"5.Print the Name at a specific Id"<<endl;
        cout<<"6.Print all Id"<<endl;
        cout<<"7.Exit"<<endl;
	cout<<"Enter your Choice: "<<endl;
        cin>>choice;
		
        switch(choice)
      {
        case 1:
		do
		{
			cout<<"enter id name workmode salary "<<endl;
			cin>>i>>n>>t>>s;
			E1.init(n,t,s);
			map_m.insert(pair<int, Emp>(i, E1));
  			cout<<"do you need to enter again[y/n]"<<endl;
	    		cin>>c;
			 
		}	while(c=='y');
		 
	}		cout<<"del"<<endl;
			map<int,Emp>::iterator it = map_m.begin();
			cin>>i;
			it=map_m.find(i);
			map_m.erase(it);
			for (; it != map_m.end(); it++)
			{
				 cout <<"ID="<< it->first<<"\n"<<"name= "<< it->second.getname()<<"\n"<<"worktype= "<<it->second.gettype()<<"\n"<<"salary= "<<it->second.getsal()<<endl;
			
			}

	 }

    
 return 0;
}

