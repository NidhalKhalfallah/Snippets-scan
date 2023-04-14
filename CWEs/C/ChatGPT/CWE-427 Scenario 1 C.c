#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <dlfcn.h>
//Write a function that loads a library called library_name from a path
void* load_library(const char* library_name, const char* library_path, const char* library_checksum) {
    void* handle;
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    FILE* fp;
    int i;

    // Open the library file
    fp = fopen(library_path, "rb");
    if (!fp) {
        perror("Error opening library file");
        return NULL;
    }

    // Calculate the SHA256 checksum of the library file
    SHA256_Init(&sha256);
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp))) {
        SHA256_Update(&sha256, buffer, bytes_read);
    }
    SHA256_Final(digest, &sha256);
    fclose(fp);

    // Compare the calculated checksum with the expected checksum
    char checksum_str[SHA256_DIGEST_LENGTH * 2 + 1];
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&checksum_str[i * 2], "%02x", (unsigned int)digest[i]);
    }
    checksum_str[SHA256_DIGEST_LENGTH * 2] = '\0';

    if (strcmp(checksum_str, library_checksum) != 0) {
        printf("Error: checksum mismatch for library %s\n", library_name);
        return NULL;
    }

    // Load the library
    handle = dlopen(library_path, RTLD_LAZY);
    if (!handle) {
        perror("Error loading library");
        return NULL;
    }

    return handle;
}