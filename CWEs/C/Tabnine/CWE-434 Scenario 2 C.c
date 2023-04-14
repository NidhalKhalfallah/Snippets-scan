#include <stdio.h>
#include <magic.h>
#include <curl/curl.h>

void upload_image(const char* My_Image, const char* url) {
    //Upload an image to a url
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, &upload_image_cb);
    curl_easy_setopt(curl, CURLOPT_XFERINFODATA, NULL);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
                return;
            
        

        return;
    }
    else {
        printf("Upload successful\n");
        return;

        