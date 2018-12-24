#include<iostream>
using namespace std;
class A
{
	public:
		virtual ~A(){
			cout<<"dest-a"<<endl;
		}
};
class B:public A
{
	public:
/*virtual*/		~B(){
			cout<<"dest-b"<<endl;
		}
};
class C:public B
{
	public:
/*virtual*/	~C(){
		cout<<"dest-c"<<endl;
	}
};
int main()
{

//	C c;
//	C *dptr=new C;
//	delete dptr;
	A *bptr=new C();
	delete bptr;
//	B*cptr=new B;
//	delete cptr;
}

