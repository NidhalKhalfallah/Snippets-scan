#include <gcrypt.h>
#include <sodium.h>
int main() {
// Hash the message
  gcry_md_hd_t hash;
  gcry_error_t err;
  err = gcry_md_open(&hash, GCRY_MD_SHA512, 0);
  if (err!= 0) {
    fprintf(stderr, "gcry_md_open failed: %s\n", gcry_strerror(err));
    return 1;
  }
  err = gcry_md_write(hash, "Hello World", 12);
  if (err!= 0) {
    fprintf(stderr, "gcry_md_write failed: %s\n", gcry_strerror(err));
    return 1;
  }
  err = gcry_md_final(hash);
  if (err!= 0) {
    fprintf(stderr, "gcry_md_final failed: %s\n", gcry_strerror(err));
    return 1;
  }
  unsigned char hash_bytes[64];
  err = gcry_md_read(hash, hash_bytes, 64);
  if (err!= 0) {
    fprintf(stderr, "gcry_md_read failed: %s\n", gcry_strerror(err));
    return 1;
  }
  gcry_md_close(hash);