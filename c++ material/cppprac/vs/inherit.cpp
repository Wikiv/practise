#include<iostream>
using namespace std;
class A
{
    public:
    int x;
};   
class B:public A
    {
        public:
        void print()
    {
        cout<<"x= "<<x<<endl;
    
    }
};
int main()
{
    B d;
    d.x=10;
    d.print();

}