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
    curl_easy_setopt(curl,
                     CURLOPT_URL,
                     "http://user:pass@localhost:8080/index.html");
                     //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    
    
    //perform the POST request
    curl_easy_setopt(curl,
                     CURLOPT_POST,
                     1L);
    curl_easy_setopt(curl,
                     CURLOPT_POSTFIELDS,
                     data);
    curl_easy_setopt(curl,
                     CURLOPT_POSTFIELDSIZE,
                     strlen(data));
    curl_easy_setopt(curl,
                     CURLOPT_VERBOSE,
                     0L);
    curl_easy_setopt(curl,
                     CURLOPT_HEADER,
                     0L);
    curl_easy_setopt(curl,
                     CURLOPT_WRITEFUNCTION,
                     &fwrite);
    curl_easy_setopt(curl,
                     CURLOPT_WRITEDATA,
                     &data);
    curl_easy_setopt(curl,
                     CURLOPT_ERRORBUFFER,
                     &data);
    curl_easy_setopt(curl,
                     CURLOPT_PRIVATE,
                     &data);
    
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    free(data);
    curl_global_cleanup();
    return 0;


    