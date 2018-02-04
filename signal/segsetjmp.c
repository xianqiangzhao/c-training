#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>
/* 执行结果
 starting main:
 starting sig_usr1: SIGUSR1
 in sig_alrm: SIGUSR1 SIGALRM
 finishing sig_usr1: SIGUSR1
 end main:

*/

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
 

static void  sig_usr1(int);
static void  sig_alrm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t  canjump;

int main(int argc, char const *argv[])
{
	if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
		perror("signal sig_usr1 error1");
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		perror("signal sig_alrm error1");
	pr_mask("starting main");
	if (sigsetjmp(jmpbuf, 1)) {
		pr_mask("end main");
		exit(0);
	}
	canjump = 1;
	for(; ;)
		pause();
	 
	return 0;
}
static void sig_usr1(int signo) {

	time_t starttime;
	if (canjump == 0)
		return ;
	pr_mask("starting sig_usr1");
	alarm(3);
	starttime = time(NULL);
	for(;;)
		if (time(NULL) > starttime + 5)
			break;

	pr_mask("finishing sig_usr1");
	canjump = 0;
	siglongjmp(jmpbuf, 1);
} 

static void sig_alrm(int signo) {
	pr_mask("in sig_alrm");

}
