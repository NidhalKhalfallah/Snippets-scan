#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
//Define a function to create a file that contains private information

int main(int argc, char *argv[])
{
  int fd;
  int i;

  // Open the file
  fd = open("/home/jim/Documents/test.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  if (fd == -1)
    {
      perror("open");
      exit(1);
    }
  // Write some data to the file
  for (i = 0; i < 10; i++)
    {
      write(fd, "Hello World!\n", 14);
    }
  // Close the file
  close(fd);
  return 0;
}