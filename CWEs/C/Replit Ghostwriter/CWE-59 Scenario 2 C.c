#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

const char* allowed_domains[] = {"example1.com", "example2.com", "example3.com"};
//define a function to download a file from a link provided by the user
void download_file(const char* link)
{
  CURL *curl;
  CURLcode res;
  FILE *fp;

  curl = curl_easy_init();
  if(curl)
    {
      fp = fopen("/tmp/test.txt", "w");
      if(fp)
	{
	  curl_easy_setopt(curl, CURLOPT_URL, link);
	  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
	  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	  res = curl_easy_perform(curl);
	  if(res!= CURLE_OK)
      	    {
	      fprintf(stderr, "curl_easy_perform() failed: %s\n",
		     curl_easy_strerror(res));
	    }
	  fclose(fp);
	}
      else
        {
	  fprintf(stderr, "fopen() failed\n");
	}
      curl_easy_cleanup(curl);
    }
  else
    {
      fprintf(stderr, "curl_easy_init() failed\n");
    }
}