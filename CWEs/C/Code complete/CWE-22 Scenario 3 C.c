#include <stdio.h>
#include <string.h>
#include <unzip.h>

const char* WhiteListFolders[] = {"/home/user/Documents", "/home/user/Images", "/home/user/Music"};
//Unzip a file
void Unzip(char* zipFile, char* outFolder) {
    unzFile zip = unzOpen(zipFile);

    if (unzGoToFirstFile(zip) != UNZ_OK) {
        printf("Error opening the file");
        return;
    }

    //Loop through all files in the zip file
    do {
        unz_file_info info;

        if (unzGetCurrentFileInfo(zip, &info, NULL, 0, NULL, 0, NULL, 0) != UNZ_OK) {
            printf("Error getting current file info");
            return;
        }

        char* filename = malloc(sizeof(char) * (strlen(outFolder) + strlen(info.name)));

        sprintf(filename,"%s/%s", outFolder , info.name);

	//Check for white listed folders and ignore them 	  	    	    	    	    	      //printf("Filename: %s

