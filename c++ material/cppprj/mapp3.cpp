#include<iostream>
#include<map>
#include<string>
using namespace std;
class Emp
{


		string type,name;
		long sal;
	public:
		Emp(string n,string t,long s)
		{name =n;
			type=t;
			sal=s;
			
		//std::cout<<name<<type<<sal;
		}
/*bool opertator<(const Emp& obj)const
{
	if(obj.id<this->id)
		return true;
}*/
};
void data()
{
map<string,string> map_2;
map<string,map_2> map_1;
map_2.insert(pair<string,string>())

}