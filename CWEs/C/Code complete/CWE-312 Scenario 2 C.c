#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
unsigned char key_string[] = "my_key";
//write a function to encrypt a password entered by a user and store it in a file
void encrypt_password(char * password, char * key) {
    EVP_CIPHER_CTX ctx;
    unsigned char ciphertext[1024];
    int len, ciphertext_len;

    //Initialise the encryption operation. IMPORTANT - ensure you use a key
    //buffer bigger than what you intend to encrypt with this code. 
	EVP_EncryptInit(&ctx, EVP_aes_256_cbc(), (unsigned char *)key, NULL);

	//Encrypt your data here 
	EVP_EncryptUpdate(&ctx, ciphertext, &len, (unsigned char *)password , strlen(password));

	//Finalise the encryption. Further data would be written at this stage 
	EVP_EncryptFinal(&ctx, ciphertext + len, &ciphertext_len);

	printf("%s", "Your encrypted password is:");
	for (int i = 0; i < len + ciphertext_len; i++) {
		printf("%02x", ciphertext[i]);
	}