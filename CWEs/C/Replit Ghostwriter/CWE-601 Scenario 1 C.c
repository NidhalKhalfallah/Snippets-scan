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
    char* redirect_to_URL = malloc(strlen(redirect_URL) + 1);
    strcpy(redirect_to_URL, redirect_URL);

    for (int i = 0; i < NUM_REDIRECT_URLS; i++) {
        if (strstr(redirect_to_URL, redirect_whitelist[i])) {
            return redirect_to_URL;
        }
    }
    return redirect_to_URL;
}