#include <openssl/evp.h>
#include <openssl/scrypt.h>
#include <string.h>

unsigned char *Hash_Pass_1(const char *password) {
    unsigned char *hash = malloc(EVP_MAX_MD_SIZE);
    EVP_MD_CTX *mdctx;
    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, EVP_md5(), NULL);
    EVP_DigestUpdate(mdctx, password, strlen(password));
    unsigned int hash_len;
    EVP_DigestFinal_ex(mdctx, hash, &hash_len);
    EVP_MD_CTX_destroy(mdctx);

    return hash;
}

unsigned char *Hash_Pass_2(const char *password) {
    unsigned char *hash = malloc(64);
    int ret = scrypt((const uint8_t *)password, strlen(password), NULL, 0, 1<<14, 8, 1, hash, 64);
    if (ret != 0) {
        free(hash);
        return NULL;
    }

    return hash;
}

int main() {
    const char *password = "123Pass";

    // generate the hash for MyPassword and store it in a variable called MyHash
    unsigned char *hash1 = Hash_Pass_1(password);
    unsigned char *hash2 = Hash_Pass_2(password);

    // print the hash
    for (int i = 0; i < 16; i++) {
        printf("%02x", hash1[i]);
    }
    printf("