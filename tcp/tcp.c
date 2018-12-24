#include <sys/types.h>
#include <arpa/inet.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include <unistd.h>
#include<string.h>
void main()
{
	int i=0,r,c=0;
	char a;
	struct sockaddr_in srv,cln;
	int sfd=socket(PF_INET,SOCK_STREAM,0);
	int nsfd[10]={0};
	char sbuf[128];
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	srv.sin_family=PF_INET;
	srv.sin_addr.s_addr=INADDR_ANY; //inet_addr("0.0.0.0");/*accept any ip address*/
	srv.sin_port=htons(2051);/*converts the unsigned integer hostlong  from  host byte order to network byte order*/
if(bind(sfd,(struct sockaddr*)&srv,sizeof(srv))==0)
printf("bind success........\n");
else
{
	perror("bind");
	return;

}
listen(sfd,3);
while(1)
{
int len=sizeof(cln);
static int c=0;
nsfd[i++]=accept4(sfd,(struct sockaddr *)&cln,&len,SOCK_NONBLOCK);
c++;
int j=0;
printf("new connection......of=%d\n",c);
bzero(sbuf,128);
printf("nsfd=%d",nsfd[i]);
r=recv(nsfd[j],sbuf,128,0);
printf("nsfd1=%d",nsfd[j]);
printf("r=%d",r);
if(r<=0)
{
	printf("client terminated......=%d\n",j);
	close(nsfd[i]);
}
else
printf("received data from client==== %s\n",sbuf);
j++;
}
return;
}
