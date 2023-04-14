#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

const char* allowed_domains[] = {"example1.com", "example2.com", "example3.com"};
//define a function to download a file from a link provided by the user

int main(int argc, char **argv)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    FILE *hd_src ;
    char *hd_dst ;
    size_t hd_size;
    const char *url = "https://example.com/index.html";
    const char *filename = "index.html";
    const char *header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    size_t header_len = strlen(header);
    size_t total_size = 0;
    int i;
    if(argc > 1)
        url = argv[1];
        
    if(argc > 2)
        filename = argv[2];
        
    if(argc > 3)
        header = argv[3];
        
    if(argc > 4)
        header_len = atoi(argv[4]);
        
    if(argc > 5)
        total_size = atoi(argv[5]);
        
    hd_src = fopen(filename, "wb");
    if(!hd_src) {
        perror("fopen");
        return 1;
    }
    
    hd_dst = fopen(filename, "rb");
    if(!hd_dst) {
        perror("fopen");
        return 1;
    }
    
    curl = curl_easy_init();
    if(!curl) {
        perror("curl_easy_init");
        return 1;
    }
    
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, hd_dst);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, hd_src);
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 150L);