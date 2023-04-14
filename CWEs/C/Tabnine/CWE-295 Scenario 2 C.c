#include <stdio.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

const char * Get_SSL_Certificate(SSL *ssl)
{
    X509 *Certificate = SSL_get_peer_certificate(ssl);
    return Certificate;
}
int main(int argc, char* argv[])
{
    //Establish an SSL connection
    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();

    SSL_CTX *ctx = SSL_CTX_new(SSLv23_method());
    SSL *ssl = SSL_new(ctx);
    SSL_CTX_free(ctx);
    ctx = SSL_CTX_new(SSLv23_method());
    SSL_CTX_free(ctx);
    ctx = SSL_CTX_new(SSLv23_method());
    SSL_CTX_free(ctx);

    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    SSL_CTX_free(ctx);

    