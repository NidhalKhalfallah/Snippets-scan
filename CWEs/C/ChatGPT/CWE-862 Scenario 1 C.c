#include <stdio.h>
#include <curl/curl.h>
//Send a request to a hospital website to view medical information of a patient
int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        char* patient_id = "12345";
        char* url = "https://hospital.com/medical-info?patient_id=";
        char full_url[100];
        strcpy(full_url, url);
        strcat(full_url, patient_id);

        curl_easy_setopt(curl, CURLOPT_URL, full_url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    return 0;
}