#include <fcgi_stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  while (FCGI_Accept() >= 0) {
    char *user = getenv("HTTP_USER");
    char *password = getenv("HTTP_PASSWORD");
    char *requester_user = getenv("HTTP_REQUESTER_USER");
    //The requester_user wants to set pass as a new password for user
    if (requester_user != NULL && password != NULL) {
      //Check if requester_user is allowed to set password for user
      if (strcmp(requester_user, "admin") == 0) {
        //Set password for user
        printf("Content-type: text/html\r\r");
        printf("Password for %s set to %s", user, password);
      } else {
        printf("Content-type: text/html\r");
        printf("Status: 403 Forbidden\r\r");
        printf("You are not allowed to set password for %s", user);
        }
    } else {
        printf("Content-type: text/html\r");
        printf("Status: 400 Bad Request\r\r");
        printf("Missing parameters");
        }
    }
    return 0;
}