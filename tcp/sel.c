#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/select.h>
void main()
{
	int sfd,nsfd,i=0,r=0;
	char sbuf[128];
	struct sockaddr_in srv,cln;
	fd_set rdset,testset;
	struct timeval timeout;
	sfd=socket(PF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	srv.sin_family=PF_INET;
	srv.sin_addr.s_addr=INADDR_ANY;
	srv.sin_port=htons(2051);
	if(bind(sfd,(struct sockaddr*)&srv,sizeof(srv))==0)
	printf("bind succes.............\n");
	else
	{
		perror("bind");
		return;
	}
	listen(sfd,5);
	int len=sizeof(cln);
	FD_ZERO(&rdset);
	FD_SET(sfd,&rdset);
	while(1)
	{	
		int len=sizeof(cln);
		testset=rdset;
		select(100,&testset,0,0,0);
		for(i=0;i<100;i++)
		{
			if(FD_ISSET(i,&testset))
			{
			break;
			}
		}
		printf("out of loop\n");
		if (sfd==i)
		{
			printf("new connection......\n");
			nsfd=accept(sfd,(struct sockaddr*)&cln,&len);
			printf("nsfd=%d",nsfd);
			FD_SET(nsfd,&rdset);
		}
		else
		{
		bzero(sbuf,128);
		read(i,sbuf,128);
		printf("%s\n",sbuf);
	
		}//timeout.tv_sec=5;
		//timeout.tv_usec=0;
		//sret=select(8,&nsfd,0,0,&timeout);
	}
	return;
}
