#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <bcrypt.h>
bool verify_password(const char *password) {
        //verify if the password is correct
//return true if it is correct and false otherwise

        char hash[100];
        FILE *f = fopen("hash.txt", "r");
        if (f == NULL) {
                printf("Error opening file!");
                exit(1);
        }

        fscanf(f, "%s", hash);
        if (strcmp(hash, password) == 0) {
                return true;
        } else {
                printf("Wrong Password");
                return false;
        }

        fclose(f);
}
