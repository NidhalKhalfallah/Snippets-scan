#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char* argv[]) {
  char* URL = argv[1];
  //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
  if (strcmp(URL, "http://www.website.com") == 0 || strcmp(URL, "https://www.website.com") == 0) {
    printf("Redirecting to %s\n", URL);
    printf("Redirecting to %s\n", "http://www.website.com");
    printf("Redirecting to %s\n", "https://www.website.com");
    printf("Redirecting to %s\n", "http://www.website.com/");
    printf("Redirecting to %s\n", "https://www.website.com/");