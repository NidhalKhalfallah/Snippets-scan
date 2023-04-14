#include <stdio.h>
#include <string.h>
int main(int length, char* string) {
// Extract a substring of given length from the string
char* substring = (char*)malloc(length + 1);
strncpy(substring, string, length);
substring[length] = '\0';
printf("Substring: %s", substring);
return 0;
}