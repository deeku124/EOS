#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
int fd;
fd=open("fifo",O_WRONLY);
write(fd,"iam deekshitha\n",16);
printf("data sent to p2\n");
close(fd);
return 0;
}