/*client to server server to client for several time communication*/
#include<stdio.h>
#include"tcpheaderc.h"
while(1)
{
        printf("\nenter the data\n");
        gets(buf);
        write(sfd,buf,strlen(buf));
        printf("send data from client is===%s\n",buf);
	bzero(buf,128);
	read(sfd,buf,128);
	printf("data sent from client is===%s\n",buf);	
}
return;
}

       
