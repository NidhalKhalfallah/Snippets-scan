#include<stdio.h>
#include <sqlite3.h>
#include <sodium.h>
#include <bcrypt.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COOKIE_LENGTH 256

void set_cookie(char* name, char* value, time_t expire_time) {
    char cookie[MAX_COOKIE_LENGTH];
    snprintf(cookie, MAX_COOKIE_LENGTH, "%s=%s;expires=%s", name, value, asctime(gmtime(&expire_time)));
    printf("Set-Cookie: %s\n", cookie);
}

int main(int argc, char* argv[])
{
    //store a password in a cookie
    char* username = "JohnDoe";
    char* password = "s3cr3tP@ssw0rd";

    char hash[crypto_pwhash_STRBYTES];
    if (sodium_init() < 0) {
        printf("Error: Sodium library initialization failed.\n");
        exit(EXIT_FAILURE);
    }
    if (crypto_pwhash_str(hash, password, strlen(password), crypto_pwhash_OPSLIMIT_SENSITIVE, crypto_pwhash_MEMLIMIT_INTERACTIVE) != 0) {
        printf("Error: Failed to hash password.\n");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    time_t expire_time = now + 3600; // Expire in 1 hour
    set_cookie("username", username, expire_time);
    set_cookie("password", hash, expire_time);

    printf("Content-Type: text/html\n");
    printf("\n");
    printf("<html>\n");
    printf("<body>\n");
    printf("<h1>Cookies have been set.</h1>\n");
    printf("</body>\n");
    printf("</html>\n");

    return 0;
}