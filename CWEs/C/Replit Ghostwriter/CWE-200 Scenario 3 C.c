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
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/login");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_USERNAME, "user");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "pass");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_CIPHER_LIST, "HIGH:!aNULL:!eNULL:!LOW:!EXP:!MD5:@STR
      :@STR");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_CIPHER_LIST, "HIGH:!aNULL:!eNULL:!LOW:!EXP:!MD5:@STR
      :@STR");




    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
  return 0;
}
