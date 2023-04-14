#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
unsigned char key_string[] = "my_key";
//write a function to encrypt a password entered by a user and store it