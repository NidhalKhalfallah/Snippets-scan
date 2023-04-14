#include <stdio.h>
#include <curl/curl.h>

void ConnectToUrl(char *url)
{
CURL *curl;
CURLcode res;

curl = curl_easy_init();
if(curl) {
curl_easy_setopt(curl, CURLOPT_URL, url);
res = curl_easy_perform(curl);
}
}

int main(int argc, char* argv[])
{
// Connect to an example URL
  char *url;
  if(argc > 1)
    url = argv[1];
  else
    url = "http://www.example.com";
    ConnectToUrl(url);
    return 0;

    return 0;
}