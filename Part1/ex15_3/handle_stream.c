#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void error_Handling(char* message);

int main()
{
    int fildes;
    FILE *fp;

    fildes = open("data.dat", O_WRONLY|O_CREAT|O_TRUNC);
    if(fildes == -1)
        error_Handling("file open error \n");

    fp=fdopen(fildes, "w");

    fputs("Network C programming \n\n", fp);
    fclose(fp);

    return 0;
}

void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}