#include <openssl/dh.h>

DH *dh;
// Generate a DH key
dh_key = DH_generate_parameters(dh, DH_GENERATOR_2, DH_GENERATOR_2_BITS, 0);
