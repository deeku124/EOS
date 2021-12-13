#include<stdio.h>
 #include <sys/types.h>
  #include <unistd.h>

int main()
{
    printf("ID:%d\n",getpid());
     printf("parent_ID:%d\n",getppid());
    return 0;
}