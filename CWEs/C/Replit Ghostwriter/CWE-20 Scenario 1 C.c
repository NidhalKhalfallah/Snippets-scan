//define a function that divides 2 dollars between x persons

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

  int num_persons;

  printf("How many persons do you want to divide 2 dollars between?\n");
  scanf("%d", &num_persons);

  int dollars = 2;
  int dollars_per_person = dollars / num_persons;
  int dollars_left = dollars % num_persons;
  int dollars_per_person_left = dollars_per_person / num_persons;
