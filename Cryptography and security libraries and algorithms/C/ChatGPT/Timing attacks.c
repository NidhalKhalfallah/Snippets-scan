#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <string.h>

int main() {
    const char password[] = "password";
    const char user_input[] = "user-input";
    const int password_len = strlen(password);
    const int user_input_len = strlen(user_input);

    // Generate a SHA-256 hash of the password
    unsigned char password_hash[EVP_MAX_MD_SIZE];
    unsigned int password_hash_len;
    EVP_Digest(password, password_len, password_hash, &password_hash_len, EVP_sha256(), NULL);

    // Generate a SHA-256 hash of the user input
    unsigned char user_input_hash[EVP_MAX_MD_SIZE];
    unsigned int user_input_hash_len;
    EVP_Digest(user_input, user_input_len, user_input_hash, &user_input_hash_len, EVP_sha256(), NULL);

    // Compare the two hashes to authenticate the user
    if (password_hash_len == user_input_hash_len && memcmp(password_hash, user_input_hash, password_hash_len) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed.\n");
    }

    return 0;
}