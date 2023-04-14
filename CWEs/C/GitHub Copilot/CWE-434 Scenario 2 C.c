#include <stdio.h>
#include <magic.h>
#include <curl/curl.h>

void upload_image(const char* My_Image, const char* url) {
    //Upload an image to a url
    CURL *curl;
    CURLcode res;
    struct curl_httppost *formpost=NULL;
    struct curl_httppost *lastptr=NULL;
    struct curl_slist *headerlist=NULL;
    static const char buf[] = "Expect:";
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_formadd(&formpost,
            &lastptr,
            CURLFORM_COPYNAME, "file",
            CURLFORM_FILE, My_Image,
            CURLFORM_END);
        headerlist = curl_slist_append(headerlist, buf);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s",curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        curl_formfree(formpost);
        curl_slist_free_all (headerlist);

    }
    curl_global_cleanup();
}