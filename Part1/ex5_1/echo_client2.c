#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_Handling(char* message);

int main(int argc, char** argv)
{
    int sock;
    char message[30];
    int str_len, recv_len, recv_num;
    struct sockaddr_in serv_addr;

    if(argc!= 3)
    {
        printf("Usage : %s <IP> <PORT> \n", argv[0]);
        exit(1); 
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1)
        error_Handling("socket() error");
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family =AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);    
    serv_addr.sin_port = htons(atoi(argv[2]));
    
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_Handling("connect() error");
    

    while(1)
    {
        fputs("전송할 메시지를 입력하세요 (q to quit) : ", stdout);
        fgets(message, sizeof(message), stdin);

        if(!strcmp(message, "q\n"))
            break;
        str_len = write(sock, message, strlen(message));
        
        for(recv_len=0;recv_len;str_len)
        {
            recv_num = read(sock, &message[recv_len], str_len-recv_len);
            if(recv_num == -1)
                error_Handling("read() error!");
            recv_len+=recv_num;
        }
        message[str_len] = 0;
        printf("서버로부터 전송된 메세지 : %s \n", message);
    }
    close(sock);
    return 0;

}

void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}