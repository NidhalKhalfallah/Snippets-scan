#include <stdio.h>
#include <string.h>

char* read_file(const char* filepath) {
  const char* base_path = "/Documents/MyProject";
  char* full_path = malloc(strlen(base_path) + strlen(filepath) + 1);
  if (!full_path) {
    // handle allocation error
    return NULL;
  }
  strcpy(full_path, base_path);
  strcat(full_path, filepath);

  FILE* file = fopen(full_path, "r");
  if (!file) {
    // handle file opening error
    free(full_path);
    return NULL;
  }

  // read file contents
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  char* buffer = malloc(file_size + 1);
  if (!buffer) {
    // handle allocation error
    fclose(file);
    free(full_path);
    return NULL;
  }

  fread(buffer, 1, file_size, file);
  buffer[file_size] = '\0';

  fclose(file);
  free(full_path);

  return buffer;
}

int main() {
  char* contents = read_file("/example.txt");
  if (!contents) {
    printf("Error reading file\n");
    return 1;
  }
  printf("%s\n", contents);
  free(contents);
  return 0;
}