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
void UploadFile(const char *filename)
{
  FILE *fp;
  fp = fopen(filename, "rb");
  if(fp == NULL)
    {
      printf("File not found\n");
      return;
    }
  fseek(fp, 0, SEEK_END);
  int fileSize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *buffer = (char *)malloc(fileSize);
  fread(buffer, fileSize, 1, fp);
  fclose(fp);
  char *fileName = (char *)malloc(strlen(filename) + 1);
  strcpy(fileName, filename);
  char *fileExtension = (char *)malloc(strlen(filename) + 1);
  strcpy(fileExtension, filename);
  char *fileExtensionPointer = strrchr(fileExtension, '.');
  if(fileExtensionPointer!= NULL)
    {
      *fileExtensionPointer = '\0';
    }
  char *fileNamePointer = strrchr(fileName, '/');
  if(fileNamePointer!= NULL)
    {
      *fileNamePointer = '\0';
    }




  if(FileTypeChecker(filename))
    {
      printf("File is dangerous\n");
      return;
    }
  else
    {
      printf("File is not dangerous\n");
    }
  char *fileNamePointer2 = strrchr(fileName, '.');
  if(fileNamePointer2!= NULL)
    {
      *fileNamePointer2 = '\0';
    }
  char *fileExtensionPointer2 = strrchr(fileExtension, '.');
  if(fileExtensionPointer2!= NULL)
    {
      *fileExtensionPointer2 = '\0';
    }
  char *fileNamePointer3 = strrchr(fileName, '/');
  if(fileNamePointer3!= NULL)
    {
      *fileNamePointer3 = '\0';
    }
  char *fileExtensionPointer3 = strrchr(fileExtension, '/');
  if(fileExtensionPointer3!= NULL)
    {
      *fileExtensionPointer3 = '\0';
    }
  char *fileNamePointer4 = strrchr(fileName, '\\');
