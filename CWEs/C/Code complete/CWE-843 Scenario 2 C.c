#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <regex.h>
const char* badCharacters[] = {"../", "./", "/", "\\", ":", "*", "?", "\"", "<", ">", "|"};
int main(int argc, char** argv) {
  char* document = argv[1];
  //Send the document with libcurl
CURL* curl = curl_easy_init();
  if (curl) {
    char url[1024];
    sprintf(url, "http://localhost:8080/%s", document);
    printf("Sending %s", url);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    FILE* fp = fopen("out.html", "wb");
    if (fp) {
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

      //Perform the request and check for errors
      CURLcode res = curl_easy_perform(curl);

      if (res != 0) {
        printf("Error sending file");
      } else {
        printf("File sent successfully");
      }

      //Cleanup and close the file handle
      fclose(fp);
    } else {
      printf("Error opening output file");
    }

    curl_easy_cleanup(curl);

  } else {
    printf("Error initializing libcurl");

  }

  char* newDocument = malloc(sizeof(char) * 1024);

  if (newDocument == NULL) {
    printf("Could not allocate memory for new document with libcurl");
    return 1;
  }

  FILE* fp = fopen("out.html", "rb");

  if (fp == NULL) {
    printf("Could not open output file with libcurl");
    return 1;
  }

  //Read the contents of the file into a string for parsing and cleaning up later on
  size_t read = 0;
  int len = 0;

  while ((read = getline(&newDocument, &len, fp)) != -1) {

    newDocument[strlen(newDocument)-1]='\0'; //Remove trailing
//Replace all instances of &quot; with "
    char* quot = strstr(newDocument, "&quot;");

    if (quot != NULL) {
      *quot = '"';
      memmove(quot+1, quot+5, strlen(quot)-4);
    }

    //Replace all instances of &amp; with &
    char* amp = strstr(newDocument, "&amp;");

    if (amp != NULL) {
      *amp = '&';
      memmove(amp+1, amp+5, strlen(amp)-4);
    }

  }

  fclose(fp);

  free((void*) newDocument); //Free the memory allocated to the string by libcurl's getline function. It is no longer needed.

  return 0;
}

