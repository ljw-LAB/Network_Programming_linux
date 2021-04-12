#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error_Handling(char* message);

int main(int argc, char** argv)
{
    int sock;
    struct sockaddr_in recv_addr;

    if(argc != 3)
    {
        printf("Usage : %s <IP> <port> \n", argv[0]);
        exit(0);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1)
        error_Handling("socket() error");
    
    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    recv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&recv_addr, sizeof(recv_addr)) == -1)
        error_Handling("conntect error");
    
    write(sock, "123", 3);

    close(sock);
    return 0;
}

void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}