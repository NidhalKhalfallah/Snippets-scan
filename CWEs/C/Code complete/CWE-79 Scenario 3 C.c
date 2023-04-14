#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

int main(int argc, char *argv[]) {
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/test/password");

    res = curl_easy_perform(curl);
    //Verify that the password is correct and send it back to the client
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s
      curl_easy_cleanup(curl);
      curl_global_cleanup();
    }
  }

  return 0;
}