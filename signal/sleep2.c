#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static  jmp_buf  env_alrm;
 
static void sig_alrm(int signo) {
	printf("get sig_alarm\n");
	exit(0);
	//longjmp(env_alrm, 1);
	
}  
 unsigned
 int sleep2(int sec) {

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return sec;
	if (setjmp(env_alrm) == 0) {   //如果不加这段代码，alarm 和pause 之间有一个竞争条件。
		alarm(sec);
		pause();
	}
	return (alarm(0));

}

static  void sig_int(int sig){
	 int i,j;
	 volatile int k;
	 printf("sig_int starting\n");
	 for (i = 0; i < 300000; i++) {
	 	for(j = 0; j< 400; j++) {
	 		//k += i * j;
	 		printf("i = %d j = %d \n", i, j);
	 	}
	 }
	 printf("hander finished\n");
}

int main(int argc, char const *argv[])
{
	unsigned int unslept;
	if (signal(SIGINT, sig_int) == SIG_ERR)
		perror("install sigint error");
	unslept = sleep2(5);
	printf("sleep2 return:%u\n", unslept);
  	return 0;

}
