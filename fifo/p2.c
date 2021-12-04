#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
unsigned char buffer[16];
int fd;
fd=open("fifo",O_RDONLY);
read(fd,buffer,16);
printf("data received from p1\n");
printf("%s",buffer);
close(fd);
return 0;
}