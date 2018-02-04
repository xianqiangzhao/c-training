#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>


void pr_mask(const char *str) {
	sigset_t sigset;
	int error_save;
	error_save = errno;
	if (sigprocmask(0, NULL, &sigset) < 0) 
		perror("sigpromask error");
	printf("%s: ", str);
	if (sigismember(&sigset, SIGINT))
		printf("SIGINT ");
	if (sigismember(&sigset, SIGQUIT))
		printf("SIGQUIT ");
	if (sigismember(&sigset, SIGUSR1))
		printf("SIGUSR1 ");
	if (sigismember(&sigset, SIGALRM))
		printf("SIGALRM ");
	printf("\n ");
	errno = error_save;
}
static void sig_int(int);
int main(int argc, char const *argv[])
{
	
	sigset_t newmask, oldmask, waitmask;
	pr_mask("program start");
	signal(SIGINT, sig_int);
	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);

	//block sigint 
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		perror("sigprocmask error");

	pr_mask("in critical region");

	//pasu,allowing all signals except sigusr1
	if(sigsuspend(&waitmask) != 1)
		//perror("sigsuspend error");

	pr_mask("after return form sigsuspend");
	//reset signal mask
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		perror("SIG_SETMASK error");

	pr_mask("program exit");

	return 0;
}

static void sig_int(int signo) {

	pr_mask("in sig_int");
}
