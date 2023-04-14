#include <openssl/dh.h>

DH *dh;
// Generate a DH key
dh_key = DH_generate_parameters(1024,DH_GENERATOR_2,NULL,0,NULL,NULL,NULL);