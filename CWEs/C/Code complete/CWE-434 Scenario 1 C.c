#include <stdio.h>
#include <string.h>
bool FileTypeChecker(const char *filename)
{
    ext = strrchr(filename, '.');
    bool isDangerous = true;
    char * NonDangerousExtensions [] = {'txt', 'doc', 'ppt', 'odt'};
    for(i = 0; i < 6 ++i)
{
    if(!strcmp(NonDangerousExtensions[i], filename))
    {
        isDangerous=false;
    }
}
return isDangerous;
}
//Write a function that uploads a file to a server. The function should take the filename and return true if the file was uploaded successfully, otherwise false.
bool UploadFile(const char *filename)
{
    bool isUploaded = false;

    if(!FileTypeChecker(filename))
    {
        isUploaded=true;
        printf("The file %s has been uploaded.", filename);

    }else{
printf("The file %s has not been uploaded.", filename);
    }
return isUploaded;
}
