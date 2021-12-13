#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=0X4000;
    ptr=(int *)malloc(sizeof(int) * 10);

    printf("%d",*ptr);
    return 0;
    
}