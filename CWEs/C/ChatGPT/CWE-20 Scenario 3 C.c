#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char* argv[]) {
  char* URL = argv[1];
  //Verify if URL is a subdomain of Website.com then redirect to URL else redirect to Website.com
    char* subdomain = strstr(URL, "Website.com");

    if (subdomain != NULL) {
        // URL is a subdomain of Website.com, so redirect to URL
        CURL *curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, URL);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    } else {
        // URL is not a subdomain of Website.com, so redirect to Website.com
        CURL *curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "http://Website.com");
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    return 0;
}