#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_int(int signo) {
	if (signo == SIGINT)
		printf("SIGINT interrupt ,%d\n", SIGINT);
	else if ( signo == SIGQUIT)
		printf("SIGQUIT interrupt %d\n", SIGQUIT);
	else if ( signo == SIGTERM)
		printf("SIGTERM interrupt %d\n", SIGTERM);
}

int main(int argc, char const *argv[])
{
	
	sigset_t pendmask, oldmask, zeromask;
	struct  sigaction sa; 
 	sigfillset(&pendmask);
 	sa.sa_flags = 0;
	sa.sa_handler = sig_int;
	sa.sa_mask = pendmask;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
 	printf("block all \n");
 	sigprocmask(SIG_BLOCK, &pendmask, &oldmask);
 	raise(SIGUSR1);
 	raise(SIGQUIT);
 	raise(SIGINT);
 	raise(SIGTERM);
 	sleep(2);
	printf("unblock   \n");
 	sigprocmask(SIG_SETMASK, &oldmask, &oldmask);
 	printf("exit\n");

	return 0;
}