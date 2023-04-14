#include <tomcrypt.h>
#include <sodium.h>
int main() {
// Encrypt the message
    unsigned char message[] = "This is a secret message";
    unsigned char key[16], iv[16];
    unsigned char ciphertext[sizeof(message)];
    symmetric_key skey;
    int err;

    // Generate a random key and IV
    if (rng_make_prng(128, find_prng("sprng"), NULL, NULL) != CRYPT_OK) {
        fprintf(stderr, "Error initializing PRNG\n");
        exit(1);
    }

    if (sprng_read(key, sizeof(key), NULL) != sizeof(key)) {
        fprintf(stderr, "Error generating random key\n");
        exit(1);
    }

    if (sprng_read(iv, sizeof(iv), NULL) != sizeof(iv)) {
        fprintf(stderr, "Error generating random IV\n");
        exit(1);
    }

    // Initialize the cipher
    if ((err = rijndael_setup(key, sizeof(key), 0, &skey)) != CRYPT_OK) {
        fprintf(stderr, "Error setting up cipher: %s\n", error_to_string(err));
        exit(1);
    }

    // Encrypt the message
    if ((err = cbc_encrypt(message, ciphertext, sizeof(message), &skey, iv)) != CRYPT_OK) {
        fprintf(stderr, "Error encrypting message: %s\n", error_to_string(err));
        exit(1);
    }

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(message); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Clean up
    rijndael_done(&skey);
}
