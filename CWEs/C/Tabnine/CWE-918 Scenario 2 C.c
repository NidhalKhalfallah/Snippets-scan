#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

char *fetch_html_body(const char *url, const char *endpoint) {
    //this function sends a GET request to the endpoint and returns the HTML body of the response
    CURL *curl;
    CURLcode res;
    FILE *fp = NULL;
    char *body = NULL;
    long response_code;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)");
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    res = curl_easy_perform(curl);

    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        return NULL;
    }
    res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_getinfo() failed: %s\n",
                curl_easy_strerror(res));
        return NULL;
    }
    curl_easy_cleanup(curl);

    if (response_code!= 200) {
        fprintf(stderr, "response_code: %ld\n", response_code);
        return NULL;
    }
    body = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE);
    curl_easy_cleanup(curl);
    return body;

    return NULL;
}
