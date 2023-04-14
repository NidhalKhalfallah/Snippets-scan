#include <gcrypt.h>
#include <sodium.h>
int main(void)
{
    // Hash the message
    if (sodium_init() < 0) {
        printf("Error initializing libsodium\n");
        return 1;
    }

    const char message[] = "This is a secret message";
    unsigned char hash[crypto_generichash_BYTES];
    crypto_generichash(hash, sizeof hash, (const unsigned char *) message, strlen(message), NULL, 0);
    
    printf("Hash of message: ");
    for (int i = 0; i < sizeof hash; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}