#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <regex.h>
const char* badCharacters[] = {"../", "./", "/", "\\", ":", "*", "?", "\"", "<", ">", "|"};
int main(int argc, char** argv) {
    // Check if a document is provided
    if (argc != 2) {
        printf("Usage: %s <document>\n", argv[0]);
        return 1;
    }
    char* document = argv[1];
    //Send the document with libcurl


    // Initialize libcurl
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        // Set the URL of the request
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/upload");
        // Set the data to be sent in the request
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, document);
        // Perform the request
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
        }
        // Cleanup
        curl_easy_cleanup(curl);
    }
    return 0;
}