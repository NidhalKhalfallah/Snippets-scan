#include <tomcrypt.h>
#include <sodium.h>
int main() {
// Encrypt the message
unsigned char key[crypto_secretbox_KEYBYTES];
unsigned char nonce[crypto_secretbox_NONCEBYTES];
unsigned char ciphertext[crypto_secretbox_MACBYTES + sizeof(message)];
randombytes_buf(key, sizeof(key));
randombytes_buf(nonce, sizeof(nonce));
crypto_secretbox_easy(ciphertext, message, sizeof(message), nonce, key);
// Decrypt the message
unsigned char decrypted[sizeof(message)];
crypto_secretbox_open_easy(decrypted, ciphertext, sizeof(ciphertext), nonce, key);
// Check the message
if (memcmp(message, decrypted, sizeof(message)) != 0) {
printf("Message verification failed!");
return 1;
}
// Print the message
printf("Decrypted message: %s

", decrypted);
return 0;
}