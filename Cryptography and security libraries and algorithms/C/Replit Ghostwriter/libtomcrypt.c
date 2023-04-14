#include <tomcrypt.h>
#include <sodium.h>
int main() {
// Encrypt the message
  int rc = 0;
  unsigned char ciphertext[crypto_aead_chacha20poly1305_ietf_ABYTES];
  unsigned char plaintext[crypto_aead_chacha20poly1305_ietf_ABYTES];
  unsigned char nonce[crypto_aead_chacha20poly1305_ietf_NPUBBYTES];
  unsigned char tag[crypto_aead_chacha20poly1305_ietf_ABYTES];
  unsigned char key[crypto_aead_chacha20poly1305_ietf_KEYBYTES];


  rc = crypto_aead_chacha20poly1305_ietf_keygen(key, nonce);
  if (rc!= 0) {
    printf("crypto_aead_chacha20poly1305_ietf_keygen failed\n");
    return 1;
  }
  printf("keygen succeeded\n");
  printf("nonce: ");
  for (int i=0; i<crypto_aead_chacha20poly1305_ietf_NPUBBYTES; i++) {
    printf("%02x", nonce[i]);
  }
  printf("\n");
  printf("key: ");
  for (int i=0; i<crypto_aead_chacha20poly1305_ietf_KEYBYTES; i++) {
    printf("%02x", key[i]);
  }
  printf("\n");