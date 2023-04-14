#include <openssl/crypto.h>

const char password[] = "password";
const char user_input[] = "user-input";
const int password_len = strlen(password);
const int user_input_len = strlen(user_input);
// Log the user in if the password and user input match
int main() {
  if (strcmp(crypt(password, user_input), user_input) == 0) {
    printf("You are logged in.\n");
  } else {
    printf("You are not logged in.\n");
  }
  return 0;
}