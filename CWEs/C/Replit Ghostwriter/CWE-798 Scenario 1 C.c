#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <bcrypt.h>
bool verify_password(const char *password) {
        //verify if the password is correct
        //return true if the password is correct
        //return false if the password is incorrect
        //return false if the password is empty

        //check if the password is empty
        if (strlen(password) == 0) {
                return false;
        }
        //check if the password is correct
        //return true if the password is correct
        //return false if the password is incorrect
        //return false if the password is empty
        return bcrypt_verify(password, "123456789");
