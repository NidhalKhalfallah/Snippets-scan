#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char* argv[]) {
  char* URL = argv[1];
  //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s",curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }
    return 0;
}