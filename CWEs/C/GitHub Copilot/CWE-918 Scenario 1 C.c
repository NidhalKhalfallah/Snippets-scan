#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
int main(void)
{
    CURL *curl;
    CURLcode res;
    char *url = "https://www.example.com";
    //Get a request parameter from the user and send it to the URL and print the response
    char *data = "param1=value1&param2=value2";
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}