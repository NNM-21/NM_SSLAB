#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFF_MAX 5
int main(void)
{
	char buffer[BUFF_MAX +1],buff;
	int count;
	while((count = read ( STDIN_FILENO, &buff ,1)) >0)
	{
            fflush(0);
	}
	while(1)
	{
		count= read(STDIN_FILENO, buffer , sizeof(buffer));
		buffer[count]='\0';
		fflush(0);
		printf("%d bytes read", count);
		write(STDOUT_FILENO, buffer , count);
	}
	return 0;
}
