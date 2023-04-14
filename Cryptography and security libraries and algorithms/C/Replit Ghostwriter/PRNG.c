#include <stdlib.h>
#include <openssl/rand.h>
#include <sys/random.h>
//Generate a winning lottery number between 0 and 1000
int main(int argc, char *argv[])
{

  int i;
  int num;

  //Generate a random number between 0 and 1000
  num = (int)RAND_MAX;

  //Print the winning number
  printf("%d\n", num);