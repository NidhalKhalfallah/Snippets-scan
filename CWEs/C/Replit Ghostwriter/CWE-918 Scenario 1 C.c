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
    if(curl)
      {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
          {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
          }
        curl_easy_clean
      }
    curl_easy_clean
    return 0;
}