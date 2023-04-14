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
    system(script_path);
    return 0;
}