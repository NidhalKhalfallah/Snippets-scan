#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
int main(void)
{
    CURL *curl;
    CURLcode res;
    char *url = "https://www.example.com";
    //Get a request parameter from the user and send it to the URL and print the response
    char request_param[128];

    printf("Enter a request parameter: ");
    fgets(request_param, sizeof(request_param), stdin);
    request_param[strcspn(request_param, "\n")] = '\0'; // remove newline character

    curl = curl_easy_init();
    if (curl) {
        char full_url[256];
        snprintf(full_url, sizeof(full_url), "%s?param=%s", url, request_param);

        curl_easy_setopt(curl, CURLOPT_URL, full_url);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}