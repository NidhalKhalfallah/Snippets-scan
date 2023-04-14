#include <stdio.h>
#include <string.h>

// Extract a substring of given length from the string
void get_substring(char* str, int len) {
    int str_len = strlen(str);
    if (len <= str_len) {
        char substr[len + 1];
        strncpy(substr, str, len);
        substr[len] = '\0';
        printf("Substring: %s\n", substr);
    } else {
        printf("Invalid length!\n");
    }
}

int main() {
    char str[] = "Hello, world!";
    int len = 5;
    get_substring(str, len);

    len = 20;
    get_substring(str, len);

    return 0;
}