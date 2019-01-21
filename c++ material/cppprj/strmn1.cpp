#include<stdio.h>
#include<stdlib.h>
int main()
{
	char s1[10],s2[10];int n;
	printf("enter the string 1 size");
	scanf("%d",&n);
	char *p=(char*)malloc(sizeof(char)*n);
	printf("enter the string s1\n");
	for(int i=0;i<n;i++)
	{
		scanf("%s",p+i);		
	}
	printf("enter the size of string 2\n");
	scanf("%d",&n);
	p=(char*)realloc(p,n*sizeof(char));
	for(int i=0;p[i];i++)
		printf("%s",p+i);
}



