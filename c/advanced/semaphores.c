// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
  
sem_t mutex;
int global_int;

void* thread(void* arg)
{
    char* string_arg = (char*)arg;
    //wait
    sem_wait(&mutex);
    printf("\nEntered %s..\n",string_arg);
    printf("The value of global int is %d\n", global_int);  
    //critical section
    sleep(4);
    
    printf("Global int was updated to %d\n", ++global_int);
    //signal
    printf("\nJust Exiting %s...\n",string_arg);
    sem_post(&mutex);
}
  
  
int main()
{
    global_int = 0;
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    char s1[]="Thread number one";
    char s2[]="Thread number two";
    pthread_create(&t1,NULL,thread,(char*)s1);
    sleep(2);
    pthread_create(&t2,NULL,thread,(char*)s2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}
