#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int pid1 = fork();
    int pid2 = fork();
    //INSIDE PARENT PROCESS
    if(pid1 != 0 && pid2 != 0){
        int waitPID = 0;
        int status;
        //WAITING FOR CHILD 2
        printf("\nParent: I am going to wait for the process with process ID: %d\n", pid2);

        while(waitPID == 0){
            waitPID = waitpid(pid2, &status, WNOHANG);
        }

        printf("\nParent: Waited for child, the return value of waitpid(): %d\n", waitPID);
        printf("\nParent: The exit code of terminated child: %d\n", WEXITSTATUS(status));
        exit(1);
    }
    //CHILD1
    else if(pid1 == 0 && pid2 != 0){
        printf("\nChild1: My process ID is: %d, and my exit code is 1\n", getpid());
        exit(1);   
    }
    //CHILD 2(EXECUTED AFTER FIRST STATEMENT OF PARENT)
    else if(pid1!= 0 && pid2 == 0){
        printf("\nChild2: My process ID is: %d, and my exit code is 2\n", getpid());
        exit(2);
    }
    //CHILD3
    else{
        printf("\nChild3: My process ID is: %d, and my exit code is 3\n", getpid());
        exit(3);
    }

    return 0;
}