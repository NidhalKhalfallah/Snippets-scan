//Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <sys/syscall.h>

#define THREAD_NUM 3
#define THREAD_NUM_MAX 100
#define THREAD_NUM_MIN 1
#define THREAD_NUM_INC 1
#define THREAD_NUM_DEC 1
#define THREAD_NUM_MAX_INC 1
#define THREAD_NUM_MAX_DEC 1



int main(int argc, char *argv[])
{
  int i;
  int fd;
  int fd_lock;
  int fd_bank;
  int fd_bank_lock;
  int fd_bank_lock_lock;
  int fd_bank_lock_unlock;



  //Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
  fd = open("/dev/mem/bank", O_RDWR);
  if (fd < 0)
    {
      printf("Error: can't open /dev/mem/bank\n");
      exit(1);
    }
  fd_bank = fd;
  fd_bank_lock = fd;
  fd_bank_lock_lock = fd;
  fd_bank_lock_unlock = fd;

  //Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
  fd = open("/dev/mem/bank_lock", O_RDWR);
  if (fd < 0)
    {
      printf("Error: can't open /dev/mem/bank_lock\n");
      exit(1);
    }
  fd_bank_lock_lock = fd;