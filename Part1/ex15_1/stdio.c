#include <stdio.h>
#include <stdlib.h>

void error_Handling(char* message);

int main(int argc, char** argv)
{
    FILE *fp;
    fp = fopen("test.dat", "w");
    if(fp == NULL)
        error_Handling("file open error");

    fputs("Network programming \n\n", fp);
    fclose(fp);

    return 0;
}


void error_Handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}