#include<iostream>
#include<string.h>
using namespace std;
class S
{
	private:
		char *str;
	public:
	void cpy(char*p);
	void cnt (char*p);
	void oc(char*p);
	void str_cpy(char*);
	int str_len(char*);
	void str_cat(char*);
	void brk(char*p,S *[]);
};
		void S::cpy(char*p)
		{
			int i=str_len(p);
			str=(char*)malloc(i+1);
			str_cpy(p);
			cout<<"str-"<<str<<endl;
		}
		void S::cnt (char*p)
		{
			str=(char*)realloc(str,10);
			str_cat(p);
			cout<<"str1-"<<str<<endl;
		}
		void S::oc(char*p)
		{
			int count=0;
			for(int i=0;str[i];i++)
			{
				if(str[i]==*p)
				count++;
				else
					continue;
			}
			cout<<"occurance of char="<<count<<endl;
			cout<<"str2-"<<str<<endl;
		}
		void S::str_cpy(char*p)
		{
			int i=0;
			for(i=0;p[i];i++)
				this->str[i]=p[i];
				this->str[i]='\0';

		}
		int S::str_len(char*p)
		{
			int i;
			for(i=0;p[i];i++);
			return i-1;
		}
		void S::str_cat(char*p)
		{
			int i,j;
			for(i=0;this->str[i]!='\0';i++);
			for(i-1,j=0;p[j];j++,i++)
			this->str[i]=p[j];
			this->str[i]='\0';


		}
		void S::brk(char*p,S *result[10])
		{
			int i=0;
			for(;str[i];i++)
			{
				result[i]=&this->str;
				//cout<<"res-"<<result<<endl;
				//result++;
				if(str[i]==*p)
					str[i]=' ';
				else
				continue;
			}
			cout<<"strbrk="<<str<<endl;
			
		}
		S S::operator=(S*result[])


int main()
{
char s1[10];
S ob;
S *result[10];
cout<<"enter string 1"<<endl;
cin>>s1;
ob.cpy(s1);
cout<<"enter string to con"<<endl;
cin>>s1;
ob.cnt(s1);
cout<<"enter to find a occurance of a word"<<endl;
cin>>s1;
ob.oc(s1);
cout<<"enter a char to break a string"<<endl;
cin>>s1;
ob.brk(s1,result);

}

