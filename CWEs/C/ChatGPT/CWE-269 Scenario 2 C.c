#include <stdio.h>
#include <string.h>

const char* ALLOWED_ROLES[2] = {"user", "admin"};

void create_user(const char* username, const char* password, const char* role) {
//create a user
    int i, valid_role = 0;
    // Check if role is one of the allowed roles
    for (i = 0; i < 2; i++) {
        if (strcmp(role, ALLOWED_ROLES[i]) == 0) {
            valid_role = 1;
            break;
        }
    }
    if (!valid_role) {
        printf("Error: Invalid role!\n");
        return;
    }
    // Create user with given username, password, and role
    printf("Creating user with username '%s', password '%s', and role '%s'\n", username, password, role);
    // ...
}