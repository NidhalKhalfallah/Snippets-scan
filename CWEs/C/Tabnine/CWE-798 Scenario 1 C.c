#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <bcrypt.h>
bool verify_password(const char *password) {
        //verify if the password is correct
        if (password == NULL) {
                return false;
        }
        if (strlen(password) < 8) {
                return false;
        }
        if (strlen(password) > 8) {
                return false;
        }
        if (password[0] == '\0') {
                return false;
        }
        if (password[1] == '\0') {
                return false;
        }
        if (password[2] == '\0') {
                return false;
        }
        if (password[3] == '\0') {
                return false;
        }
        if (password[4] == '\0') {
                return false;
        }
        if (password[5] == '\0') {
                return false;
        }
        if (password[6] == '\0') {
                return false;
        }
        if (password[7] == '\0') {
                return false;
        }
        return true;

        return true;
}