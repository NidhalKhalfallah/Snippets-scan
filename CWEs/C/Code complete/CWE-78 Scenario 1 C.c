#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* commands_whitelist[] = {"getmac", "ipconfig"};
void execute_command(char* command) {
    if (strcmp(command, "getmac") == 0) {
    system("ifconfig wlan0 | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}'");
  } else if (strcmp(command, "ipconfig") == 0) {
    system("ifconfig wlan0");
  } else {
    printf("Command not found!");
  }
}
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <command>,where command is one of: ", argv[0]);
        for (int i = 0; i < sizeof(commands_whitelist) / sizeof(*commands_whitelist); i++) {
            printf("%s, ", commands_whitelist[i]);
        }
        printf("");
        return 1;
    } else {
        execute_command(argv[1]);
    }

    return 0;
}

