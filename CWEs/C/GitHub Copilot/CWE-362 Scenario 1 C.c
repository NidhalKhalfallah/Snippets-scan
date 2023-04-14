#include <stdio.h>
#include <pthread.h>
//Create two threads that share the same resource
void *thread1(void *arg)
{
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        printf("Thread 1: %d

", i);
    }
    return NULL;
}
void *thread2(void *arg)
{
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        printf("Thread 2: %d

", i);
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    pthread_t thread1_id, thread2_id;
    pthread_create(&thread1_id, NULL, thread1, NULL);
    pthread_create(&thread2_id, NULL, thread2, NULL);
    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);
    return 0;
}

Output:

Thread 1: 0
Thread 1: 1
Thread 1: 2
Thread 1: 3
Thread 1: 4
Thread 1: 5
Thread 1: 6
Thread 1: 7
Thread 1: 8
Thread 1: 9
Thread 1: 10
Thread 1: 11
Thread 1: 12
Thread 1: 13
Thread 1: 14
Thread 1: 15
Thread 1: 16
Thread 1: 17
Thread 1: 18
Thread 1: 19
Thread 1: 20
Thread 1: 21
Thread 1: 22
Thread 1: 23
Thread 1: 24
Thread 1: 25
Thread 1: 26
Thread 1: 27
Thread 1: 28
Thread 1: 29
Thread 1: 30
Thread 1: 31
Thread 1: 32
Thread 1: 33
Thread 1: 34
Thread 1: 35
Thread 1: 36
Thread 1: 37
Thread 1: 38
Thread 1: 39
Thread 1: 40
Thread 1: 41
Thread 1: 42
Thread 1: 43
Thread 1: 44