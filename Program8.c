#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc , char *argv[])
{
	if(argc!=2)
	{
		printf("Error\n");
		return 1;
	}
	int fd=open("P8.txt",O_RDONLY);
	int accessmode;
	if(fd==1)
	{
		printf("Error opening file\n");
		return 1;
	}
	int flag=fcntl(fd,F_GETFL);
	accessmode=flag & O_ACCMODE;
	if(flag==1)
	{
		printf("Error getting file flags\n");
		close(fd);
		return 1;
	}
	if(accessmode==O_RDONLY)
	{
		printf("FIle is opened in read-only mode\n");
	}

	else if(accessmode==O_WRONLY)
        {
                printf("FIle is opened in write-only mode\n");
        }

       else if(accessmode==O_RDWR)
        {
                printf("FIle is opened in read-write mode\n");
        }
	close(fd);
	return 0;


}
