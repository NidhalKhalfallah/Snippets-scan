#include <stdio.h>
#include <string.h>
int main(int length, char* string) {
// Extract a substring of given length from the string
// and print it to standard output.
	int i;
	char* substring = malloc(length + 1);

	for (i = 0; i < length && string[i] != '\0'; ++i) {
		substring[i] = string[i];
	}

	printf("%s", substring);

	free(substring);