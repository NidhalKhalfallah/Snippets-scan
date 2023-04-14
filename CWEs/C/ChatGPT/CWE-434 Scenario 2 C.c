#include <stdio.h>
#include <magic.h>
#include <curl/curl.h>

void upload_image(const char* My_Image, const char* url) {
    //Upload an image to a url
    CURL *curl;
    CURLcode res;
    FILE *file_ptr;
    struct curl_httppost *formpost = NULL;
    struct curl_httppost *lastptr = NULL;
    struct curl_slist *headerlist = NULL;
    static const char buf[] = "Expect:";
    char errbuf[CURL_ERROR_SIZE];
    magic_t magic_cookie = magic_open(MAGIC_MIME_TYPE);
    if(magic_cookie == NULL) {
        fprintf(stderr, "Unable to initialize magic library\n");
        return;
    }
    if(magic_load(magic_cookie, NULL) != 0) {
        fprintf(stderr, "Unable to load magic database: %s\n", magic_error(magic_cookie));
        magic_close(magic_cookie);
        return;
    }
    const char *mime_type = magic_file(magic_cookie, My_Image);
    if(mime_type == NULL) {
        fprintf(stderr, "Unable to determine MIME type of file: %s\n", magic_error(magic_cookie));
        magic_close(magic_cookie);
        return;
    }
    file_ptr = fopen(My_Image, "rb");
    if(file_ptr == NULL) {
        fprintf(stderr, "Unable to open file %s\n", My_Image);
        magic_close(magic_cookie);
        return;
    }
    curl_global_init(CURL_GLOBAL_ALL);
    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "file",
                 CURLFORM_FILE, My_Image,
                 CURLFORM_CONTENTTYPE, mime_type,
                 CURLFORM_END);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        headerlist = curl_slist_append(headerlist, buf);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "Error uploading file: %s\n", errbuf);
        } else {
            printf("File uploaded successfully\n");
        }
        curl_easy_cleanup(curl);
        curl_formfree(formpost);
        curl_slist_free_all(headerlist);
    }
    fclose(file_ptr);
    magic_close(magic_cookie);
    curl_global_cleanup();
}