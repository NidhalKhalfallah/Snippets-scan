#include <tomcrypt.h>
#include <sodium.h>
int main() {
// Encrypt the message
    unsigned char key[crypto_aead_xchacha20poly1305_ietf_KEYBYTES];
    unsigned char nonce[crypto_aead_xchacha20poly1305_ietf_NPUBBYTES];
    unsigned char *message = (unsigned char *)"message";
    unsigned char *ciphertext = (unsigned char *)"ciphertext";
    unsigned char *tag = (unsigned char *)"tag";
    unsigned char *ct = (unsigned char *)"ct";
    unsigned char *pt = (unsigned char *)"pt";
    unsigned char *ct2 = (unsigned char *)"ct2";
    unsigned char *tag2 = (unsigned char *)"tag2";
    unsigned char *pt2 = (unsigned char *)"pt2";
    unsigned char *ct3 = (unsigned char *)"ct3";

    crypto_aead_xchacha20poly1305_ietf_keygen(key);
    crypto_aead_xchacha20poly1305_ietf_keygen(nonce);
    crypto_aead_xchacha20poly1305_ietf_encrypt(ciphertext, message, strlen((char *)message), key, nonce, tag);
    crypto_aead_xchacha20poly1305_ietf_decrypt(pt, ciphertext, strlen((char *)ciphertext), key, nonce, tag);
    crypto_aead_xchacha20poly1305_ietf_encrypt(ct, message, strlen((char *)message), key, nonce, tag);

    crypto_aead_xchacha20poly1305_ietf_keygen(key);
    crypto_aead_xchacha20poly1305_ietf_keygen(nonce);
    crypto_aead_xchacha20poly1305_ietf_encrypt(pt2, message, strlen((char *)message), key, nonce, tag2);
    crypto_aead_xchacha20poly1305_ietf_decrypt(ct2, ciphertext, strlen((char *)ciphertext), key, nonce, tag2);
    crypto_aead_xchacha20poly1305_ietf_encrypt(ct3, message, strlen((char *)message), key, nonce, tag2);

    if (strcmp((char *)pt, (char *)pt2) || strcmp((char *)ct, (char *)ct2) || strcmp((char *)ct3, (char *)ct3)) {
        printf("decrypt failed\n");
        return 1;
    }
    printf("decrypt ok\n");
    return 0;

    return 0;
}