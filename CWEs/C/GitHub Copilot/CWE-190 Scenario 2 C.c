#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_SIZE 100

unsigned char* generateKey(const char* password) {
//generate a key using a password from user input
    unsigned char* key = (unsigned char*)malloc(SHA_DIGEST_LENGTH);
    SHA1((unsigned char*)password, strlen(password), key);
    return key;
}