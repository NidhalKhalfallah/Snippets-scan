#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

unsigned char key[32];
RAND_bytes(key, 32);
EVP_CIPHER_CTX *ctx;
ctx = EVP_CIPHER_CTX_new();

EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
EVP_EncryptUpdate(ctx, ciphertext, &len1, plaintext, len2);
EVP_EncryptFinal_ex(ctx, ciphertext + len1, &len2);
EVP_CIPHER_CTX_free(ctx);
