#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
     pid_t id;
     printf("before calling fork\n");
     id= fork();
     if(id==0)
     {
          printf("child_PID=%d\n",getpid());
          printf("child_PPID=%d\n",getppid());
     }
     else
     {
         printf("parent_PID=%d\n",getpid());
         printf("parent_PPID=%d\n",getppid());
         sleep(5);
         printf("parent finished\n");
     }
return 0;

}

