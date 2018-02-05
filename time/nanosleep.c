#include <sys/types.h>  
#include <sys/unistd.h>  
#include <errno.h>  
#include <sys/wait.h>  
#include <signal.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  


static void sig_handler(int sig) {
	 ;
}

int main(int argc, char const *argv[])
{
	
	struct timeval start, finish;
	struct  timespec request, remain;
	struct sigaction sa;
	int s;
	request.tv_sec = 10;
	request.tv_nsec = 8888;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler;
	sigaction(SIGINT, &sa, NULL);
	gettimeofday(&start, NULL);
    for (;;){
    	s = nanosleep(&request, &remain);
    	if (s == -1 &&  errno != EINTR)
    		perror("nanosleep");
    	gettimeofday(&finish, NULL);
    	printf("slept for: %9.6f secs\n", finish.tv_sec - start.tv_sec + (finish.tv_usec - start.tv_usec) / 1000000.0);
    	if (s == 0) {
    		printf("exit for \n");
    		break;
    	}
    	printf("remaining:%2ld.%09ld\n", (long) remain.tv_sec, remain.tv_nsec);
    	request = remain;
    }
 	printf("sleep complete \n");

	return 0;
}