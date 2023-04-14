#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char* malicious_characters = ";&|><$\\";
  //Execute a file as a shell command based on user input
    char* command = malloc(100);
    printf("Enter a command: ");
    scanf("%s", command);
    //Check for malicious characters
    for (int i = 0; i < strlen(malicious_characters); i++) {
        if (strchr(command, malicious_characters[i]) != NULL) {
            printf("Malicious character detected: %c", malicious_characters[i]);
            return 1;
        }
    }
    //Execute the command
    system(command);
    return 0;
}