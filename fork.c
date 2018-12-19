#include<stdio.h>
#include<sys/types.h>
void main()
{
//for(int i=0;i<3;i++)

	if(fork()==0)
{
//printf("child pid=%d,ppid=%d\n",getpid(),getppid());
//sleep(5);
//printf("child ppid=%d,pid=%d\n",getppid(),getpid());
printf("child exit\n");
}
//else
//printf("parent pid=%d,ppid=%d\n",getpid(),getppid());
//sleep(10);
printf("parrent exit\n");

}
