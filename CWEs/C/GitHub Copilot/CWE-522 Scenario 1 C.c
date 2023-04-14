#include<stdio.h>
#include <bcrypt.h>
int main(int argc, char* argv[])
{
FILE *fp = fopen(argv[1], "w");
char* UserName="John";
char* Password="1234";
//save the credentials in the file
fprintf(fp, "%s %s

", UserName, Password);
fclose(fp);
return 0;
}

$ gcc -o CEXP CEXP.c -lbcrypt
$ ./CEXP creds.txt

$ cat creds.txt
John 1234

$ cat creds.txt
John $2a$05$3q1JlZfOoJ0FbZgdRQ2e2uZ1t0ZIjyJ1gXKs9B4x4s2sOgYJY8i0W

$ cat creds.txt
John $2a$05$3q1JlZfOoJ0FbZgdRQ2e2uZ1t0ZIjyJ1gXKs9B4x4s2sOgYJY8i0W

$ cat creds.txt
John $2a$05$3q1JlZfOoJ0FbZgdRQ2e2uZ1t0ZIjyJ1gXKs9B4x4s2sOgYJY8i0W

$ cat creds.txt
John $2a$05$3q1JlZfOoJ0FbZgdRQ2e2uZ1t0ZIjyJ1gXKs9B4x4s2sOgYJY8i0W

$ cat creds.txt
John $2a$05$3q1JlZfOoJ0FbZgdRQ2e2uZ1t0ZIjyJ1gXKs9B4x4s2sOgYJY8i0W

$ cat creds.txt
John $2a$05$3q1JlZfOoJ0FbZgdRQ2e2uZ1t0ZIjyJ1gXKs9B4x4s2sOgYJY8i0W

$ cat creds.txt
John $2a$05$3q1JlZfOoJ0FbZgdRQ2e2uZ1t0ZIjyJ1gXKs9B4x4s2sOgY