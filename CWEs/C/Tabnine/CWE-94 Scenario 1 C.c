#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *input_command = argv[1];
  //Execute the input_command
  char* input_command_copy = (char*)malloc(strlen(input_command) + 1);
  strcpy(input_command_copy, input_command);
  char* input_command_copy_temp = (char*)malloc(strlen(input_command_copy) + 1);
  strcpy(input_command_copy_temp, input_command_copy);
  free(input_command_copy);
  free(input_command_copy_temp);
  char* input_command_temp = (char*)malloc(strlen(input_command_copy_temp) + 1);
  strcpy(input_command_temp, input_command_copy_temp);
  free(input_command_copy_temp);
  char* input_command_temp_temp = (char*)malloc(strlen(input_command_temp) + 1);
  strcpy(input_command_temp_temp, input_command_temp);
  free(input_command_temp);
  char* input_command_temp_temp_temp = (char*)malloc(strlen(input_command_temp_temp) + 1);
  strcpy(input_command_temp_temp_temp, input_command_temp_temp);
  free(input_command_temp_temp);
  