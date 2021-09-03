#include <stdio.h> 
int main() 
{
    int pid, status, childPid; 
    printf("I'm the parent process and my PID is %d\n", getpid() ); 
    pid = fork();  /* Duplicate */ 
    if ( pid!=0 ) {/* Branch based on return value from fork() */ 
        printf("I'm the parent process with PID %d and PPID %d\n", 
           getpid(), getppid() ); 
        childPid = wait( &status );  /* Wait for a child to terminate. */ 
        printf(" A child with PID %d terminated with exit code %d \n", 
             childPid, status >> 8 ); 
    } else {
        printf("I'm the child process with PID %d and PPID %d \n", 
             getpid(), getppid() ); 
        exit(42);  /* Exit with a silly number */ 
    } 
    printf("PID %d terminates \n", getpid() ); 
}

