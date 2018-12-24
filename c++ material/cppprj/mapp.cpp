#include<iostream>
#include<map>
using namespace std;
class Emp
{
	public:
	int id;
	char name;
	private:
	char type;
	float sal;
	public:
	map<int,std::string> map_1;
void create(int id,string name)
{
 map_1.insert(pair<int,string>(id  ,name));	

}

void print()
{
	 for(map<int,string>::iterator it = map_1.begin();it != map_1.end();it++)
{
	cout<<it->first<<"->"<<it->second<<endl;
}
}
int cont(int id)
{
    map_1.count(id);
}
int fnd(int id)
{
  map_1.find(id);
}
void erse(int id)
{
    map_1.erase(id);
}  
  void prt(int d)
  {
      map_1[d];
  }
};
int main()
{
//map<int,std::string> map_1;
	Emp e,e1,e2,e3,e4;
     int choice, id;
     char name;

    while (1)

    {

        cout<<"1.Insert Element into the Map"<<endl;

        cout<<"2.Modify Element of the Map"<<endl;

	    cout<<"3.Find Element at a key in Map"<<endl;

        cout<<"4.Delete the data"<<endl;

        cout<<"5.Print the Elements at a specific key"<<endl;

        cout<<"6.Print all elements"<<endl;

        cout<<"Enter your Choice: ";

        cin>>choice;

        switch(choice)
        {
        case 1:

            cout<<"Enter id and name to be inserted: ";
            cin>>id>>name;
	        e.create(id,&name);
            break;

        

      case 3:

	    cout<<"Enter the Id at which name  to be found: ";

            cin>>id;

            if (e.cont(id) != 0)

                cout<<e.fnd(id).second<<endl;

            else

                cout<<"No Element Found"<<endl;

            break;
    case 4:

            cout<<"Enter the id to be deleted: ";

            cin>>id;
            cout<<e.erse(id)<<endl;
            break;
    case 5:
        cout<<"Enter the ID to print specific id";
        cin>>id;
        cout<<e.prt(id)<<endl;
        break;

        case 6:

	    cout<<"Displaying all values: ";

           /* for (map<int,string>::iterator it = map_1.begin(); it != map_1.end(); it++)

            {

                cout << (*it).first << ": " << (*it).second << endl;

            }*/e.print();

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
