#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
 
static  int i =0; //
static void signalHandler(int sig) {
	if (sig == SIGINT) {
		printf("  sigint \n");
		pause ();
	} else if (sig == SIGUSR1){

		printf("sigusr1 \n");
		sleep(3);
		i = 1;
	} 
}
int main(int argc, char const *argv[])
{
	
	int j;
	if(signal(SIGINT, signalHandler) == SIG_ERR) {
		perror("install sig error");
	} 
	if(signal(SIGUSR1, signalHandler) == SIG_ERR) {
		perror("install sig error");
	}
	for (j = 1;;j++) { 
		printf("%d\n", j);
		if (i == 1) {
			sleep(2);
			i = 0;
		}
		//sleep(3);
	}

	return 0;
}