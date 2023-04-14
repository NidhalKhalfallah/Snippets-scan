#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <dlfcn.h>
//Write a function that loads a library called library_name from a path
void* load_library(const char* library_name, const char* library_path, const char* library_checksum) {
    void* handle;
    char* error;
    handle = dlopen(library_name, RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }
    return handle;
}
int main() {
    void* handle;
    handle = l