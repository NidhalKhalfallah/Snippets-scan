#include <stdlib.h>
#include <openssl/rand.h>
#include <sys/random.h>
//Generate a winning lottery number between 0 and 1000
int main(void) {
    int lotteryNumber;
    getrandom(&lotteryNumber, sizeof(lotteryNumber), 0);
    lotteryNumber = lotteryNumber % 1000;
    printf("Your winning lottery number is %d

", lotteryNumber);
    return 0;
}