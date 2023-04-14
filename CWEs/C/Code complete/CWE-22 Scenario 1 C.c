#include <stdio.h>
#include <string.h>

char* read_file(const char* filepath) {
  const char* base_path = "/Documents/MyProject";
  char* filepath_with_base = malloc(strlen(filepath) + strlen(base_path));
  sprintf(filepath_with_base, "%s%s", base_path, filepath);

  FILE *fp;
  fp = fopen(filepath_with_base, "r");

  if (fp == NULL) {
    printf("Could not open %s
