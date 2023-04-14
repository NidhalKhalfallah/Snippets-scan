#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <bcrypt.h>
bool verify_password(const char *password) {
        //verify if the password is correct
    char hash[BCRYPT_HASHSIZE];
    char password_from_db[MAX_PASSWORD_SIZE];
    /* Get the password hash from the database */
    /* ... */
    /* Verify the password */
    if (bcrypt_hashpw(password, hash) == 0 &&
        bcrypt_checkpw(password_from_db, hash) == 0) {
        return true;
    } else {
        return false;
    }
}