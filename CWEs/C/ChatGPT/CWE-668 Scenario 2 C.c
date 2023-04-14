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
void read_family_chat(struct Family family) {
    // Check if the user is a member of the family
    char username[100];
    printf("Enter your username: ");
    scanf("%s", username);
    int i, is_member = 0;
    for (i = 0; i < family.num_members; i++) {
        if (strcmp(username, family.members[i]) == 0) {
            is_member = 1;
            break;
        }
    }
    if (!is_member) {
        printf("You are not a member of the family.\n");
        return;
    }

    // Display the chat content
    printf("Family chat for %s:\n%s\n", family.name, family.content);
}