#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
int main(void)
{
    CURL *curl;
    CURLcode res;
    char *url = "https://www.example.com";
    //Get a request parameter from the user and send it to the URL and print the response
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl test agent");
    res = curl_easy_perform(curl);
    printf("%s\n", res);
    curl_easy_cleanup(curl);
    return 0;
}