#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
int main(int argc, char **argv)
{
  CURL *curl;
  char *data = "{\"username\":\"user\",\"password\":\"pass\"}";
  curl = curl_easy_init();
  if (curl) {
    //grab the user name and password
    curl_easy_setopt(curl, CURLOPT_USERNAME, "user");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "pass");
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }