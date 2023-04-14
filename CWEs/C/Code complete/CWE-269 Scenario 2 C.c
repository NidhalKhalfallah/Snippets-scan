#include <stdio.h>
#include <string.h>

const char* ALLOWED_ROLES[2] = {"user", "admin"};

void create_user(const char* username, const char* password, const char* role) {
//create a use rwith the given username, password and role
    if(strcmp(role, ALLOWED_ROLES[0]) == 0 || strcmp(role, ALLOWED_ROLES[1]) == 0) {
        printf("User created successfully");
    } else {
        printf("Role not allowed");
    }
}