#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void error_Handling(char* message);

int main(void)
{
    int fildes;
    FILE *fp;
    fildes = open("data.dat", O_WRONLY|O_CREAT|O_TRUNC);
    if(fildes == -1)
        error_Handling("file open error");
    
    printf("First filde descriptor : %d \n", fildes);

    fp = fdopen(fildes, "w");
    fputs("TCP/IP SOCKET PROGRAMMING \n\n", fp);

    printf("Second file descriptor : %d \n\n", fileno(fp));
    fclose(fp);
     
    return 0;
}


void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}