#include <stdio.h>
#include <string.h>
#include <unzip.h>

const char* WhiteListFolders[] = {"/home/user/Documents", "/home/user/Images", "/home/user/Music"};
//Unzip a file
int unzip_file(const char* filepath) {
    // check if file is in a whitelisted folder
    int is_whitelisted = 0;
    for (int i = 0; i < sizeof(WhiteListFolders)/sizeof(WhiteListFolders[0]); i++) {
        if (strstr(filepath, WhiteListFolders[i]) != NULL) {
            is_whitelisted = 1;
            break;
        }
    }
    if (!is_whitelisted) {
        printf("Error: file is not in a whitelisted folder.\n");
        return -1;
    }

    // create a buffer to hold the path of the extracted file
    char path_buf[256];
    snprintf(path_buf, sizeof(path_buf), "%s.extracted", filepath);

    // open the zip file
    unzFile zip_file = unzOpen(filepath);
    if (!zip_file) {
        printf("Error: failed to open zip file.\n");
        return -1;
    }

    // get the first file in the archive
    unz_file_info file_info;
    int res = unzGoToFirstFile(zip_file);
    if (res != UNZ_OK) {
        printf("Error: failed to read zip file.\n");
        unzClose(zip_file);
        return -1;
    }
    res = unzGetCurrentFileInfo(zip_file, &file_info, NULL, 0, NULL, 0, NULL, 0);
    if (res != UNZ_OK) {
        printf("Error: failed to read zip file.\n");
        unzClose(zip_file);
        return -1;
    }

    // extract the file
    res = unzOpenCurrentFile(zip_file);
    if (res != UNZ_OK) {
        printf("Error: failed to extract file from zip.\n");
        unzClose(zip_file);
        return -1;
    }
    FILE* extracted_file = fopen(path_buf, "wb");
    if (!extracted_file) {
        printf("Error: failed to create extracted file.\n");
        unzCloseCurrentFile(zip_file);
        unzClose(zip_file);
        return -1;
    }
    char buffer[1024];
    while (1) {
        int bytes_read = unzReadCurrentFile(zip_file, buffer, sizeof(buffer));
        if (bytes_read == 0) break;
        if (bytes_read < 0) {
            printf("Error: failed to extract file from zip.\n");
            fclose(extracted_file);
            unzCloseCurrentFile(zip_file);
            unzClose(zip_file);
            return -1;
        }
        fwrite(buffer, 1, bytes_read, extracted_file);
    }
    fclose(extracted_file);
    unzCloseCurrentFile(zip_file);
    unzClose(zip_file);

    printf("File extracted to %s.\n", path_buf);
    return 0;
}