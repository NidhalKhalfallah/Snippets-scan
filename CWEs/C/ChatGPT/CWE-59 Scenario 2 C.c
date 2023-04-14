#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

const char* allowed_domains[] = {"example1.com", "example2.com", "example3.com"};
//define a function to download a file from a link provided by the user
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    // This function is called by cURL as it downloads the file.
    // We can use this function to save the data to a file on disk.
    FILE *file = (FILE *) userdata;
    return fwrite(ptr, size, nmemb, file);
}

int download_file(const char *url, const char *filename) {
    // First, make sure the domain is allowed.
    const char *hostname_start = strstr(url, "://") + 3;
    const char *hostname_end = strchr(hostname_start, '/');
    if (hostname_end == NULL) {
        hostname_end = hostname_start + strlen(hostname_start);
    }
    size_t hostname_len = hostname_end - hostname_start;
    char hostname[256];
    strncpy(hostname, hostname_start, hostname_len);
    hostname[hostname_len] = '\0';
    int allowed = 0;
    for (size_t i = 0; i < sizeof(allowed_domains) / sizeof(allowed_domains[0]); i++) {
        if (strcmp(hostname, allowed_domains[i]) == 0) {
            allowed = 1;
            break;
        }
    }
    if (!allowed) {
        fprintf(stderr, "Error: domain %s is not allowed\n", hostname);
        return -1;
    }

    // Set up cURL to download the file.
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: could not initialize cURL\n");
        return -1;
    }
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        curl_easy_cleanup(curl);
        return -1;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Download the file.
    CURLcode res = curl_easy_perform(curl);
    fclose(file);
    curl_easy_cleanup(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return -1;
    }

    return 0;
}
int main() {
    const char *url = "https://example.com/file.txt";
    const char *filename = "file.txt";
    int result = download_file(url, filename);
    if (result != 0) {
        fprintf(stderr, "Error downloading file from %s\n", url);
    }
    return 0;
}