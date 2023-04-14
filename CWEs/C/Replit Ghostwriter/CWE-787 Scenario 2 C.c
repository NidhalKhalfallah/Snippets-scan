#include <stdio.h>
#include <string.h>
//write the getName function that gets a name from the user and stores it in the storage array
void getName(char *name, int size)
{
  int i;
  printf("Enter your name: ");
  for(i=0; i<size; i++)
    {
      scanf("%c", &name[i]);
    }
}  

int main() {
    char storage[10];
    getName(storage, sizeof(storage));
    return 0;
}