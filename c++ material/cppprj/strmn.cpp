#include<iostream>
using namespace std;
class S
{
    public:
    string s1;
    S(){}
    S (string s_1):s1(s_1){}
 	 S operator+(S&ob2);
    void print();
};
S S::operator+(S&ob2)
{
    S obj;
    obj.s1=s1+ob2.s1;
    return obj;
}
void S::print()
{
    cout<<"S1-"<<s1<<endl;

}
int main()
{
    S obj1("abc"),obj2("ghi"),obj3;
    
    obj3=obj1+obj2;
    cout<<"obj1-";
    obj1.print();
    cout<<"obj2-";
    obj2.print();
    cout<<"obj4-";
    obj3.print();
}
