#include<stdio.h>
#include <pthread.h>

void *hello(void *arg)
{
printf("Hi, This is thread. How are you?\n"); 
}

void *bye(void *arg)
{
printf("BYE\n"); 
}


int main()
{
    pthread_t helloID;
    pthread_t byeID;
    printf("before creating the HELLO thread\n");

    pthread_create(&helloID,NULL,hello,NULL);
    pthread_join(helloID,NULL);

    printf("after creating the HELLO thread\n");


    printf("before creating BYE thraed\n");

    pthread_create(&byeID,NULL,bye,NULL);
    pthread_join(byeID,NULL);
     
    printf("after creating the BYE thread\n");

    return 0;
}
