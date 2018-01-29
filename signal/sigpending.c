#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_quit(int );

int main(int argc, char const *argv[])
{
	
	sigset_t newmask, oldmask, pendmask;
	if (signal(SIGINT, sig_quit))
		perror("install sigquit error");
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0 )
		perror("sigblock error");

	sleep(5);

	if(sigpending(&pendmask) < 0)
		perror("pendmask error");
	if (sigismember(&pendmask, SIGINT))
		perror("\n sigint pengding");
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		perror("\n sigsetmask error");
	printf("sigint unblock \n");
	sleep(5);
	exit(0); 
}

static void sig_quit(int signo) {
	printf("caught sigint\n");
}
