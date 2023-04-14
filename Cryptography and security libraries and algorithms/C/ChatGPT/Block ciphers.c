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
    // Allocate memory for the ciphertext and IV
    int message_len = strlen((char *)message);
    int ciphertext_len = message_len + EVP_CIPHER_CTX_cipher(ctx2)->block_size;
    unsigned char* ciphertext = malloc(ciphertext_len);
    unsigned char* iv = malloc(EVP_CIPHER_CTX_iv_length(ctx2));

    // Generate a random IV
    RAND_bytes(iv, EVP_CIPHER_CTX_iv_length(ctx2));

    // Encrypt the message
    int len;
    EVP_EncryptInit_ex(ctx2, NULL, NULL, NULL, iv);
    EVP_EncryptUpdate(ctx2, ciphertext, &len, message, message_len);
    int ciphertext_len1 = len;
    EVP_EncryptFinal_ex(ctx2, ciphertext + len, &len);
    ciphertext_len1 += len;

    // Get the tag
    unsigned char tag[EVP_MAX_BLOCK_LENGTH];
    EVP_CIPHER_CTX_ctrl(ctx2, EVP_CTRL_GCM_GET_TAG, 16, tag);

    // Print the ciphertext, IV, and tag
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len1; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    printf("IV: ");
    for (int i = 0; i < EVP_CIPHER_CTX_iv_length(ctx2); i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");

    printf("Tag: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", tag[i]);
    }
    printf("\n");

    // Free memory
    free(ciphertext);
    free(iv);
    EVP_CIPHER_CTX_free(ctx2);

    return 0;
}