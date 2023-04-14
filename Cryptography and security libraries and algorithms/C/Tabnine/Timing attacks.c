#include <openssl/crypto.h>

const char password[] = "password";
const char user_input[] = "user-input";
const int password_len = strlen(password);
const int user_input_len = strlen(user_input);
// Log the user in if the password and user input match

int main(int argc, char **argv)
{
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <password> <user-input>\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], password))
    {
        fprintf(stderr, "Invalid password\n");
        return 1;
    }
    if (strcmp(argv[2], user_input))
    {
        fprintf(stderr, "Invalid user-input\n");
        return 1;
    }

    printf("Password: %s\n", argv[1]);
    printf("User-input: %s\n", argv[2]);
    return 0;

    return 0;
}