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
   
    while(1)
    {
    sem_wait(&semp);
    scanf("%d\n",&a);
    scanf("%d\n",&b);
    sem_post(&sems);
    }

}

void* sumth(void*arg)
{
   
    while(1)
    {
    sem_wait(&sems);
    sum=a+b;
    printf("sum=%d\n",sum);
    sem_post(&semp);
    }
}


int main(int argc, const char* argv[])
{
    pthread_t numt;  
    pthread_t sumt; 

    printf("Main thread execution\n");
  
    sem_init(&semp,0,1);   
    sem_init(&sems,0,0);   
    pthread_create(&numt,NULL,numbert,NULL); 
    pthread_create(&sumt,NULL,sumth,NULL);

    pthread_join(numt,NULL);  
    pthread_join(sumt,NULL);  
    sem_destroy(&semp);
    sem_destroy(&sems); 

}