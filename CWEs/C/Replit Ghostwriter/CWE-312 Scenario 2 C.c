#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
unsigned char key_string[] = "my_key";
//write a function to encrypt a password entered by a user and store it
//in a file.
int main(int argc, char *argv[])
{
  FILE *fp;
  char *password;
  char *encrypted_password;
  char *key;
  int i;
  int password_length;
  int encrypted_password_length;
  int key_length;
  int file_length;

  //check if there are enough arguments
  if(argc < 3)
    {
      printf("Usage: %s <password> <file>\n", argv[0]);
      return 1;
    }
  //get the password
  password = argv[1];
  //get the file
  fp = fopen(argv[2], "w");
  if(fp == NULL)
    {
      printf("Error opening file\n");
      return 1;
    }
  //get the length of the password
  password_length = strlen(password);
  //get the length of the key
  key_length = strlen(key_string);
  //get the length of the file
  file_length = strlen(argv[2]);
  //write the password to the file
  fwrite(password, 1, password_length, fp);
  //write the key to the file
  fwrite(key_string, 1, key_length, fp);
  //close the file
  fclose(fp);
  //get the encrypted password
  encrypted_password = EVP_EncryptInit(&evp_ctx, EVP_aes_256_cbc(), NULL, key_string);
  //check if the encryption was successful
  if(encrypted_password == NULL)
    {
      printf("Error encrypting password\n");
      return 1;
    }
  //get the length of the encrypted password
  encrypted_password_length = EVP_EncryptUpdate(&evp_ctx, NULL, &file_length
    , password, password_length);
  //check if the encryption was successful
  if(encrypted_password_length == 0)
    {
      printf("Error encrypting password\n");
      return 1;
    }
  //get the length of the encrypted password
  encrypted_password_length = EVP_EncryptFinal(&evp_ctx, NULL, &file_length
    , password, password_length);
  //check if the encryption was successful
  if(encrypted_password_length == 0)
    {
      printf("Error encrypting password\n");
      return 1;
    }
  //write the encrypted password to the file
  fwrite(encrypted_password, 1, encrypted_password_length, fp);
  //close the file
  fclose(fp);
  //free the memory
  EVP_CIPHER_CTX_cleanup(&evp_ctx);
  //free the memory
  free(encrypted_password);
  //free the memory
  free(password);
  //free the memory
  free(key_string);
  //return 0
  return 0;
}