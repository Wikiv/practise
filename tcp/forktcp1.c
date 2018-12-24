#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
void str_echo(int s)
{
char buf[50];
//receiving data from client
bzero(buf,50);
recv(s,buf,50,0);
puts("Message from Client...");
fputs(buf,stdout);
send(s,buf,50,0);
}
int main()
{
int sfd,nsfd,len;
struct sockaddr_in srv,cln;
pid_t pid;
puts("I am Server...");
//creating socket
sfd=socket(AF_INET,SOCK_STREAM,0);
puts("Socket Created Successfully...");
//socket address structure
srv.sin_family=AF_INET;
srv.sin_addr.s_addr=INADDR_ANY;
srv.sin_port=htons(2051);
bind(sfd,(struct sockaddr*)&srv,sizeof(srv));
puts("Binding Done...");
listen(sfd,3);
puts("Listening for Client...");
for(;;)
{
len=sizeof(cln);
//accepting client connection
nsfd=accept(sfd,(struct sockaddr*)&cln,&len);
puts("\nConnected to Client...");
//creating child process
{
if((pid=fork()) == 0)

puts("Child process created...");
close(sfd);
str_echo(nsfd);
close(nsfd);
//exit(0);
}
close(nsfd);
}
return 0;
}
