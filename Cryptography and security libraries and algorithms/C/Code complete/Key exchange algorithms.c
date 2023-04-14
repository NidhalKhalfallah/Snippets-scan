#include <openssl/dh.h>

DH *dh;
// Generate a DH key
dh_key = DH_generate_parameters(512, DH_GENERATOR_2, NULL, NULL);
// Generate a key pair
dh = DH_new();
DH_generate_key(dh);