#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_SIZE 100

unsigned char* generateKey(const char* password) {
//generate a key using a password from user input
    unsigned char key[MAX_PASSWORD_SIZE];
    SHA_CTX ctx;
    unsigned char hash[SHA_DIGEST_LENGTH];
    int i = 0;
    int j = 0;
    int k = 0;
    int iter = 0;
    int passlen = strlen(password);
    unsigned char* pass = (unsigned char*)malloc(passlen);
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, password, passlen);
    SHA1_Final(hash, &ctx);
    for (i = 0; i < SHA_DIGEST_LENGTH; i++) {
        key[i] = hash[i];
    }
    for (i = 0; i < passlen; i++) {
        key[i] ^= hash[i];
    }
    for (i = 0; i < passlen; i++) {
        key[i] = key[i] ^ pass[i];
    }
    free(pass);
    return key;

    /*
    for (i = 0; i < passlen; i++) {
        key[i] = hash[i];
    }
    for (i = 0; i < passlen; i++) {
        key[i] ^= hash[i];
    }
    */
}