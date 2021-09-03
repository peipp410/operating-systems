#include <stdio.h>

int main(){
	int pid;
	printf("I'm the original process with PID %d and PPID %d.\n",  getpid(), getppid());
	pid = fork();
	if (pid != 0){
		printf("I'm the parent process with PID %d and PPID %d. \n", getpid(), getppid());
		printf("My child's PID is %d\n", pid );
	}
	else{
		sleep(5);
		printf("I'm the child process with PID %d and PPID %d. \n", getpid(), getppid());
	}
	printf("PID %d terminates.\n", getpid());
	return 0;
}
