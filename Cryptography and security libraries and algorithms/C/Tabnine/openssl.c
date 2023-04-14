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
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, STDIN_FILENO);
    X509 *cert = SSL_get_certificate(ssl);
    if (SSL_get_verify_result(ssl) == X509_V_OK) {
        printf("Certificate verified.\n");
    } else {
        printf("Certificate verification failed.\n");
    }
    X509_free(cert);
    SSL_CTX_free(ctx);
    SSL_free(ssl);
    return 0;
}