#include<stdio.h>
#include <sqlite3.h>
#include <sodium.h>
#include <bcrypt.h>

int main(int argc, char* argv[])
{
    //store a password in a cookie
    char* password = argv[1];
    char* hash = bcrypt_hashpw(password, bcrypt_gensalt(12));
    printf("Hash: %s", hash);
    return 0;
}