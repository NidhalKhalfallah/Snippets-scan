#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* home = getenv("HOME");
    char* filename=argv[1];
    //verify if filename exists in home directory
    if(access(filename, F_OK) == -1){
        printf("File does not exist");
        exit(1);
    }else{
        //verify if filename is executable in home directory
        if(access(filename, X_OK) == -1){
            printf("File not executable");
            exit(2);
        }else{

            char* command = malloc((strlen(home)+strlen(filename)+2)*sizeof(*command));//+2 for / and \0 at the end of string 

            strcpy(command, home);//copy home to command string

            strcat (command, "/");//add / after home

            strcat (command, filename);//add filename to command string

             execlp("bash","bash", "-c",command , NULL ); //execute bash with -c option and argument being the full path of file + arguments given by user. This will execute a script file. 

             free (command); //free memory allocated for command variable.  			    	     	        	      	          	          }}}}}}
