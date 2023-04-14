#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv) {
// Get an employee name as an argument then execute an OS command that returns the age of that employee
char* empName = argv[1];
	char command[100] = "curl -s http://localhost:8080/employees | jq '.[] | select(.name==\"";
	strcat(command,empName);
	strcat(command,"\")'");
	system(command);

	return 0;
}
