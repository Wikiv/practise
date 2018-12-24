#include<stdio.h>
#include"tcpheader.h"
int len=sizeof(cln);
nsfd=accept(sfd,(struct sockaddr*)&cln,&len);                                   /*accepting the request from client*/
if(nsfd<0)
{
        perror("nsfd");
        return;
}
else
printf("new connection..........\n");
while(1)
{
bzero(sbuf,128);
read(nsfd,sbuf,128);                                                            /*reading the data from client*/
printf("received message from client=%s\n",sbuf);
printf("server message\n");
bzero(sbuf,128);
printf("enter the data\n");
gets(sbuf);
write(nsfd,sbuf,128);
printf("data sent\n");
}
}
