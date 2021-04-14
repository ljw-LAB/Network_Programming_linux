#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void error_Handling(char* message);

int main(int argc, char** argv)
{
    int fildes;
    char str[] = "socket programming \n\n";

    fildes = open("data.daa", O_WRONLY|O_CREAT|O_TRUNC);
    if(fildes == -1)
        error_Handling("file open error");
    
    write(fildes, str, sizeof(str)-1);
    close(fildes);
    return 0;
}

void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}