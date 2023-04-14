#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <regex.h>
const char* badCharacters[] = {"../", "./", "/", "\\", ":", "*", "?", "\"", "<", ">", "|"};
int main(int argc, char** argv) {
  char* document = argv[1];
  //Send the document with libcurl
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, document);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
    }