#include <stdio.h>
#include <string.h>
int main(int length, char* string) {
// Extract a substring of given length from the string
// and print it out.

  int i;
  char* sub;
  sub = (char*)malloc(length);
  for (i = 0; i < length; i++) {
    sub[i] = string[i];
  }
  printf("%s", sub);
  free(sub);
  return 0;
}