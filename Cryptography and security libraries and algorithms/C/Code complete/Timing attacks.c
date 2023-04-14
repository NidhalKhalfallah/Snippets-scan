#include <openssl/crypto.h>

const char password[] = "password";
const char user_input[] = "user-input";
const int password_len = strlen(password);
const int user_input_len = strlen(user_input);
// Log the user in if the password and user input match
int login(const char *user_input, const char *password) {
    if (strcmp(user_input, password) == 0) {
        printf("Login successful");
        return 1;
    } else {
        printf("Login failed");
        return 0;
    }
}

 // Encrypt the password with AES-256 using a key derived from user input and log the user in if the encrypted password matches the encrypted user input.  The salt is used to prevent rainbow table attacks on passwords.  If you are not familiar with this, ask your TA or instructor for clarification.  You can use OpenSSL's EVP_BytesToKey() function to derive keys from passwords and salts.  This should be very easy to do because we have all of our information available here (the password, salt, etc).  

 int main(int argc, char *argv[]) {

     unsigned char key[32];                           // 256 bit key buffer that will hold our derived key after it has been generated by EVP_BytesToKey().   We need 32 bytes because AES-256 uses a 256 bit key which is 32 bytes long.   Note: A 128 bit AES-128 would require 16 bytes instead of 32 bytes as AES-256 requires a 256 bit key!   See http://www.openssl.org/docs/crypto/EVP_BytesToKey.html#details for more info on how this works!

     unsigned char iv[16];                            // IV buffer that will hold our initialization vector after it has been generated by OpenSSL's RAND_bytes().   We need 16 bytes because we are using an algorithm that operates on blocks of data (like CBC) which require an IV of size equal to the block size (in this case 128 bits = 16 bytes).  See https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Initialization_vector for more info on how IVs work!

     const EVP_CIPHER *cipher = NULL;                  // Cipher object containing cipher details such as mode, block size, etc... see https://www.openssl.org/docs/manmaster/apps/encryption-.html#ENCRYPTION-OFFLINE for more info on what these objects contain!

     int len = 0;                                      // Length value returned by OpenSSL functions when encrypting or decrypting data so we can know exactly how much data was written during encryption / decryption process respectively without having to call fwrite() multiple times and allocate memory each time based off length returned by each call