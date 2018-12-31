#include "Semaphore.h"
#include <sys/signal.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

Semaphore s;
void critical_resource()
{
    char c;
    printf("Request from %d\n", getpid());
    while(1) {
        c = getchar();
        if(c != '\n') 
            break;
    }
    if(isdigit(c) != 0) {
        printf("found a number. Press CTL + C to exit\n");
        while(1) {}
    }
}

void process_for_write()
{
    int i;
    while(1) {

        i = s.semaphoreLock(0);
        if(i == 0) {
            printf("Resource locked.......\n");
            critical_resource();
            s.semaphoreUnLock(0);
            printf("Resource unlocked.......\n");
        }
        sleep(1);
    }
}

void process_exit(int exitNum)
{
    s.removeSemaphore();
    exit(1);
}

void init_process_one()
{
    if(fork() == 0) {
        printf("pid is %d\n", getpid());
        signal(SIGINT, process_exit);
        process_for_write();
        while(1);
    }
}

void init_process_two()
{
    if(fork() == 0) {
        printf("pid is %d\n", getpid());
        signal(SIGINT, process_exit);
        process_for_write();
        while(1);
    }
}

int main()
{
    signal(SIGINT, SIG_DFL);
    signal(SIGINT, process_exit);
    s.initSemaphore(2000, 1);
    s.setSemaphoreValue();
    init_process_one();
    init_process_two();
    while(1);
    return 0;
}
