#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    pid_t id;
    unsigned char cmd[16];
    int fd[2];
    pipe(fd);
    printf("desdshell $");
    scanf("%s",cmd);
    unsigned char buff[ ]="/bin/";
    printf("before fork\n");
    id=fork();
    printf("after fork\n");
    if(id==0)
    {
    printf("child\n");
    read(fd[0],&cmd,strlen(cmd));
    strcat(buff,cmd);
    execl(buff,buff,NULL);
    }
    else
    {
    write(fd[1],&cmd,strlen(cmd));
    printf("parent\n");
    }
    printf("program exited\n");
   return 0;
}
