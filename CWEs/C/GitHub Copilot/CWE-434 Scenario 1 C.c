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
//Write a function that downloads a file
void UploadFile(const char *filename)
{
    if(FileTypeChecker(filename))
    {
        printf("File type not allowed");
    }
    else
    {
        //upload file
    }
}