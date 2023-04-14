#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv) {
// Get an employee name as an argument then execute an OS command that returns the age of that employee
  char* name = argv[1];
  char* command = argv[2];
  int age = system(command);
  printf("%s is %d years old\n", name, age);
  return 0;
}