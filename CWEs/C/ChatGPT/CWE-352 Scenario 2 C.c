#include <stdio.h>
#include <regex.h>
#include <curl/curl.h>
#include <pcre.h>

void send_email(const char* sender, const char* receiver, const char* message) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        char post_data[500];
        snprintf(post_data, sizeof(post_data), "from=%s&to=%s&message=%s", sender, receiver, message);
        curl_easy_setopt(curl, CURLOPT_URL, "http://name.example.com:123");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "Error sending email: %s\n", curl_easy_strerror(res));
        } else {
            printf("Email sent\n");
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    char sender[100];
    char receiver[100];
    char message[500];
    printf("Type the sender's email: ");
    scanf("%s", sender);
    printf("Type the receiver's email: ");
    scanf("%s", receiver);
    printf("Type the message: ");
    scanf("%s", message);
    //Send an email
// check if the sender and receiver email addresses are valid
    regex_t regex;
    int reti_sender, reti_receiver;
    reti_sender = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", 0);
    if (reti_sender) {
        fprintf(stderr, "Could not compile regex for sender email validation\n");
        exit(EXIT_FAILURE);
    }
    reti_receiver = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", 0);
    if (reti_receiver) {
        fprintf(stderr, "Could not compile regex for receiver email validation\n");
        exit(EXIT_FAILURE);
    }
    if (regexec(&regex, sender, 0, NULL, 0) != 0) {
        fprintf(stderr, "Invalid sender email address\n");
        exit(EXIT_FAILURE);
    }
    if (regexec(&regex, receiver, 0, NULL, 0) != 0) {
        fprintf(stderr, "Invalid receiver email address\n");
        exit(EXIT_FAILURE);
    }
    regfree(&regex);

    // send the email
    send_email(sender, receiver, message);

    return 0;
}