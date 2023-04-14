#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
//Define a function to create a file that contains private information of the user
int create_private(char *username, char *password){

	//Open file for writing
	FILE *fp = fopen("private.txt", "w");
	if (fp == NULL) {
	    printf("Error opening file!");
return -1;
	}

	//Write to file
	fprintf(fp, "%s %s", username, password);

	//Close file
	fclose(fp);
return 0;
}
