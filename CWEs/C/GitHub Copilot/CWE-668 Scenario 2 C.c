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
void read_chat(struct Chat chat) {
    printf("Family: %s", chat.family.name);
    printf("Members: ");
    for (int i = 0; i < chat.family.num_members; i++) {
        printf("%s ", chat.family.members[i]);
    }
    printf("Content: %s", chat.content);
}