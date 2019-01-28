#include<iostream>
#include<string.h>
using namespace std;
class S
{
	private:
		char *str;
		
	public:
	void cpy_str(char *p);
	void cnt_str (char *p);
	void occ_str(char *p);
	void str_cpy(char *p);
	int str_len(char *p);
	void str_cat(char *p);
	void brk_str(char *p,S *[]);
	int sub_str(char *p);
	void str_lwr();
	void str_upr();
};
		void S::cpy_str(char *p)
		{
			int i=str_len(p);
			str=(char*)malloc(i+1);
			str_cpy(p);
			cout<<"str-"<<str<<endl;
		}
		void S::cnt_str (char *p)
		{
			str=(char*)realloc(str,10);
			str_cat(p);
			cout<<"str1-"<<str<<endl;
		}
		void S::occ_str(char *p)
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
		void S::str_cpy(char *p)
		{
			int i=0;
			for(i=0;p[i];i++)
				this->str[i]=p[i];
				this->str[i]='\0';

		}
		int S::str_len(char *p)
		{
			int i;
			for(i=0;p[i];i++);
			return i-1;
		}
		void S::str_cat(char *p)
		{
			int i,j;
			for(i=0;this->str[i]!='\0';i++);
			for(i-1,j=0;p[j];j++,i++)
			this->str[i]=p[j];
			this->str[i]='\0';


		}
		void S::brk_str(char *p,S *result[])
		{
			int i=0,j=0,k=0,l=-1,count=0;
			
			
			char *a;
			for(;str[i];i++)
			{
				if(str[i]==p[j])
				{
					//a=(char*)malloc(sizeof(1));
					j++;
					k=0;
					continue;
				}
								
				if(p[j]=='\0')
				{
					j=0;
					i--;
					l++;
					//k=0;
					continue;
				}
				else
				{
					result[l]=(S*)malloc(sizeof(S));
					result[l]->str=(char*)malloc(2);
					result[l]->str[k]=str[i];
					k++;
					//j++;
					cout<<endl<<"i-"<<this->str[i]<<endl;
					cout<<"result-"<<result[l]->str<<"L-"<<l<<"K"<<k<<endl;
				
					count++;
				
				}
				
			}
			l=0;
			/*while(result[l]->str)
			{
				cout<<"result-"<<result[l]->str<<"L-"<<l<<endl;
				l++;
			}*/
			cout<<endl<<"strbrk="<<str<<endl;
			
			cout<<"cout-"<<count<<endl;
			
			
		}
		int S::sub_str(char *p)
		{
			int i,j;
			for(i=0;this->str[i];i++)
			{
				if(this->str[i]==p[0])

				{	
					for(j=1;p[j];j++)
					{	
					if(p[j]!=this->str[i+j])
					break;
					}
					if(p[j]=='\0')
					{
						return((*str)+i);
						cout<<"i-"<<this->str[i]<<endl;
					}
				}

			}
		return 0;
		}
		void S::str_lwr()
		{
			int i=0;
			for(i=0;this->str[i];i++)
			if(this->str[i]>=65&&this->str[i]<=90)
			this->str[i]=this->str[i]+32;
			cout<<endl<<"str_lwr="<<str<<endl;

			
		}
		void S::str_upr()
		{
			int i=0;
			for(i=0;this->str[i];i++)
			if(this->str[i]>=97&&this->str[i]<=122)
			this->str[i]=this->str[i]-32;
			cout<<endl<<"str_lwr="<<str<<endl;

		}


int main()
{
char s1[1000];
S ob;
S *result[100];
cout<<"enter string 1"<<endl;
cin>>s1;
ob.cpy_str(s1);
cout<<"enter string to con"<<endl;
cin>>s1;
ob.cnt_str(s1);
cout<<"enter to find a occurance of a word"<<endl;
cin>>s1;
ob.occ_str(s1);
cout<<"enter a char to break a string"<<endl;
cin>>s1;
ob.brk_str(s1,result);
cout<<"enter the string to find sub string"<<endl;
cin>>s1;
int p=ob.sub_str(s1);
cout<<"substring found at-"<<p<<endl;
cout<<"lower case"<<endl;
ob.str_lwr();
cout<<"upper case"<<endl;
ob.str_upr();
}

