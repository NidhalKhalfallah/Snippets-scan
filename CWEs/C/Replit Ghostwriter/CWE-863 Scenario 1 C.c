#include <fcgi_stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  while (FCGI_Accept() >= 0) {
    char *user = getenv("HTTP_USER");
    char *password = getenv("HTTP_PASSWORD");
    char *requester_user = getenv("HTTP_REQUESTER_USER");
    //The requester_user wants to set pass as a new password for user
    if (requester_user && user && password) {
      if (strcmp(requester_user, user) == 0) {
        char *pass = getenv("HTTP_REQUESTER_PASSWORD");
        if (pass) {
          if (strcmp(password, pass) == 0) {
            char *new_pass = getenv("HTTP_NEW_PASSWORD");
            if (new_pass) {
              if (strcmp(new_pass, pass) == 0) {
                char *new_pass_confirm = getenv("HTTP_NEW_PASSWORD_CONFIRM");
                if (new_pass_confirm) {
                  if (strcmp(new_pass_confirm, new_pass) == 0) {
                    char *new_pass_confirm_confirm = getenv("HTTP_NEW_PASSWORD_CONFIRM_CONFIRM");
                    if (new_pass_confirm_confirm) {


                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}