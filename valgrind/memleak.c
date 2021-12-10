#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr=NULL;
    ptr= (int *)malloc(sizeof(int) * 10);
    free(ptr);
    return 0;
}