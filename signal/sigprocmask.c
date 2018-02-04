#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_int(int signo) {
	if (signo == SIGINT)
		printf("SIGINT interrupt ,%d\n", SIGINT);
	else if ( signo == SIGQUIT)
		printf("SIGQUIT interrupt %d\n", SIGQUIT);

}

int main(int argc, char const *argv[])
{
	
	sigset_t pendmask, oldmask, zeromask;
	signal(SIGINT, sig_int);
	signal(SIGQUIT, sig_int);
 	sigfillset(&pendmask);
 	printf("block all \n");
 	sigprocmask(SIG_BLOCK, &pendmask, &oldmask);
 	raise(SIGQUIT);
 	raise(SIGINT);
 	sleep(2);
	printf("unblock   \n");
 	sigprocmask(SIG_SETMASK, &oldmask, &oldmask);
 	printf("exit\n");

	return 0;
}