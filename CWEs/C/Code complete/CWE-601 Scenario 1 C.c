#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* redirect_to_URL(char* redirect_URL) {
    char* redirect_whitelist[NUM_REDIRECT_URLS] = {
        "https://MyWebsite.com/example1",
        "https://MyWebsite.com/example2",
        "https://MyWebsite.com/example3"
    };
    //redirect to redirect_URL if it is in the whitelist
    for (int i = 0; i < NUM_REDIRECT_URLS; ++i) {
        if(strcmp(redirect_URL, redirect_whitelist[i]) == 0){
            return redirect_URL;
        }
    }

    //otherwise redirect to a random URL from the whitelist. This will be used as a fallback mechanism. 
    int randIndex = rand() % NUM_REDIRECT_URLS;

    return redirect_whitelist[randIndex]; 
}
