#include <stdio.h>
#include <string.h>

char* read_file(const char* filepath) {
  const char* base_path = "/Documents/MyProject";
    char* full_path = malloc(strlen(base_path) + strlen(filepath) + 1);
    strcpy(full_path, base_path);
    strcat(full_path, filepath);
    FILE* file = fopen(full_path, "r");
    free(full_path);
    if (file == NULL) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    fclose(file);
    buffer[size] = '\0';
    return buffer;
}