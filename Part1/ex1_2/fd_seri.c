#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>

int main(void)
{
    int fdes1, fdes2, fdes3;

    fdes1 = socket(PF_INET, SOCK_STREAM, 0);
    fdes2 = open("test.dat", O_CREAT);
    fdes3 = socket(PF_INET, SOCK_DGRAM, 0);

    printf("첫 번째 파일 디스크립터 : : %d \n", fdes1);
    printf("두 번째 파일 디스크립터 : : %d \n", fdes2);
    printf("세 번째 파일 디스크립터 : : %d \n", fdes3);
    
    close(fdes1);
    close(fdes2);
    close(fdes3);

    return 0;

}