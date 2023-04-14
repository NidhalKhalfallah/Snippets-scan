#include <gcrypt.h>
#include <sodium.h>
int main() {
// Hash the message
unsigned char hash[crypto_hash_sha512_BYTES];
    crypto_hash(hash, "Hello", 5);

    printf("Hash: %s
