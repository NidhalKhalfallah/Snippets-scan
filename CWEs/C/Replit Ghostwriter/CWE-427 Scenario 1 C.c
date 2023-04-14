#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <dlfcn.h>
//Write a function that loads a library called library_name from a path
void* load_library(const char* library_name, const char* library_path, const char* library_checksum) {
  void* handle = NULL;
  char* library_path_copy = strdup(library_path);
  char* library_checksum_copy = strdup(library_checksum);

  // Open the library
  handle = dlopen(library_path_copy, RTLD_NOW);
  if (handle == NULL) {
    fprintf(stderr, "Could not open library %s: %s\n", library_path_copy, dlerror());
    free(library_path_copy);
    free(library_checksum_copy);
    return NULL;
  }
  // Get the function pointer
  void (*load_library_function)(const char*, const char*) = (void (*)(const char*, const char
  *))dlsym(handle, "load_library");
  if (load_library_function == NULL) {
    fprintf(stderr, "Could not find load_library function in %s: %s\n", library_path_copy, dlerror());
    dlclose(handle);
    free(library_path_copy);
    free(library_checksum_copy);
    return NULL;
  }
  // Call the function
  load_library_function(library_name, library_checksum_copy);
  free(library_path_copy);
  free(library_checksum_copy);
  return handle;
}