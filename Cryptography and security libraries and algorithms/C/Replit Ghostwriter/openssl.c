#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <wolfssl/options.h>
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/x509.h>
#include <wolfssl/wolfcrypt/ssl.h>
int main() {
    // Load the certificate
    X509 *cert = PEM_read_X509(cert_file, NULL, NULL, NULL);