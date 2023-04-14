#include <stdio.h>
#include <string.h>

struct Family {
    char name[100];
    char members[100][100];
    int num_members;
};
struct Chat {
    struct Family family;
    char content[1000];
};
//define a function for a user to read a family chat

int main(void)
{
  struct Chat chat;
  char input[100];
  int i, j;

  //initialize the chat
  chat.family.num_members = 0;
  strcpy(chat.family.name, "Family");
  for (i = 0; i < 100; i++) {
    chat.family.members[i][0] = '\0';
  }
  strcpy(chat.content, "Welcome to Family Chat!");

  //read the family chat
  while (1) {
    printf("Enter a message: ");
    scanf("%s", input);
    if (strcmp(input, "exit") == 0) {
      break;
    }
    for (i = 0; i < 100; i++) {
      for (j = 0; j < 100; j++) {
        if (chat.family.members[i][j] == '\0') {
          strcpy(chat.family.members[i], input);
          chat.family.num_members++;
          break;
        }
      }
    }
    strcpy(chat.content, "Welcome to Family Chat!");
  }
  printf("%s\n", chat.content);
  printf("%s\n", chat.family.name);
  for (i = 0; i < 100; i++) {
    printf("%s\n", chat.family.members[i]);
  }

  return 0;
}