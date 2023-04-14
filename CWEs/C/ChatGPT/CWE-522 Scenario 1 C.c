#include<stdio.h>
#include <bcrypt.h>
int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    char* UserName = "John";
    char* Password = "1234";
    //save the credentials in the file
    fprintf(fp, "Username: %s\nPassword: %s", UserName, Password);
    fclose(fp);
    return 0;
}
//Note that this code does not encrypt the password in any way, and it is generally not recommended to store passwords in plain text.