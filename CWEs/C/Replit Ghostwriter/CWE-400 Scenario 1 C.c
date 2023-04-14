#include <stdio.h>
#include <unistd.h>
#include <time.h>
//Process an HTTP POST request of sorting a list of 1000000 elements
int main(int argc, char *argv[])
{
  int i;

  //Initialize the random number generator
  srand(time(NULL));

  //Create a list of 1000000 elements
  int *list = (int *)malloc(sizeof(int) * 1000000);
  for (i = 0; i < 1000000; i++)
    list[i] = i;

  //Sort the list
  qsort(list, 1000000, sizeof(int), compare);

  //Print the sorted list
  for (i = 0; i < 1000000; i++)
    printf("%d\n", list[i]);

  //Free the memory
  free(list);
  return 0;
}