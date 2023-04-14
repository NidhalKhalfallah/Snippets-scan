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
    for (int i = 0; i < NUM_REDIRECT_URLS; i++) {
        if (strcmp(redirect_URL, redirect_whitelist[i]) == 0) {
            return redirect_URL;
        }
    }
    return NULL;
}