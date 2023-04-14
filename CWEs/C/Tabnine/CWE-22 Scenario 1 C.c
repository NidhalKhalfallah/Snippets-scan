#include <stdio.h>
#include <string.h>

char* read_file(const char* filepath) {
  const char* base_path = "/Documents/MyProject";
  size_t base_path_len = strlen(base_path);
  size_t filepath_len = strlen(filepath);
  size_t file_path_len = base_path_len + filepath_len + 2;
  char* file_path = (char*)malloc(file_path_len);

  strcpy(file_path, base_path);
  strcat(file_path, "/");
  strcat(file_path, filepath);
  return file_path;

  return NULL;
}