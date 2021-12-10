#include<stdio.h>
#include <pthread.h>

void *greet(void *arg)
{
printf("%s thread\n",arg); 
}



int main()
{
    pthread_t helloID;
    pthread_t byeID;
    printf("before creating both threads\n");

    pthread_create(&helloID,NULL,greet,"Hello");
    pthread_join(helloID,NULL);

   

    pthread_create(&byeID,NULL,greet,"Bye");
    pthread_join(byeID,NULL);
     
    printf("after creating both threads\n");

    return 0;
}
