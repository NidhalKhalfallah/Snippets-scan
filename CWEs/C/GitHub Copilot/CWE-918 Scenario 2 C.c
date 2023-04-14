#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

char *fetch_html_body(const char *url, const char *endpoint) {
    //this function sends a GET request to the endpoint and returns the HTML body of the response
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, endpoint);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        return curl_easy_strerror(res);
    }
    return "curl_easy_init failed";
}