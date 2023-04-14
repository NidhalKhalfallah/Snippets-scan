#include <stdio.h>
#include <string.h>

const char* ALLOWED_ROLES[2] = {"user", "admin"};

void create_user(const char* username, const char* password, const char* role) {
//create a user
    char* user_id = NULL;
    char* user_name = NULL;
    char* user_password = NULL;
    char* user_role = NULL;

    user_id = (char*)malloc(strlen(username) + 1);
    strcpy(user_id, username);
    user_name = (char*)malloc(strlen(username) + 1);
    strcpy(user_name, username);
    user_password = (char*)malloc(strlen(password) + 1);
    strcpy(user_password, password);
    user_role = (char*)malloc(strlen(role) + 1);
    strcpy(user_role, role);
    printf("user_id: %s\n", user_id);

    if (add_user(user_id, user_name, user_password, user_role)!= 0) {
        printf("Error creating user\n");
    } else {
        printf("User created successfully\n");
    }
    free(user_id);
    free(user_name);
    free(user_password);
    free(user_role);
    return;

    return;
}