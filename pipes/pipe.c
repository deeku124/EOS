#include<stdio.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>



int main()
{
int a,b,sum,result;
int buff1,buff;
pid_t id;
int fd1[2],fd2[2];
pipe(fd1);
pipe(fd2);
printf("enter two numbers\n");
scanf("%d",&a);
scanf("%d",&b);


id=fork();
if(id==0)
{
printf("child reading data from the pipe\n");
read(fd1[0],&buff,sizeof(buff));
printf("data written by parent is:%d\n",buff);
read(fd1[0],&buff1,sizeof(buff1));
printf("data written by parent is:%d\n",buff1);
printf("performing addition\n");
sum=buff+buff1;
write(fd2[1],&sum,sizeof(sum));
printf("addition done and sending sum back to parent\n");
}
else
{
write(fd1[1],&a,sizeof(a));
write(fd1[1],&b,sizeof(b));
printf("sending data to child using pipe\n");
read(fd2[0],&result,sizeof(result));
printf("sum of two numbers is = %d\n",result);
}
return 0;
}