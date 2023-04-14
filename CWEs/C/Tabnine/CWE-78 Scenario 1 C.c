#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* commands_whitelist[] = {"getmac", "ipconfig"};
void execute_command(char* command) {
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "%s: %s\n", command, strerror(errno));
        exit(1);
    }
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp))!= -1) {
        printf("%s\n", line);
    }
    pclose(fp);
}