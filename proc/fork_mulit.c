#include <sys/types.h>  
#include <sys/unistd.h>  
#include <errno.h>  
#include <sys/wait.h>  
#include <signal.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  


//static volatile  i = 1;
 int  istack = 2;
int main(int argc, char const *argv[])
{
	
	 
	pid_t pid;
	int forknum = 2;
	int child; 
	setbuf(stdout, NULL);
 	pid = fork();
	pid = fork();

	printf("pid = %d ppid =%d \n ", getpid(), getppid());
	// while ((child = wait(NULL)) != -1 ) {
	// 	printf("child = %d ppid =%d %s   istack=%d \n", child,getppid(),
	//   	 (pid == 0 ? "(child)" : "parent"),  istack);
	// 	continue;
	// }
	
	exit(0);
}