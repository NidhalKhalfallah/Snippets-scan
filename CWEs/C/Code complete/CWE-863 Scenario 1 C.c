#include <fcgi_stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  while (FCGI_Accept() >= 0) {
    char *user = getenv("HTTP_USER");
    char *password = getenv("HTTP_PASSWORD");
    char *requester_user = getenv("HTTP_REQUESTER_USER");
    //The requester_user wants to set pass as a new password for user
if (user && password && requester_user) {
      printf("Content-type: text/html\r");
      printf("