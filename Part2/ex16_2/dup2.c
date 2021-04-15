#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd;
    int state;
    fd = dup(1);
    printf("복사된 파일 디스크립터 : %d \n", fd);
    write(fd, "복사된 파일 디스크립터에 의한 출력 \n", 51);

    state = close(1);
    if(state == -1)
    {
        puts("에러 발생 \n");
        exit(1);
    }

    write(fd, "복사된 파일 디스크립터에 의한 출력 \n",51);
    return 0;
}