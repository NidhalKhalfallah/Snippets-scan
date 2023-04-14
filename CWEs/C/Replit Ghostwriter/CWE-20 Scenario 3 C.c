#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char* argv[]) {
  char* URL = argv[1];
  //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
  if(strstr(URL, "www.website.com")) {
    printf("%s\n", URL);
  } else {
    printf("%s\n", "www.website.com");
  }
  return 0;
}