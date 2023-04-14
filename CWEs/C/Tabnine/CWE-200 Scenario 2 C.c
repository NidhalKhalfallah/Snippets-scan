#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* home = getenv("HOME");
    char* filename=argv[1];
    //verify if filename exists in home
    struct stat st;
    if (stat(filename, &st) == -1) {
        printf("File %s does not exist\n", filename);
        return -1;
    }
    if (st.st_mode & S_IFDIR) {
        printf("%s is a directory\n", filename);
        return -1;
    }
    if (st.st_mode & S_IFREG) {
        printf("%s is a regular file\n", filename);
        return -1;
    }
    if (st.st_mode & S_IFCHR) {
        printf("%s is a character device\n", filename);
        return -1;
    }
    if (st.st_mode & S_IFBLK) {
        printf("%s is a block device\n", filename);
        return -1;
    }
    if (st.st_mode & S_IFIFO) {
        printf("%s is a FIFO\n", filename);
        return -1;
    }
    if (st.st_mode & S_IFLNK) {
        printf("%s is a symbolic link\n", filename);
        return -1;
    }
    if (st.st_mode & S_IFSOCK) {
        printf("%s is a socket\n", filename);
        return -1;
    }
    