#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
// need all these

int main(int argc, char *argv[]) {
    // print statements
    printf("\033[1;31m"); // made the color red(bold)
    
    printf("\nThe last 4 commands were the following:\n"); // Essentially, what we have is: Print the last four(4) commands
    
    printf("%s\n\n", argv[1]); //need in order to print the last 4 commands. Need argv[1] here
    // need %s
    
   
    pid_t fq = fork(); // Essentially: forking a child
    if (fq == -1){
        fprintf(stderr, "Essentially, forking of the child has failed."); //(similar to labs/assignments)
        return 1;
    }

    else if(fq==0){ // Essentially we have: The child successfully forked
        printf("\033[0;31mDetailed list of all content of the current directory\033[1;34m\n");
        // regular color red and then blue(bold) for the directory info.
        execlp ("ls", "ls", "-la", NULL); // need or wont show a detailed list of all content of the current directory
        // The following essentially does: All of the files in the current directory with the add'l info. are shown when it executes a command
        //Executes a command that shows all of the files in the current directory with add'l information
        //Note: ls -l gives you various info. like permissions, owner of the file, size of the file or directory (in bytes), date and time of modification
        //Note: ls -a shows you hidden files as well. Hidden files are the files beginning with a dot so (.)
        printf ("Excelp has essentially failed\n");
        // failure
        exit(1); //exit
        
    }

    // have wait
    wait(NULL); // Essentially: Parent process waits for the child process's execution to terminate before leaving 'exit'
    
    return 0;
}
