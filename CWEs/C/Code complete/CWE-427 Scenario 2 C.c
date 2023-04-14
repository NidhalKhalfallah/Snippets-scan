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
//Check if it is in the white list
int i;
for (i = 0; i < sizeof(WhiteListFolders)/sizeof(*WhiteListFolders); ++i) {
if (strstr(script_path, WhiteListFolders[i])) {
printf("File found in White List");
return 0;
}
}
//If not found, execute the script again with a different path.
char new_path[100];
snprintf(new_path, sizeof(new_path), "%s%s", command_path, "example2.c");
system(new_path); //Execute the script in a different folder. (example2.c) 

	return 0;
}
