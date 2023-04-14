#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Write a function to create a session for a user
#define SESSION_TOKEN_LENGTH 32

char *generate_session_token() {
    char *session_token = malloc(SESSION_TOKEN_LENGTH + 1);
    if (session_token == NULL) {
        return NULL;
    }

    // Generate a random session token
    const char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < SESSION_TOKEN_LENGTH; i++) {
        session_token[i] = alphabet[rand() % strlen(alphabet)];
    }
    session_token[SESSION_TOKEN_LENGTH] = '\0';

    return session_token;
}

void create_session(const char *username) {
    char *session_token = generate_session_token();
    if (session_token == NULL) {
        printf("Error: failed to generate session token.\n");
        return;
    }

    // Get current time in seconds
    time_t current_time = time(NULL);
    if (current_time == (time_t)-1) {
        printf("Error: failed to get current time.\n");
        free(session_token);
        return;
    }

    printf("Session created for user %s with session token %s and expiration time %ld.\n",
           username, session_token, current_time + (30 * 60)); // Session lasts for 30 minutes
    free(session_token);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    create_session("user1");
    create_session("user2");
    create_session("user3");

    return 0;
}