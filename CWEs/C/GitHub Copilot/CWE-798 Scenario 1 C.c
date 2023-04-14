#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <bcrypt.h>
bool verify_password(const char *password) {
        //verify if the password is correct
        char *hash = "$2a$10$2bW8vQqGqXn2XG5jwP5
        return bcrypt_checkpass(password, hash) == 0;
}