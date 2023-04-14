#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char* malicious_characters = ";&|><$\\";
  //Execute a file as a shell command based on user input

  char* file_name = "";

  printf("Enter the file name: ");
  scanf("%s", &file_name);

  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  char* buffer = (char*)malloc(sizeof(char) * 1024);
  int buffer_size = 1024;
  int bytes_read = 0;

  while ((bytes_read = fread(buffer, sizeof(char), buffer_size, file)) > 0) {
    for (int i = 0; i < bytes_read; i++) {
      if (strchr(malicious_characters, buffer[i])) {
        printf("%c", buffer[i]);
      }
    }
  }
  fclose(file);
  free(buffer);
  return 0;
}
