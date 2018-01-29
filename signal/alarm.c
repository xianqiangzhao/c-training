#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int j;
static  void hander(int sig){
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("sec = %d  usec= %d\n", tv.tv_sec, tv.tv_usec);

	printf("get  sigalrm %d\n", j);
	//我的电脑 执行结果 get  sigalrm 286486130 
	exit(0);
}

int main(int argc, char const *argv[])
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	printf("sec = %d  usec= %d\n", tv.tv_sec, tv.tv_usec);

 	signal(SIGALRM, hander);
 	alarm(1);
	for (;;) {
		 j++;
		 if(j == 1000000) {
		 	printf("j == 1000000 \n");
		 }
	}


 	return 0;

}