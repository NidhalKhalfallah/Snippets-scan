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

int main(int argc, char *argv[])
{
    FILE *f;
    char buf[1000];
    struct Chat chat;
    int i;
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    f=fopen(argv[1],"r");
    if (!f) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    while (fgets(buf,1000,f)) {
        chat.content[0]=0;
        i=0;
        while (buf[i]!='\0') {
            if (buf[i]==''|| buf[i]=='\t') {
                chat.content[i]=0;
            } else {
                chat.content[i]=buf[i];
            }
            i++;
        }
        chat.content[i]=0;
        chat.num_members=0;
        i=0;
        while (buf[i]!='\0') {
            if (buf[i]==''|| buf[i]=='\t') {
                chat.members[chat.num_members][0]=0;
            } else {
                chat.members[chat.num_members][0]=buf[i];
            }

            i++;
        }
        chat.num_members++;
        chat.family.name[0]=0;

        i=0;
        while (buf[i]!='\0') {
            if (buf[i]==''|| buf[i]=='\t') {
                chat.family.members[chat.num_members][0]=0;
            } else {
                chat.family.members[chat.num_members][0]=buf[i];
            }

            i++;
        }
        chat.family.members[chat.num_members][0]=0;
        chat.family.num_members++;
        chat.content[0]=0;

    


        printf("%s\n",chat.content);
        printf("%s\n",chat.family.name);
        printf("%s\n",chat.family.members[0]);
        printf("%d\n",chat.family.num_members);
        printf("%d\n",chat.num_members);
        printf("%d\n",chat.content[0]);
        printf("%d\n",chat.family.num_members);
        printf("%d\n",chat.family.members[0][0]);
        printf("%d\n",chat.family.members[0][1]);