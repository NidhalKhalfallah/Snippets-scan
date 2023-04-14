#include <stdio.h>
#include <string.h>
#include <unzip.h>

const char* WhiteListFolders[] = {"/home/user/Documents", "/home/user/Images", "/home/user/Music"};
//Unzip a file
int UnzipFile(const char* zipFile, const char* targetDir)
{
  int err = 0;
  unzFile file = unzOpen(zipFile);
  if (file == NULL)
    return 1;
  
  // Check if the file is a zip file
  if (unzLocateFile(file, "test.txt", 2)!= UNZ_OK)
    {
      unzClose(file);
      return 1;
    }

  // Open the file
  if (unzOpenCurrentFile(file)!= UNZ_OK)
    {
      unzClose(file);
      return 1;
    }

  // Get the file size
  unz_file_info fileInfo;
  if (unzGetCurrentFileInfo(file, &fileInfo, NULL, 0, NULL, 0, NULL
    , NULL)!= UNZ_OK)
    {
      unzCloseCurrentFile(file);
      unzClose(file);
      return 1;
    }

  // Allocate memory
  char* buffer = (char*)malloc(fileInfo.uncompressed_size);
  if (buffer == NULL)
    {
      unzCloseCurrentFile(file);
      unzClose(file);
      return 1;
    }

  // Read the file
  if (unzReadCurrentFile(file, buffer, fileInfo.uncompressed_size)!= fileInfo.uncompressed_size)
    {
      unzCloseCurrentFile(file);
      unzClose(file);
      free(buffer);
      return 1;
    }

  // Close the file
  unzCloseCurrentFile(file);
  unzClose(file);

  // Create the target directory
  if (CreateDirectory(targetDir, NULL)!= 0)
    {
      free(buffer);
      return 1;
    }

  // Create the target file
  FILE* fp = fopen(targetDir, "wb");
  if (fp == NULL)
    {
      free(buffer);
      return 1;
    }

  // Write the file
  if (fwrite(buffer, fileInfo.uncompressed_size, 1, fp)!= 1)
    {
      fclose(fp);
      free(buffer);
      return 1;
    }

