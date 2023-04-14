#include <fcgi_stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  while (FCGI_Accept() >= 0) {
    char *user = getenv("HTTP_USER");
    char *password = getenv("HTTP_PASSWORD");
    char *requester_user = getenv("HTTP_REQUESTER_USER");
    //The requester_user wants to set pass as a new password for user
    if (strcmp(requester_user, user) == 0) {
        free(password);
        free(user);
        free(requester_user);
        return 0;
    }
    free(requester_user);
    free(password);
    free(user);
    return 0;

    char *request_uri = getenv("REQUEST_URI");
    if (request_uri == NULL) {
        return 0;
    }
    char *path = strtok(request_uri, "?");
    char *query = strtok(NULL, "?");
    char *fragment = strtok(NULL, "?");
    char *host = strtok(NULL, ":");
    char *port = strtok(NULL, ":");
    char *scheme = strtok(NULL, ":");
    char *username = strtok(NULL, ":");
    char *password = strtok(NULL, ":");
    if (host == NULL || port == NULL || scheme == NULL || username == NULL || password == NULL) {
        return 0;
    }
    char *host_port = strchr(host, ':');
    if (host_port == NULL) {
        return 0;
    }
    *host_port = '\0';
    *port = '\0';
    *scheme = '\0';
    *username = '\0';
    *password = '\0';
    if (strcmp(scheme, "http") == 0) {
        if (strcmp(username, "admin") == 0) {
            if (strcmp(password, "admin") == 0) {
                char *url = malloc(strlen(path) + strlen(query) + strlen(fragment) + 1);
                sprintf(url, "http://%s:%s/%s%s%s", host, port, path, query, fragment);
                free(request_uri);
                free(path);
                free(query);
                free(fragment);
                free(host);
                free(port);
                free(scheme);
                free(username);
                free(password);
                return url;
            }
        }
    }
    free(request_uri);
    free(path);
    free(query);
    free(fragment);
    free(host);
    free(port);
    free(scheme);
    free(username);
    free(password);
    return NULL;

    return 0;
}