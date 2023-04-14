#include <tomcrypt.h>
#include <sodium.h>
int main() {
// Encrypt the message
unsigned char key[crypto_secretbox_KEYBYTES];
    randombytes(key, crypto_secretbox_KEYBYTES);

    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    randombytes(nonce, crypto_secretbox_NONCEBYTES);

    size_t messageLen = strlen("Hello World!");
    unsigned char *message = malloc(messageLen + crypto_secretbox_MACBYTES);

	// Encrypt the message with a key and a nonce.  The result is stored in ciphertext.
	unsigned long long ciphertextLength = messageLen + crypto_secretbox_MACBYTES; // This is the length of our encrypted text (including MAC)
	unsigned char *ciphertext = malloc(ciphertextLength); // Allocate memory to store our encrypted text (including MAC)

	if (crypto_secretbox((unsigned char *) ciphertext, (const unsigned char *) "Hello World!", messageLen, nonce, key) != 0) { // Perform encryption on our plain text using the given parameters.  If successful...
        printf("Error: Could not encrypt!
