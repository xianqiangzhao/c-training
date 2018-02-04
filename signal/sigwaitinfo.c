#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>
/*
sigwaitinfo(const sigset_t *set, siginfo_t &info)
以同步方式等待 set 中的信号
*/
int main(int argc, char const *argv[])
{
	
	siginfo_t siginfo;
	sigset_t pendmask;
	sigfillset(&pendmask);
	int sig;
	//block all signals except sigkill and sigstop
	sigprocmask(SIG_SETMASK, &pendmask, NULL);

	for(;;) {
		sig = sigwaitinfo(&pendmask, &siginfo);
		if (sig == -1)
			perror("sigwaitinfo error");
		if (sig == SIGUSR1)
			exit(0);
		printf("got signal :%d %s\n",  sig, strsignal(sig));

	}
	return 0;
}