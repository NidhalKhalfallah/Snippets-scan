#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char* WhiteListFolders[] = {
"/home/user/Documents",
"/home/user/Images",
"/home/user/Music"
};
const char* command_path = "/home/user/local/";
const char* script_name = "example.c";
int main() {
    char script_path[100];
    snprintf(script_path, sizeof(script_path), "%s%s", command_path, script_name);
    //Execute the script
    // Check if the script is located in one of the white-listed folders
    int is_whitelisted = 0;
    for (int i = 0; i < sizeof(WhiteListFolders)/sizeof(WhiteListFolders[0]); i++) {
        if (strncmp(script_path, WhiteListFolders[i], strlen(WhiteListFolders[i])) == 0) {
            is_whitelisted = 1;
            break;
        }
    }

    if (!is_whitelisted) {
        printf("Error: Script is not in the white-listed folders.\n");
        return 1;
    }

    // Execute the script
    char command[100];
    snprintf(command, sizeof(command), "gcc %s -o output && ./output", script_path);
    system(command);

    return 0;
}