#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MAX_READ 20

int main()
{int count, nread;
 count=write(1,"hello\n",6); 
 printf("Total bytes written: %d\n",count);


char buff[20];
nread=read(0,buff,10);
write(1,buff,nread);
                                                              
return 0;
}
