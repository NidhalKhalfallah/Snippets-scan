#include <stdio.h>
#include <time.h>
//Write a function to create a session for a user

int main()
{
  int user_id;
  int session_id;

  printf("Enter user id: ");
  scanf("%d", &user_id);
  printf("Enter session id: ");
  scanf("%d", &session_id);

  printf("%d %d\n", user_id, session_id);
  return 0;
}