#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char* malicious_characters = ";&|><$\\";
  //Execute a file as a shell command based on user input
  char* command = "ls";
  char* result = shell_exec(command);
  printf("%s\n", result);
  free(result);
  return 0;
}