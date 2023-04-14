#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <dlfcn.h>
//Write a function that loads a library called library_name from a path
void* load_library(const char* library_name, const char* library_path, const char* library_checksum) {
void* library_handle = dlopen(library_path, RTLD_LAZY);
	if (library_handle == NULL) {
		printf("Error: %s", dlerror());
		return NULL;
	} else {
	SHA_CTX ctx;
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_Init(&ctx);

    FILE *fp = fopen(library_name, "rb");
    if (fp == NULL) { return NULL; }

    // Read file in chunks of 4K
    char buffer[4096];
    size_t readBytes = 0;

    while ((readBytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) { SHA256_Update(&ctx, buffer, readBytes); }

   SHA256_Final(hash, &ctx);  // Finalize the computation and store result in hash[]

   int i=0; for (i=0; i<SHA256_DIGEST_LENGTH; i++) printf("%02x", hash[i]); printf("
if (strcmp(library_checksum, hash) != 0) {
	printf("Error: invalid checksum for %s", library_name);
	return NULL;
}

    return library_handle;
}
