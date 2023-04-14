#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

char *fetch_html_body(const char *url, const char *endpoint) {
    //this function sends a GET request to the endpoint and returns the HTML body of the response
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        char url[50]; //the URL of the page to be fetched, including the endpoint and query params
        strcpy(url, url);
strcat(url, endpoint);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);

        //get the response body and return it as a string
        char *body = NULL;
        long length;

        res = curl_easy_perform(curl);
         if (res != CURLE_OK) {
            fprintf(stderr,"Error: %s", curl_easy_strerror(res));
            return NULL;
        }

        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &length);
        if (res != CURLE_OK) {
            fprintf(stderr,"Error: %s", curl_easy_strerror(res));
            return NULL;
        }

        body = malloc((sizeof(*body)) * length); //allocate memory for the response body string

        res = curl_easy_perform(curl); //fetch the HTML body of the page and store it in 'body' variable. The result is stored as a string. 

         if (res != CURLE_OK) {
            fprintf(stderr,"Error: %s", curl_easy_strerror(res));
            return NULL;   //return null on error. This will be used to determine whether or not an error occurred while fetching data from a remote server. If no errors occur then this function returns a non-null value which can be used to parse the HTML body of the page that was fetched by this function call. 
         }

    } else {  //if there are any errors when creating CURL easy object then print them out and exit with code 1 indicating failure to create cURL easy object successfully. 			//this should never happen because we're using libcurl so we know it's going to work at runtime but just in case... 			//exit with code 1 indicating failure to create cURL easy object successfully because it indicates an internal error in libcurl itself or something went wrong with our program logic that caused us to fail before reaching this point in our program execution flow... 	}
