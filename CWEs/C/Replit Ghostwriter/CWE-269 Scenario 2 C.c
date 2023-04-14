#include <stdio.h>
#include <string.h>

const char* ALLOWED_ROLES[2] = {"user", "admin"};

void create_user(const char* username, const char* password, const char* role) {
//create a user
  printf("Creating user %s\n", username);
  if (strcmp(role, "user") == 0) {
    printf("Role is user\n");
  } else if (strcmp(role, "admin") == 0) {
    printf("Role is admin\n");
  } else {
    printf("Role is invalid\n");
  }