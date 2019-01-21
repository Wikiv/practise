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
	void str_cpy(char*,char*);
	int str_len(char*);
	void str_cat(char*,char*);
	void brk(char*p);
};
		void S::cpy(char*p)
		{
			int i=str_len(p);
			str=(char*)malloc(i+1);
			str_cpy(str,p);
			cout<<"str-"<<str<<endl;
		}
		void S::cnt (char*p)
		{
			str=(char*)realloc(str,10);
			str_cat(p,str);
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
		void S::str_cpy(char*s,char*pp)
		{
			int i=0;
			for(i=0;pp[i];i++)
				str[i]=pp[i];
				str[i]='\0';

		}
		int S::str_len(char*p)
		{
			int i;
			for(i=0;p[i];i++);
			return i-1;
		}
		void S::str_cat(char*p,char*s)
		{
			int i,j;
			for(i=0;s[i]!='\0';i++);
			for(i-1,j=0;p[j];j++,i++)
			str[i]=p[j];
			str[i]='\0';


		}
		void S::brk(char*p)
		{
			int i=0;
			for(;str[i];i++)
			{
				if(str[i]==*p)
				str[i]=' ';
				else
				continue;
			}
			cout<<"strbrk="<<str<<endl;
		}

int main()
{
char s1[10];
S ob;
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
ob.brk(s1);

}

