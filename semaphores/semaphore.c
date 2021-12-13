#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

int a,b,sum;
sem_t semp,sems;

void* numbert(void*arg)
{
    printf("entering numbers using semaphore1\n");
    while(1)
    {
    sem_wait(&semp);
    scanf("%d\n",&a);
    scanf("%d\n",&b);
    sem_post(&semp);
    }
}

void* sumth(void*arg)
{
    printf("performin addition in semaphore2");
    while(1)
    {
    sem_wait(&sems);
    sum=a+b;
    printf("sum=%d\n",sum);
    sem_post(&sems); 
    }
}


int main(int argc, const char* argv[])
{
    pthread_t numt;  
    pthread_t sumt; 

    printf("Main thread is starting to execute!\n");
  
    sem_init(&semp,0,1);   
    sem_init(&sems,0,1);   
    printf("S1 number%ld\n", semp.__align);
    printf("S2 number%ld\n",sems.__align);
    pthread_create(&numt,NULL,numbert,NULL); 
    pthread_create(&sumt,NULL,sumth,NULL);

    pthread_join(numt,NULL);  
    pthread_join(sumt,NULL);  
    sem_destroy(&semp);
    sem_destroy(&sems); 

}