#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <dlfcn.h>
//Write a function that loads a library called library_name from a path
void* load_library(const char* library_name, const char* library_path, const char* library_checksum) {
    void* handle = dlopen(library_path, RTLD_LAZY);
    if (handle == NULL) {
        fprintf(stderr, "error: unable to open library: %s\n", library_path);
        exit(1);
    }
    void* sym = dlsym(handle, library_checksum);
    if (sym == NULL) {
        fprintf(stderr, "error: unable to find symbol: %s\n", library_checksum);
        exit(1);
    }
    return sym;

    return handle;
}