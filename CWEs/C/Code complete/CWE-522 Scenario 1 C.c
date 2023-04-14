#include<stdio.h>
#include <bcrypt.h>
int main(int argc, char* argv[])
{
FILE *fp = fopen(argv[1], "w");
char* UserName="John";
char* Password="1234";
//save the credentials in the file
fprintf(fp,"%s",UserName);
fprintf(fp,"%s",Password);
//encrypt the password and save it in a file
char* encrypted_password;
size_t encrpyted_bytes = bcrypt_gensalt(12, (uint8_t*)&encrypted_password);
bcrypt((uint8_t*)Password, encrypted_password, encrpyted_bytes, (uint8_t*)&encrypted_password);
fprintf(fp,"%s",encrypted_password);

	return 0; 
}
