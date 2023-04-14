#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
int main(void)
{
    CURL *curl;
    CURLcode res;
    char *url = "https://www.example.com";
    //Get a request parameter from the user and send it to the URL and print the response
printf("Enter a request parameter: ");
char *parameter = malloc(sizeof(char));
scanf("%s", parameter);
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if (curl) {
        char *postdata = malloc(strlen("key=value") + strlen(parameter) + 1); //1 for the null-terminator
        sprintf(postdata, "key=%s", parameter);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);

        /* Set the URL that is about to receive our POST. */
        curl_easy_setopt(curl, CURLOPT_URL, url);

        /* Perform the request, res will get the return code */ 
res = curl_easyperform(curl); 

	/* Check for errors */ 
if (res != CURLE_OK) {  printf("curl failed: %s", curl_easy_strerror(res)); }
        /* always cleanup */ 
curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}
