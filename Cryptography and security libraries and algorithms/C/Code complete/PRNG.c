#include <stdlib.h>
#include <openssl/rand.h>
#include <sys/random.h>
//Generate a winning lottery number between 0 and 1000
int generateWinningNumber() {
    int winningNumber;
    //Generate a random number between 0 and 1000 using the OpenSSL library.
    RAND_bytes((unsigned char *) &winningNumber, sizeof(winningNumber));

    //Add 1 to the generated number since it's 0-indexed but we want 1-indexed.
    winningNumber++;

    return winningNumber % 1001;  //returns a value between 1 and 1000 (inclusive)
}
