#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
unsigned char key_string[] = "my_key";
//write a function to encrypt a password entered by a user and store it
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

void encrypt_password(char* password) {
    // Generate a random salt
    unsigned char salt[EVP_MAX_SALT_LEN];
    if (RAND_bytes(salt, EVP_MAX_SALT_LEN) == 0) {
        printf("Error generating random salt\n");
        return;
    }

    // Derive a key from the password using PBKDF2
    unsigned char key[EVP_MAX_KEY_LENGTH];
    if (PKCS5_PBKDF2_HMAC(password, strlen(password), salt, EVP_MAX_SALT_LEN, 1000, EVP_sha256(), EVP_MAX_KEY_LENGTH, key) == 0) {
        printf("Error deriving key\n");
        return;
    }

    // Encrypt the password using AES-256-CBC
    unsigned char iv[EVP_MAX_IV_LENGTH];
    if (RAND_bytes(iv, EVP_MAX_IV_LENGTH) == 0) {
        printf("Error generating random IV\n");
        return;
    }
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    unsigned char* ciphertext = (unsigned char*) malloc(strlen(password) + EVP_MAX_BLOCK_LENGTH);
    int len;
    int ciphertext_len;
    EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char*) password, strlen(password));
    ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);

    // Print the salt, IV, and ciphertext to the console
    printf("Salt: ");
    for (int i = 0; i < EVP_MAX_SALT_LEN; i++) {
        printf("%02x", salt[i]);
    }
    printf("\nIV: ");
    for (int i = 0; i < EVP_MAX_IV_LENGTH; i++) {
        printf("%02x", iv[i]);
    }
    printf("\nCiphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    free(ciphertext);
}

int main(int argc, char* argv[]) {
    char* password = "my_password";
    encrypt_password(password);
    return 0;
}