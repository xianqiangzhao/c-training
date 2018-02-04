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
void sig_int(int sig) {
	//在信号处理中，会阻塞该信号。当信号处理结束后，会解除，
	//也会再次执行信号处理程序，但是多个该信号的情况下，只会处理一次。
	pr_mask("in  sig_int ");  
	printf("get SIGALRM \n");
	sleep(4);           //等待新的信号发生


}


int main(int argc, char const *argv[])
{
	 
	pr_mask("start ");	 
	pause();
	pr_mask("end  main ");

	return 0;
}
