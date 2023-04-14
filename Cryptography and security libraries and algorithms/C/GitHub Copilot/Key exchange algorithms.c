#include <openssl/dh.h>

DH *dh;
// Generate a DH key
dh_key = DH_generate_parameters( 1024, 2, NULL, NULL );