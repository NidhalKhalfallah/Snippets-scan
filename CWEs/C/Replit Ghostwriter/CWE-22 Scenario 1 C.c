#include <stdio.h>
#include <string.h>

char* read_file(const char* filepath) {
  const char* base_path = "/Documents/MyProject";
  FILE* fp = fopen(filepath, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: %s\n", filepath);
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  size_t file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char* file_data = (char*)malloc(file_size + 1);
  fread(file_data, 1, file_size, fp);
  fclose(fp);
  file_data[file_size] = '\0';
  return file_data;
}