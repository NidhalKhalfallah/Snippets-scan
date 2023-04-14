#include <stdio.h>
#include <string.h>
#include <unzip.h>

const char* WhiteListFolders[] = {"/home/user/Documents", "/home/user/Images", "/home/user/Music"};
//Unzip a file

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    printf("Unzipping %s\n", argv[1]);
    int i;
    unzFile uf= unzOpen(argv[1]);
    if (uf==NULL)
    {
        printf("Error opening %s\n", argv[1]);
        return 0;
    }
    unz_global_info64 gi;
    unz_file_info64 file_info;
    char filename_inzip[256];
    char* filename_without_path;
    unzGetCurrentFileInfo64(uf,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);
    filename_without_path=filename_inzip;
    char *filepath=strrchr(filename_without_path,'\\');
    if (filepath)
        filepath++;
    else
        filepath=filename_without_path;
        printf("%s\n", filepath);
        for (i=0; i < sizeof(WhiteListFolders)/sizeof(char*); i++)

        {
            unzLocateFile(uf,&filename_inzip[0],&file_info,WhiteListFolders[i]);
            printf("%s\n", filename_inzip);
        }
    unzClose(uf);
    return 0;
    unzCloseCurrentFile(uf);
    return 0;

    return 0;
}