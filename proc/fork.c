#include <sys/types.h>  
#include <sys/unistd.h>  
#include <errno.h>  
#include <sys/wait.h>  
#include <signal.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  


static int  i = 111;

int main(int argc, char const *argv[])
{
	
	int istack = 2;
	pid_t pid;
	pid = fork();
	switch (pid) {
		case -1:
			perror("error");
			break;
		case 0:
			i *=3;
			istack *=3;
			break;
		default:
			//sleep(3);
			break;
	}
	printf("pid = %d %s i= %d, istack=%d \n ", getpid(),
	  	 (pid == 0 ? "(child)" : "parent"), i, istack);
	return 0;
}