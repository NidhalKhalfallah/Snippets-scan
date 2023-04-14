#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[])
{

    unsigned char key1[EVP_MAX_KEY_LENGTH];
    int key1_len = EVP_BytesToKey(EVP_bf_gcm(), EVP_sha1(), NULL,
                                  (unsigned char *)"MY_SECRET_KEY", strlen("MY_SECRET_KEY"), 1, key1, NULL);


    EVP_CIPHER_CTX *ctx1;
    ctx1 = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx1, EVP_bf_gcm(), NULL, key1, (unsigned char *)"12345678");


    unsigned char key2[32];
    RAND_bytes(key2, 32);


    EVP_CIPHER_CTX *ctx2;
    ctx2 = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx2, EVP_aes_256_gcm(), NULL, key2, NULL);

    unsigned char* message = (unsigned char*)"This is my secret message";

    // Choose one cipher and encrypt the message
    unsigned char ciphertext[1024];
    int len;

    EVP_EncryptUpdate(ctx1, ciphertext, &len, message, strlen((char*)message));

    printf("Cipher text: %s
