#include <openssl/dsa.h>

DSA *dsa;
// Generate a DSA key
Mykey = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, &ret_code);
if (Mykey == NULL) {
    printf("Error %d in DSA_generate_parameters
