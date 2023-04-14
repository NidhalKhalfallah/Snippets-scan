#include<stdio.h>
#include <bcrypt.h>
int main(int argc, char* argv[])
{
FILE *fp = fopen(argv[1], "w");
char* UserName="John";
char* Password="1234";
//save the credentials in the file
fprintf(fp, "%s\n", UserName);
fprintf(fp, "%s\n", Password);
fclose(fp);