#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main()
{
        struct sockaddr_in cln,srv;
        char buf[128];
        int sfd=socket(PF_INET,SOCK_STREAM,0);
        if(sfd<0)
        {

        perror("socket");
        return;
        }
        cln.sin_family=PF_INET;
        cln.sin_port=inet_addr("127.0.0.1");
        cln.sin_port=htons(2051);
        if(connect(sfd,(struct sockaddr*)&cln,sizeof(cln))==0)
                printf("connect established............\n");
        else
        {
                perror("conect");
                return;
        }
        while(1)
        {
        printf("\nenter the data\n");
        gets(buf);
        send(sfd,buf,strlen(buf),0);
                //write(sfd,buf,strlen(buf));
                //bzero(buf,128);
                //read(sfd,buf,128);
                printf("send data===%s\n",buf);
        }
return;
}
 
