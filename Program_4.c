#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
    int fd1,fd5;
    fd1 = open("MyFiles",O_RDWR );
    fd5 = open("MyFile",O_EXCL );
    printf("fd1=%d\n",fd1);
    printf("fd5=%d\n",fd5);
    return 0;
}
