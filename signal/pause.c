#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
 
static  int i =0; //
static void signalHandler(int sig) {
	if (sig == SIGINT) {
		printf("  sigint \n");
	}
}
int main(int argc, char const *argv[])
{
	
	int j;
	if(signal(SIGINT, signalHandler) == SIG_ERR) {
		perror("install sig error");
	} 
	pause (); 

	printf("con ...\n");
	return 0;
}