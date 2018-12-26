#include<iostream>
#include<map>
using namespace std;
class Emp
{
	public:
	int id;
	char name;
	map<string id,string> map_1;
	private:
	char type;
	float sal;
	public:
void create(string id,string name)
{
 map_1.insert(pair<string,string>(id  ,name));	
 map_1.insert(pair<string,string>( ,name));	
}

void print()
{
	 for(map<string,string>::iterator it = map_1.begin();it != map_1.end();it++)
	 cout<<it->first<<"->"<<it->second<<endl;
}
int cont(string id)
{
    map_1.count(id);
}
int fnd(string id)
{
  
	map_1.find(id)->second;
      	cout<<map_1[id]<<endl;
}
void erse(string id)
{
    map_1.erase(id);
}  
  void prt(string id)
  {
     cout<<map_1[id]<<endl;
  }
void mod(string id,string name)
{
 map_1[id]=name;
}

};
int main()
{
	Emp e;
	int choice;
	string name,id,type,sal;
	char c;
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
            cout<<"Enter id and name to be inserted: ";
            cin>>id>>name;
	    e.create(id,name);
	    cout<<"do you need to enter again[y/n]"<<endl;
	    cin>>c;
	}while(c=='y');
    	break;
	case 2:

	    cout<<"Enter the Id to modify"<<endl;
	    cin>>id;
	    cout<<"Enter the data"<<endl;
	    cin>>name;
	    e.mod(id,name);
		break;

        case 3:

	    cout<<"Enter the Id at which name  to be found: ";
            cin>>id;
            if (e.cont(id) != 0)
                e.fnd(id);
            else
                cout<<"No Element Found"<<endl;
            break;

    	case 4:

            cout<<"Enter the id to be deleted: ";
            cin>>id;
            e.erse(id);
	    cout<<"Entered  id is erased"<<endl;
	    break;

    	case 5:

        cout<<"Enter the ID to print specific ";
        cin>>id;
        e.prt(id);
        break;

        case 6:

	    cout<<"Displaying all values: "<<endl;
    	    e.print();
	    break;

      	case 7:

            exit(1);

	    break;

        default:

            cout<<"Wrong Choice"<<endl;

        }


    }
	    

return 0;
}
