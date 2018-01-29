#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static  void hander(int sig){
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("sec = %d  usec= %d\n", tv.tv_sec, tv.tv_usec);

	printf("get  sigusr1\n" );

}
int main(int argc, char const *argv[])
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("sec = %d  usec= %d\n", tv.tv_sec, tv.tv_usec);

 	signal(SIGUSR1, hander);
	kill(getpid(), SIGUSR1);
	return 0;
}