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
	int sfd,sret,ret;
	char wrbuf[128];
	struct sockaddr_in srv,cln;
	int sfd;
	fd_set nsfd1;
	struct timeval timeout;
	sfd=socket(PF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	srv.sin_family=PF_INET;
	srv.sin_addr.s_addr=INADDR_ANY;
	srv.sin_port=htons(8080);
	if(bind(sfd,(struct sockaddr*)&srv,sizeof(srv))==0)
		printf("bind succes.............\n");
	else
	{
		perror("bind");
		return;
	}
	listen(sfd,1);
	int len=sizeof(cln);
	nsfd=accept(sfd,(struct sockaddr*)&cln,&len);
	if(nsfd<0)
	{
		perror("accept");
		return;
	}
	else
		printf("new connection.............\n");
	while(1)
	{
		bzero(wrbuf,128);
		FD_ZERO(&nsfd);
		FD_SET(fd,&nsfd);


		timeout.tv_sec=5;
		timeout.tv_usec=0;
		sret=select(8,&nsfd,0,0,&timeout);
		if (sret==0)
		{
			printf("sret=%d",sret);

			ret=read(fd,wrbuf,128);
			printf("ret=%d",ret);
			printf("rece=%s",wrbuf);
		}
	}
	return;
}
