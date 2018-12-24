#include<iostream>
using namespace std;
class A
{
	protected:
		int x;
	public:
		A():x(10){
			cout<<"constructor-a"<<endl;
		}
		A(int a):x(a){
			cout<<"paraconst-a"<<endl;
			//cout<<"x="<<x<<endl;
		}
		~A()
		{
			cout<<"destructor-a"<<endl;
		}
};
class B: public A

{
	protected:
		int y;
	public:
		B():y(20){
			cout<<"constructor-b"<<endl;
		}
		B(int a,int b):A(a),y(b){
			cout<<"paraconst-b"<<endl;
		}

		~B(){
			cout<<"destructor-b"<<endl;
		}

		void print()
		{
			cout<<"x="<<x<<"y= "<<y<<endl;

		}
};
class C:public B
{
	private:
		int z;
	public:
		C():z(30){
			cout<<"const-c"<<endl;
		}
		C(int a,int b,int c):B(a,b),z(c){
			cout<<"para const-c"<<endl;
		}
		~C()
		{
			cout<<"dest-c"<<endl;
		}
		void print()
		{
			cout<<"x="<<x<<"y= "<<y<<"Z= "<<z<<endl;
		}
};
int main()
{
	C obj;
	obj.print();
	//C obj1(11,22,33);
	//obj1.print();
}


