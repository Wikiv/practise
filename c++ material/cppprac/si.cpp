#include<iostream>
using namespace std;
class A
{
	private:
		int p,n,r,i,total_amt;
	public:
		void setdata()
		{
			cout<<"enter the principle, no.of.years, rate of interest"<<endl;
			cin>>p>>n>>r;
		}
		void cal_int()
		{
			i=(p*n*r)/100;
			total_amt=p+i;
		}
		void print()
		{
			cout<<"for principle=== "<<p<<" of year==="<<n<< "at interest==="<<r<<endl;
			cout<<"interest is=== " <<i<<" and total amount=== " <<total_amt<<endl;
		}
};
main()
{
	A obj;
	obj.setdata();
	obj.cal_int();
	obj.print();
}

