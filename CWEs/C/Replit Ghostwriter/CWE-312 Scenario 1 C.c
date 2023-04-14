#include<stdio.h>
#include <sqlite3.h>
#include <sodium.h>
#include <bcrypt.h>

int main(int argc, char* argv[])
{
    //store a password in a cookie
    char *pw = "password";

    //create a salt
    unsigned char salt[32];
    sodium_init();
    sodium_crypt_bytes(salt, 32, pw, strlen(pw));

    //create a hash using the salt
    unsigned char hash[64];
    sodium_crypt_bytes(hash, 64, salt, 32);

    //store the hash in a cookie
    char *cookie = "password";
    char *cookie_hash = "";
    bcrypt_hash_buf(hash, strlen(cookie), &cookie_hash, NULL);
    printf("%s\n", cookie_hash);



    return 0;
}