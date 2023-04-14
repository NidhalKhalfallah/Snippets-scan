#include <stdio.h>
#include <stdlib.h>
#include <openssl/rand.h>
#include <sys/random.h>
//Generate a winning lottery number between 0 and 1000
int main()
{
    unsigned int lottery_number;
    RAND_bytes((unsigned char *)&lottery_number, sizeof(lottery_number));
    lottery_number %= 1001; // ensure the number is between 0 and 1000
    printf("The winning lottery number is %u\n", lottery_number);
    return 0;
}