#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
//Define a function to create a file that contains private information
void create_file(char *filename, char *content)
{
FILE *fp;
fp = fopen(filename, "w");
if (fp == NULL)
{
printf("Error: %s", strerror(errno));
exit(1);
}
fprintf(fp, "%s", content);
fclose(fp);
}