#include <stdio.h>
#include <curl/curl.h>
//Send a request to a hospital website to view medical information of a patient
int main(void) {
	CURL *curl;
	CURLcode res;

	char url[100]; // URL to get the data from
	sprintf(url,"http://www.hospital.com/patient1"); //Fill in the patient number here

	curl = curl_easy_init();

	if (curl) {
	  curl_easy_setopt(curl, CURLOPT_URL, url);
	  res = curl_easy_perform(curl);

	  /* always cleanup */
//    curl_easy_cleanup(curl);
//}
}
	return 0;
}
