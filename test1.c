#include<stdio.h>
#include<string.h>
/*main(int argc,char *argv[])
{
	if (argc!=2)
	{
	perror("usage:./a.out string");
	return;
	}
	char c[50];
	strcpy(c,argv[1]);
        int i;
	for(i=0;c[i];i++)
	{
		if(c[i]=='.'||c[i]==',')
			c[i]=' ';
	printf("%c",c[i]);
}
}*/
void main(int argc,char *argv[])
{

	     if (argc!=2)
        {
        perror("usage:./a.out string");
        return;
	}
		char c[50],*p;
        	p=&c;
		strcpy(c,argv[1]);
		while(*p!='\0')	
		{
			if(*p=='.'||*p==',')
				*p=' ';
				printf("%c",*p++);
		}	
			
	

}

