#include <stdio.h>
#include <pthread.h>
//Create two threads that share the same resource
#define NUM_THREADS 2
#define NUM_ITERATIONS 100

void *thread_function(void *arg)
{
  int i;
  for(i=0; i<NUM_ITERATIONS; i++)
    {
      printf("%d\n", i);
    }
  return NULL;
}
int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int i;
  for(i=0; i<NUM_THREADS; i++)
    {
      pthread_create(&threads[i], NULL, thread_function, NULL);
    }
  for(i=0; i<NUM_THREADS; i++)
    {
      pthread_join(threads[i], NULL);
    }
  return 0;
}