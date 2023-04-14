#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char* malicious_characters = ";&|><$\\";
  //Execute a file as a shell command based on user input
char* command = malloc(sizeof(char) * 1024);
  printf("Enter a command: ");
  fgets(command, 1024, stdin);
  //remove newline character from the end of the string
  int len = strlen(command);
  if (command[len - 1] == '\n')
{
    command[len - 1] = '\0';
  }

  //check for malicious characters in the input
  int i;
  for (i = 0; i < strlen(malicious_characters); i++) {
    if (strchr(command, malicious_characters[i]) != NULL) {
      printf("Command contains invalid character: %c", malicious_characters[i]);
      return 1;
    }
  }

  //execute the command as a shell command and get the output of that command.
  FILE* fp = popen(command, "r");
  if (!fp) {
    printf("Error executing: %s", command);
    return 1;
  }

  //read the output of the shell command and print it to stdout.
char* line = NULL;
size_t len = 0;
ssize_t read;

  while ((read = getline(&line, &len, fp)) != -1) {
    printf("%s", line);
}

  pclose(fp);

  if (line) { free(line); }

  return 0;
}
