#include <openssl/dh.h>

DH *dh;

// Generate a DH key
dh = DH_new();
DH_generate_parameters_ex(dh, 2048, DH_GENERATOR_2, NULL);
DH_generate_key(dh);