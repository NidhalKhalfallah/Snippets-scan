#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

char *fetch_html_body(const char *url, const char *endpoint) {
    //this function sends a GET request to the endpoint and returns the HTML body of the response
    CURL *curl;
    CURLcode res;
    char *body;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_body);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return body;
}