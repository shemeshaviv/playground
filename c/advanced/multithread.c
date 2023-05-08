#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>
#include <string.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp)
{
    char* string_arg = (char*)vargp;
    srand(clock());
    int sleep_sec = 3 + (rand() % 7);
    printf(">Starting: %s. Now we sleep randomly\n", string_arg);
    sleep(sleep_sec);     // Sleep between 3 and 10 seconds
    printf("Finishing: %s (after sleeping %d seconds)\n", string_arg, sleep_sec);
 
    char ret_string[100];
    strcpy(ret_string,"Finished ");
    strncat(ret_string,string_arg,strlen(ret_string)+strlen(string_arg));
    pthread_exit(ret_string);
}

int main()
{
    char* msg1 = "Thread number 1";
    char* msg2 = "Thread number 2";
    pthread_t thread_id1, thread_id2;
    void* thread1_retval = NULL;
    void* thread2_retval = NULL;
    printf("Creating Thread\n");
    pthread_create(&thread_id1, NULL, myThreadFun, (char*)msg1);
    pthread_create(&thread_id2, NULL, myThreadFun, (char*)msg2);
    printf("Threads started (id1=%p, id2=%p). Next we run join to let them finish before main finishes\n",
            &thread_id1, &thread_id2); 
    pthread_join(thread_id1, &thread1_retval);
    pthread_join(thread_id2, &thread2_retval);

    printf("Done running threads\n");
    printf("Thread 1 returned with value: %s\n", (char*)thread1_retval);
    printf("Thread 2 returned with value: %s\n", (char*)thread2_retval);
    return 0;
}

/*
Creating Thread
Threads started (id1=0x7ffffb0d5358, id2=0x7ffffb0d5360). Next we run join to let them finish before main finishes
>Starting: Thread number 1. Now we sleep randomly
>Starting: Thread number 2. Now we sleep randomly
Finishing: Thread number 2 (after sleeping 5 seconds)
Finishing: Thread number 1 (after sleeping 8 seconds)
Done running threads
Thread 1 returned with value: Finished Thread number 1
Thread 2 returned with value: Finished Thread number 2
*/
