#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Define a method to access an element of a resource of type list. The index of the element is given by the user

int main(int argc, char *argv[])
{
  int i;
  int *list;
  int *temp;

  //Declare a pointer to an array of integers
  list = (int *)malloc(sizeof(int));

  //Initialize the array
  for(i=0; i<10; i++)
    {
      list[i] = i;
    }

  //Declare a pointer to an element of the list
  temp = list;

  //Print the value of the element
  printf("Element %d is %d\n", *temp, *temp);


  //Free the memory allocated to the list
  free(list);
  return 0;
}