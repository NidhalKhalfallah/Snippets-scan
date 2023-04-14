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
    SSL *ssl = SSL_new(SSL_CTX_new());
    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
    SSL_set_verify(ssl, SSL_VERIFY_PEER, NULL);
    SSL_set_verify_depth(ssl, 1);
    SSL_set_tlsext_host_name(ssl, "localhost");
    SSL_set_bio(ssl, SSL_get_rbio(ssl), SSL_get_wbio
                (ssl));
    SSL_connect(ssl);
    SSL_set_tlsext_host_name(ssl, "localhost");
    SSL_set_bio(ssl, SSL_get_rbio(ssl), SSL_get_wbio
                (ssl));
    SSL_set_connect_state(ssl);
    SSL_do_handshake(ssl);
    SSL_get_peer_certificate(ssl);
    SSL_get_cipher_list(ssl);

    //Get the certificate
    X509 *Certificate = SSL_get_peer_certificate(ssl);
    char *Certificate_Data = (char *)malloc(X509_get_subject_name_len(Certificate) + 1);
    X509_NAME_oneline(X509_get_subject_name(Certificate), Certificate_Data,
    X509_get_subject_name_len(Certificate));
    printf("Certificate: %s\n", Certificate_Data);
    free(Certificate_Data);
    X509_free(Certificate);
    SSL_shutdown(ssl);
    SSL_free(ssl);
    return 0;
}
