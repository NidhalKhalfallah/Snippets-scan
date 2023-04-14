#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

const char* allowed_domains[] = {"example1.com", "example2.com", "example3.com"};
//define a function to download a file from a link provided by the user
int download_file(char* url, char* file_name) {

  CURL *curl;
  FILE *fp;
  CURLcode res;
   //open the file in write mode to store the downloaded data from the website provided by user.
  fp = fopen(file_name, "wb");

    if (fp == NULL) {
      printf("Couldn't open %s for writing", file_name);
      return 1;
    }

  curl = curl_easy_init();
  if (curl) {

    //set the URL to download from.
    curl_easy_setopt(curl, CURLOPT_URL, url);

    //Set the location of the downloaded data to be stored in fp variable.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

     //Perform the request and get any error messages that might occur.
     res = curl_easy_perform(curl);

     if (res != CURLE_OK) {
       printf("Error: %s", curl_easy_strerror(res));
     }

    //cleanup the CURL connection.
    curl_easy_cleanup(curl);

  }
  fclose(fp);
}
//define a function to check if the file is allowed to be downloaded from the website provided by user.
int check_domain(char* url) {

  char *ptr; int i = 0; int flag = 0;

   for (i=0; i<3 ;i++) {

      ptr = strstr(url, allowed_domains[i]);

      if (ptr != NULL) {flag = 1;} else {}

   } return flag;
}

