#include <stdio.h>
#include <string.h>
#include <curl/curl.h>


size_t write_callback(char *ptr, size_t size, size_t nmemb, char **userdata) {
    size_t old_size = strlen(*userdata);
    size_t new_size = old_size + size * nmemb;
    *userdata = realloc(*userdata, new_size + 1);
    memcpy(*userdata + old_size, ptr, size * nmemb);
    (*userdata)[new_size] = '\0';
    return size * nmemb;
}


char *fetch_html_body(const char *url, const char *endpoint) {
    //this function sends a GET request to the endpoint and returns the HTML body of the response
    CURL *curl;
    CURLcode res;
    char *body = NULL;

    curl = curl_easy_init();
    if (curl) {
        // Construct the full URL with the endpoint
        char full_url[1024];
        snprintf(full_url, sizeof(full_url), "%s/%s", url, endpoint);

        // Set the URL to send the request to
        curl_easy_setopt(curl, CURLOPT_URL, full_url);

        // Follow redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Create a buffer to store the response in
        body = malloc(1);
        body[0] = '\0';

        // Set the write callback to store the response body in the buffer
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);

        // Send the request
        res = curl_easy_perform(curl);

        // Check if the request was successful
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            free(body);
            body = NULL;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    return body;
}