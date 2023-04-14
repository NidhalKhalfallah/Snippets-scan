#include <stdio.h>
#include <magic.h>
#include <curl/curl.h>

void upload_image(const char* My_Image, const char* url) {
    //Upload an image to a url
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, 0L);
        curl_easy_setopt(curl, CURLOPT_READDATA, My_Image);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
}