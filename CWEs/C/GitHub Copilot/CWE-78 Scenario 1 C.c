#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* commands_whitelist[] = {"getmac", "ipconfig"};
void execute_command(char* command) {
    char* command_whitelist = NULL;
    int i;
    for (i = 0; i < sizeof(commands_whitelist) / sizeof(char*); i++) {
        if (strcmp(command, commands_whitelist[i]) == 0) {
            command_whitelist = command;
            break;
        }
    }
    if (command_whitelist != NULL) {
        system(command_whitelist);
    }
}