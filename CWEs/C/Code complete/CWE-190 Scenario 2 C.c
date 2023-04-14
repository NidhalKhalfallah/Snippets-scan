#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_SIZE 100

unsigned char* generateKey(const char* password) {
    //generate a key using a password from user input
    unsigned char* key = malloc(SHA_DIGEST_LENGTH);
	char* passwordCopy = strdup(password);

	memset(key, 0, SHA_DIGEST_LENGTH);

	SHA1((unsigned char*)passwordCopy, strlen(password), key);

	free(passwordCopy);
	return key;
}

