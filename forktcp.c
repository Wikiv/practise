#include<stdio.h>
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
        int nsfd[10]={0};;
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
int len=sizeof(cln);
while(1)
{
	//a:nsfd[i]=accept(sfd,(struct sockaddr*)&cln,&len);

	if(fork()==0)
{
	for(i=0;i<c;i++)
	{
	bzero(sbuf,128);
	read(nsfd[i],sbuf,128);
	printf("received data from client====%s\n",sbuf);
	}
}
nsfd[i]=accept(sfd,(struct sockaddr*)&cln,&len);
c++;
sleep(5);
}
return;
}

