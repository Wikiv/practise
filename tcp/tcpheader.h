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
        struct sockaddr_in srv,cln;
        int nsfd;
        char sbuf[128];
        int sfd=socket(PF_INET,SOCK_STREAM,0);                                  /*creatioon of sockets*/
        if(sfd<0)
        {
                perror("socket");
                return;
        }
        srv.sin_family=PF_INET;
        srv.sin_addr.s_addr=INADDR_ANY;                                         /*inet_addr("0.0.0.0");accept any ip address*/
        srv.sin_port=htons(2051);                                               /*converts the unsigned integer hostlong  from  host byte order to network byte order*/
if(bind(sfd,(struct sockaddr*)&srv,sizeof(srv))==0)                             /*bind of port and ip addr*/
printf("bind success........\n");
else
{
        perror("bind");
        return;

}
listen(sfd,3);
