#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
    
    char *newline;;
    char buffer[200];
    int read_bytes;
    int fd=open(argv[1],O_RDONLY);

    if(fd==1)
	   {
		   printf("Error opening file\n");
	   }
    read_bytes=read(fd, buffer, 200);
    if(read_bytes>0)
    {
	    char *start=buffer;
	    while((newline=strchr(start, '\n'))!=NULL)
	    {
		    *newline='\0';
		    write(STDOUT_FILENO, start, strlen(start));
		    write(STDOUT_FILENO, "\n", strlen(start));
		    start=newline+1;

	    }
    }

    // Close the file
    close(fd);

    return 0;
}

