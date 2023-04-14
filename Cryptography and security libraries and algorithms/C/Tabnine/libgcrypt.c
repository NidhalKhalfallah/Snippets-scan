#include <gcrypt.h>
#include <sodium.h>
int main() {
// Hash the message
    unsigned char hash[crypto_hash_sha512_BYTES];
    crypto_hash_sha512(hash, message, strlen(message));

    // Verify the hash
    if (crypto_verify_32(hash, crypto_hash_sha512_BYTES, signature)!= 0) {
        return 1;

        // If the verification failed, the signature is invalid
    } else {
        return 0;
        // If the verification succeeded, the signature is valid
        // and the message was valid
        // Note that the signature is not verified again
        // after the message is verified
        // because the signature is verified after
        // the message is verified
        // and the signature is not verified again
        // after the message is verified