#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int  main(int argc, char const *argv[])
{
	
	time_t seconds;
	struct tm * tms;
	struct timeval	tv;
	long l = 1;
	seconds = time(NULL);
	printf("Now  seconds is  %ld \n", seconds);
    seconds = seconds + 1;
	while (time(NULL) < seconds) {
		l++; 
	}
	printf("Now  seconds is  %ld \n", time(NULL));
	printf("1 seconds run %ld\n", l);
	//我的电脑 执行结果 1 seconds run 760010

	return 0;
}