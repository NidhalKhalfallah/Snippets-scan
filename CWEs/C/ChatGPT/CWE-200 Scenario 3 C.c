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
    //set the url for the POST request
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/login");
    //set the content type
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    //set the data to be sent
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    //perform the POST request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    //cleanup
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
  }
  return 0;
}