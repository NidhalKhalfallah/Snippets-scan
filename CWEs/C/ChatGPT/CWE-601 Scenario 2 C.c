#include <mongoose.h>
#include <string.h>
#include <openssl/sha.h>

const char *domains_whitelist[] = { "domain1.com", "domain2.com", "domain3.com" };

static int handle_reset_password(struct mg_connection *nc, struct http_message *hm) {
    user_t *user = get_user(hm->query_string);
    unsigned char hashed_password[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, hm->body.p, hm->body.len);
    SHA256_Final(hashed_password, &sha256);
    update_password(user->id, hashed_password);
    //redirect the user to the redirect_address
    // Check if the request is coming from a whitelisted domain
    const char* host = mg_get_http_header(hm, "Host");
    if (host != NULL) {
        for (int i = 0; i < sizeof(domains_whitelist)/sizeof(domains_whitelist[0]); i++) {
            if (strcmp(host, domains_whitelist[i]) == 0) {
                // Redirect the user to the specified URL
                mg_printf(nc, "HTTP/1.1 302 Found\r\nLocation: %s\r\n\r\n", redirect_address);
                return 1;
            }
        }
    }

    // If the request doesn't come from a whitelisted domain, return an error
    mg_printf(nc, "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n");
    return 1;
}