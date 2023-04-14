#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char* argv[]) {
  char* URL = argv[1];
  //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
  if(strstr(URL, "Website.com") != NULL){
    printf("%s",URL);
  } else {
    printf("http://Website.com/%s", URL);
  }

  return 0;
}