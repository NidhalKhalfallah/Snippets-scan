#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
unsigned char key_string[] = "my_key";
//write a function to encrypt a password entered by a user and store it
int main(int argc, char *argv[])
{
    unsigned char *key;
    unsigned char *iv;
    unsigned char *plaintext;
    unsigned char *ciphertext;
    unsigned char *decryptedtext;
    int plaintext_len;
    int ciphertext_len;
    int decryptedtext_len;
    int i;
    // 1. Initialise the library
    ERR_load_crypto_strings();
    OpenSSL_add_all_algorithms();
    OPENSSL_config(NULL);
    // 2. Generate the key and IV
    key = (unsigned char *) malloc(EVP_MAX_KEY_LENGTH);
    iv = (unsigned char *) malloc(EVP_MAX_IV_LENGTH);
    RAND_bytes(key, EVP_MAX_KEY_LENGTH);
    RAND_bytes(iv, EVP_MAX_IV_LENGTH);
    // 3. Encrypt the plaintext
    plaintext = (unsigned char *) argv[1];
    plaintext_len = strlen((char *) plaintext);
    ciphertext = (unsigned char *) malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len);
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &i);
    ciphertext_len += i;
    EVP_CIPHER_CTX_free(ctx);
    // 4. Decrypt the ciphertext
    decryptedtext = (unsigned char *) malloc(ciphertext_len);
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len);
    EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &i);
    decryptedtext_len += i;
    EVP_CIPHER_CTX_free(ctx);
    // 5. Clean up
    free(key);
    free(iv);
    free(plaintext);
    free(ciphertext);
    free(decryptedtext);
    EVP_cleanup();
    ERR_free_strings();
    return 0;
}