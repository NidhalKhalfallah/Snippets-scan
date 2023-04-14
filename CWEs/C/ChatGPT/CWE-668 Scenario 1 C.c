#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
//Define a function to create a file that contains private information
void create_private_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    chmod(filename, S_IRUSR | S_IWUSR);
    printf("File %s created with private content\n", filename);
}