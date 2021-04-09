#define _XOPEN_SOURCE 200

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void hanlder(int sig);

int main(int argc, char** argv)
{
    int state;
    int num = 0;
    struct sigaction act;
    act.sa_handler = hanlder;
    sigemptyset(&act.sa_mask);
    act.sa_flags =0;

    state = sigaction(SIGINT, &act, 0);
    if(state != 0)
    {
        puts("sigaction() error");
        exit(1);
    }

    while(1)
    {
        printf("%d : 대기중 \n", num++);
        sleep(2);
        if(num > 5) break;
    }
    
    return 0;
}

void hanlder(int sig)
{
    printf("전달된 시그널은 %d \n", sig);
}