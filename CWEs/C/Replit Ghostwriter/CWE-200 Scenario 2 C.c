#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* home = getenv("HOME");
    char* filename=argv[1];
    //verify if filename exists in home
    if(access(home, F_OK)!= 0)
      {
        fprintf(stderr, "Error: %s does not exist\n", home);
        exit(1);
      }
    else
      {
        char* filepath=strcat(home, "/");
        filepath=strcat(filepath, filename);
        //verify if file exists
        if(access(filepath, F_OK)!= 0)
          {
            fprintf(stderr, "Error: %s does not exist\n", filepath);
            exit(1);
          }
        else
          {

            //open file
            FILE* file=fopen(filepath, "r");
            if(file==NULL)
              {
                fprintf(stderr, "Error: %s does not exist\n", filepath);
                exit(1);
              }
            else
              {
                //read file
                char* buffer=malloc(BUFFER_SIZE);
                int i=0;
                while(fgets(buffer, BUFFER_SIZE, file)!=NULL)
                  {
                    i++;
                    printf("%s", buffer);
                  }
                free(buffer);
                fclose(file);
                printf("\n");
                printf("%d lines read\n", i);
              }
          }
      }
    return 0;
}