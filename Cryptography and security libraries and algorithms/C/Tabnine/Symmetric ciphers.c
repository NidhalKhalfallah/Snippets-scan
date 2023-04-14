#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

unsigned char key[32];
RAND_bytes(key, 32);
EVP_CIPHER_CTX *ctx;
ctx = EVP_CIPHER_CTX_new();

EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);
