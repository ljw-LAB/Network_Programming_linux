#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_Handling(char* message);

int main(int argc, char** argv)
{
    int tcp_sock, udp_sock;
    int sock_type = -1;
    socklen_t optlen;
    int state;

    optlen = sizeof(sock_type);
    tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
    udp_sock = socket(PF_INET, SOCK_DGRAM, 0);

    printf("SOCK_STREAM : %d \n", SOCK_STREAM);
    printf("SOCK_DGGRAM : %d \n", SOCK_DGRAM);

    state = getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, &sock_type, &optlen);
    if(state)
        error_Handling("getsockopt() error!");
    
    printf("첫 번째 소켓의 타입은 %d \n", sock_type);

    state = getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, &sock_type, &optlen);
    if(state)
        error_Handling("getsockopt() error!");
    
    printf("두 번째 소켓의 타입은 %d \n", sock_type);

    return 0;
}

void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}