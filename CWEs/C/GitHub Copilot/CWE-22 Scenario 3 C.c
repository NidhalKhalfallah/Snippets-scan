#include <stdio.h>
#include <string.h>
#include <unzip.h>

const char* WhiteListFolders[] = {"/home/user/Documents", "/home/user/Images", "/home/user/Music"};
//Unzip a file

int main(int argc, char *argv[])
{
    int i;
    int err = 0;
    unzFile uf = NULL;
    char filename_inzip[256];
    unz_global_info gi;
    int len;
    char *filename_withoutpath;
    char *p;

    if (argc < 2)
    {
        printf("Usage: unzip file.zip [file_to_extract] [-d dir_to_extract_to]");
        return 1;
    }

    uf = unzOpen(argv[1]);
    if (uf==NULL)
    {
        printf("Cannot open %s",argv[1]);
        return 1;
    }

    err = unzGetGlobalInfo (uf,&gi);
    if (err!=UNZ_OK)
    {
        printf("Cannot read global info of the zip file");
        return 1;
    }

    for (i=0;i<gi.number_entry;i++)
    {
        err = unzGetCurrentFileInfo(uf,NULL,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);
        if (err!=UNZ_OK)
        {
            printf("Cannot read file info");
            return 1;
        }

        len = strlen(filename_inzip);
        if (filename_inzip[len-1]=='/')
        {
            printf("dir:%s",filename_inzip);
        }
        else
        {
            printf("file:%s",filename_inzip);
        }

        if ((argc>2) && (strcmp(filename_inzip,argv[2])==0))
        {
            break;
        }

        err = unzGoToNextFile(uf);
        if (err!=UNZ_OK)
        {
            printf("Cannot read next file");
            return 1;
        }
    }

    if (i==gi.number_entry)
    {
        printf("File %s not found in the zipfile",argv[2]);
        return 1;
    }

    if (argc>3)
    {
        if (strcmp(argv[3],"-d")==0)
        {
            chdir(argv[4]);
        }
    }

    err = unzOpenCurrentFile(uf);
    if (err!=UNZ_OK)
    {
        printf("Cannot open file");
        return 1;
    }

    p = filename_withoutpath = filename_inzip;