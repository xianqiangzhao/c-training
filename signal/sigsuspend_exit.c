#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>

volatile sig_atomic_t quitflag;

static void sig_int(int signo) {
	if (signo == SIGINT)
		printf("\n interrupt \n");
	else if ( signo == SIGQUIT)
		quitflag = 1; 

}

int main(int argc, char const *argv[])
{
	
	sigset_t newmask, oldmask, zeromask;
	signal(SIGINT, sig_int);
	signal(SIGQUIT, sig_int);
	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

	while (quitflag == 0)
		sigsuspend(&zeromask);
	quitflag = 0;
	sigprocmask(SIG_SETMASK, &oldmask, NULL);
	puts(strsignal(SIGQUIT));
	return 0;
}