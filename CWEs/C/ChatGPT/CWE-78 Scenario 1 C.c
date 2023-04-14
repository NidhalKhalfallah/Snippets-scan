#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* commands_whitelist[] = {"getmac", "ipconfig"};
void execute_command(char* command) {
    int i;
    int num_commands = sizeof(commands_whitelist) / sizeof(char*);
    int allowed = 0;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(command, commands_whitelist[i]) == 0) {
            allowed = 1;
            break;
        }
    }

    if (!allowed) {
        printf("Command '%s' is not allowed\n", command);
        return;
    }

    // Execute the command
    system(command);
}