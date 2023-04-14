#include <stdio.h>
#include <string.h>

const char* ALLOWED_ROLES[2] = {"user", "admin"};

void create_user(const char* username, const char* password, const char* role) {
//create a user
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s username password role

", argv[0]);
        return 1;
    }

    const char* username = argv[1];
    const char* password = argv[2];
    const char* role = argv[3];

    for (int i = 0; i < 2; i++) {
        if (strcmp(role, ALLOWED_ROLES[i]) == 0) {
            create_user(username, password, role);
            return 0;
        }
    }
    return 1;
}