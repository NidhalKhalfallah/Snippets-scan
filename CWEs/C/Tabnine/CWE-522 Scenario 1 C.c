#include<stdio.h>
#include <bcrypt.h>
int main(int argc, char* argv[])
{
FILE *fp = fopen(argv[1], "w");
char* UserName="John";
char* Password="1234";
//save the credentials in the file
    if(fp!=NULL)
    {
        fprintf(fp,"UserName=%s\n",UserName);
        fprintf(fp,"Password=%s\n",Password);
        fclose(fp);
        return 0;

        }
    else
    {
        return 1;

        