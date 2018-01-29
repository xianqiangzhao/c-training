#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

unsigned 
int sleep1(int sec);
static  void hander(int sig){
	 
}

int main(int argc, char const *argv[])
{

	sleep1(3);
 	return 0;

}

unsigned 
int sleep1(int sec) {

	if (signal(SIGALRM, hander) == SIG_ERR)
		return sec;
	alarm(sec);
	pause();
	return (alarm(0));

}