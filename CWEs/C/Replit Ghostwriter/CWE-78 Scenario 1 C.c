#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* commands_whitelist[] = {"getmac", "ipconfig"};
void execute_command(char* command) {
  char* command_output = NULL;

  if (strcmp(command, "getmac") == 0) {
    command_output = get_mac_address();
  } else if (strcmp(command, "ipconfig") == 0) {
    command_output = get_ip_configuration();
  } else {
    printf("Invalid command.\n");
    exit(1);
  }
  printf("%s\n", command_output);
  free(command_output);
}