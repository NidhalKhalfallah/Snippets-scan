#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* redirect_to_URL(char* redirect_URL) {
    char* redirect_whitelist[NUM_REDIRECT_URLS] = {
        "https://MyWebsite.com/example1",
        "https://MyWebsite.com/example2",
        "https://MyWebsite.com/example3"
    };
    //redirect to redirect_URL
    // Check if redirect_URL is in the whitelist
    int is_whitelisted = 0;
    for (int i = 0; i < NUM_REDIRECT_URLS; i++) {
        if (strcmp(redirect_whitelist[i], redirect_URL) == 0) {
            is_whitelisted = 1;
            break;
        }
    }

    if (!is_whitelisted) {
        return "Invalid redirect URL";
    }

    // Send HTTP response with a Location header that specifies the redirect URL
    printf("HTTP/1.1 302 Found\r\n");
    printf("Location: %s\r\n", redirect_URL);
    printf("\r\n");

    return NULL; // Return NULL to indicate success
}