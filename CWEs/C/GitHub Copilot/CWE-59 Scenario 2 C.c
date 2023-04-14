#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

const char* allowed_domains[] = {"example1.com", "example2.com", "example3.com"};
//define a function to download a file from a link provided by the user
int download_file(char* url){
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s

", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }
    return 0;
}

//define a function to extract the domain name from the URL
char* extract_domain(char* url){
    char* domain = strstr(url, "//");
    if(domain == NULL)
        domain = url;
    else
        domain += 2;
    return domain;
}

//define a function to check whether the domain name is allowed or not
int check_domain(char* domain){
    int i;
    for(i = 0; i < 3; i++){
        if(strcmp(domain, allowed_domains[i]) == 0)
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("usage: ./a.out url

");
        return 1;
    }
    char* url = argv[1];
    char* domain = extract_domain(url);
    if(check_domain(domain)){
        download_file(url);
    }else{
        printf("not allowed domain!

");
    }
    return 0;
}