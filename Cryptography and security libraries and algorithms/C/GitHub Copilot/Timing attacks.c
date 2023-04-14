#include <openssl/crypto.h>

const char password[] = "password";
const char user_input[] = "user-input";
const int password_len = strlen(password);
const int user_input_len = strlen(user_input);
// Log the user in if the password and user input match
if (password_len == user_input_len &&
    CRYPTO_memcmp(password, user_input, password_len) == 0) {
  // Log the user in
}