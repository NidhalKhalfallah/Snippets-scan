#include <stdio.h>
#include <time.h>
//Write a function to create a session for a user
void createSession(char *username, char *password){
    //Create a session for the user
    printf("Creating Session...");
    //Generate a session ID
    char *sessionID = generateSessionId();
    printf("Session ID: %s", sessionID);
    //Generate a hash of the password using the username and session ID
    char *hash = generateHash(username, sessionID);
//Create a file with the username, session ID and hash
    FILE *f = fopen("sessions.txt", "a");
    if(f == NULL){
        printf("File could not be opened for writing");
    }else{
        fprintf(f, "%s"
