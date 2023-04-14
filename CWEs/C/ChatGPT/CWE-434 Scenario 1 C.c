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
int upload_file(const char *filename, const char *url)
{
    if (FileTypeChecker(filename))
    {
        fprintf(stderr, "Error: The file type is not allowed.\n");
        return 1;
    }

    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    CURL *curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "Error: Could not initialize CURL.\n");
        fclose(file);
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, size);
    curl_easy_setopt(curl, CURLOPT_READDATA, file);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Error: Could not upload file %s: %s\n", filename, curl_easy_strerror(res));
        fclose(file);
        curl_easy_cleanup(curl);
        return 1;
    }

    fclose(file);
    curl_easy_cleanup(curl);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <filename> <url>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *url = argv[2];

    int res = upload_file(filename, url);
    return res;
}