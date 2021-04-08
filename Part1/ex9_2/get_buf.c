#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_Handling(char* message);

int main(int argc, char** argv)
{
    int sock;

    int snd_buf;
    int rcv_buf;

    int state;
    socklen_t len;

    sock = socket(PF_INET, SOCK_STREAM, 0);

    len = sizeof(snd_buf);
    state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, &snd_buf, &len);
    if(state)
        error_Handling("getsockopt() error");
    
    len = sizeof(rcv_buf);
    state = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &rcv_buf, &len);
    if(state)
        error_Handling("getsockopt() error");

    printf("데이터 입력을 위한 소켓의 버퍼 크기 : %d \n", rcv_buf);
    printf("데이터 출력을 위한 소켓의 버퍼 크기 : %d \n", snd_buf);

    return 0;
}

void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}