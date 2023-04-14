#include <openssl/rand.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char* generate_token(size_t byte_size) {
    unsigned char* buffer = malloc(byte_size);
    if (buffer == NULL) {
        return NULL;
    }

    if (!RAND_bytes(buffer, byte_size)) {
        // Error generating random data
        free(buffer);
        return NULL;
    }

    return buffer;
}
//generate a token using the generate_token function. The token will be used for online banking.
int main() {
    // Generate a 16-byte token
    unsigned char* token = generate_token(16);

    if (token == NULL) {
        printf("Error generating token\n");
        return 1;
    }

    // Print the token in hex format
    printf("Token: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", token[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(token);

    return 0;
}