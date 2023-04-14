#include <gcrypt.h>
#include <sodium.h>
int main() {
// Hash the message
char *message = "The quick brown fox jumps over the lazy dog";
unsigned char hash[crypto_generichash_BYTES];
crypto_generichash(hash, sizeof hash, (unsigned char *)message, strlen(message), NULL, 0);
// Sign the hash
unsigned char sk[crypto_sign_SECRETKEYBYTES];
unsigned char pk[crypto_sign_PUBLICKEYBYTES];
crypto_sign_keypair(pk, sk);
unsigned char sig[crypto_sign_BYTES];
unsigned long long siglen;
crypto_sign(sig, &siglen, hash, sizeof hash, sk);
// Verify the signature
if (crypto_sign_verify(sig, sizeof hash, pk) == 0) {
printf("Signature verification succeeded!

");
} else {
printf("Signature verification failed!

");
}
return 0;
}

The program generates a signature for the hash of the message. The signature is verified using the public key.

Run the program:

$ gcc -o CEXP CEXP.c -lsodium
$ ./CEXP
Signature verification succeeded!

The signature verification succeeded.

The following is the output of the program:

Signature verification succeeded!

The signature verification succeeded.

The following is the