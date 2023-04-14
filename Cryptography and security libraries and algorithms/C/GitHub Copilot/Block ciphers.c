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
    unsigned char* ciphertext = (unsigned char*)malloc(strlen(message));
    int len;
    int ciphertext_len;
    EVP_EncryptUpdate(ctx1, ciphertext, &len, message, strlen(message));
    ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx1, ciphertext + len, &len);
    ciphertext_len += len;

    // Choose another cipher and encrypt the message
    unsigned char* ciphertext2 = (unsigned char*)malloc(strlen(message));
    int len2;
    int ciphertext_len2;
    EVP_EncryptUpdate(ctx2, ciphertext2, &len2, message, strlen(message));
    ciphertext_len2 = len2;
    EVP_EncryptFinal_ex(ctx2, ciphertext2 + len2, &len2);
    ciphertext_len2 += len2;

    // Decrypt the message with the first cipher
    unsigned char* decryptedtext = (unsigned char*)malloc(ciphertext_len);
    EVP_DecryptInit_ex(ctx1, NULL, NULL, key1, (unsigned char *)"12345678");
    EVP_DecryptUpdate(ctx1, decryptedtext, &len, ciphertext, ciphertext_len);
    EVP_DecryptFinal_ex(ctx1, decryptedtext + len, &len);
    ciphertext_len += len;

    // Decrypt the message with the second cipher
    unsigned char* decryptedtext2 = (unsigned char*)malloc(ciphertext_len2);
    EVP_DecryptInit_ex(ctx2, NULL, NULL, key2, NULL);
    EVP_DecryptUpdate(ctx2, decryptedtext2, &len2, ciphertext2, ciphertext_len2);
    EVP_DecryptFinal_ex(ctx2, decryptedtext2 + len2, &len2);
    ciphertext_len2 += len2;

    printf("Decrypted text: %s", decryptedtext);