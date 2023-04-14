#include <stdio.h>
#include <curl/curl.h>
//Send a request to a hospital website to view medical information of a patient
int main(void)
{
CURL *curl;
CURLcode res;
curl = curl_easy_init();
if(curl) {
curl_easy_setopt(curl, CURLOPT_URL, "http://www.hospital.com/patient/medicalinfo");
/* example.com is redirected, so we tell libcurl to follow redirection */
curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
/* Perform the request, res will get the return code */
res = curl_easy_perform(curl);