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
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    SSL_connect(ssl);
    //Get the certificate
    X509 *Certificate = Get_SSL_Certificate(ssl);
    //Print the certificate
    printf("%s", X509_NAME_oneline(X509_get_subject_name(Certificate), 0, 0));
    //Free the certificate
    X509_free(Certificate);
    //Close the SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    return 0;
}