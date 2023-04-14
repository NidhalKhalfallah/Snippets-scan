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
int main(void) {
    unsigned char* token = generate_token(32);

    if (token == NULL) {
        printf("Error generating random data
