#include <stdio.h>
#include <pthread.h>
//Create two threads that share the same resource
int count = 0;

void *thread_func(void *arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        count++;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final count: %d\n", count);

    return 0;
}