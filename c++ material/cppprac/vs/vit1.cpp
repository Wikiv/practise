#include<iostream>
using namespace std;
class A
{
    public:
    void fun()
    {
        cout<<"fun-a"<<endl;

    }
};
class B:public A
{
    public:
    void fun()
    {
        cout<< "fun-b"<<endl;
    }
};
int main()
{
    A *bptr;
    A a;
    bptr=&a;
    bptr->fun();
    B b;   
    bptr=&b;
    B*bptr;
    bptr->fun();
}