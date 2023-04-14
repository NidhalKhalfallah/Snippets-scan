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
    mg_send_http_ok(nc, "302 Found");
    return 0;
}