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
//Write a function that uploads a file

int main(int argc, char *argv[])
{
    if(argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    printf("Uploading %s\n", argv[1]);
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return -1;
    }
    char buf[1024];
    while(fgets(buf, 1024, fp))
    {
        printf("%s", buf);
    }
    fclose(fp);
    return 0;
}