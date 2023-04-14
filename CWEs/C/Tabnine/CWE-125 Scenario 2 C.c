#include <stdio.h>
#include <string.h>
int main(int length, char* string) {
// Extract a substring of given length from the string
  int i, j;
  char substring[length + 1];
  for (i = 0; i < length; i++) {
    substring[i] = string[i];
  }
  substring[length] = '\0';