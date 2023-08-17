#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
    int fd;
    fd=creat("MyFiles",S_IRUSR | S_IWUSR);
    printf("fd=%d\n",fd);
    return 0;
}
