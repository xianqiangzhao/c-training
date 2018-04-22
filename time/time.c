#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

int  main(int argc, char const *argv[])
{
	
	time_t seconds;
	struct tm * tms;
	struct timeval	tv;

	seconds = time(NULL);
	printf("seconds %ld\n", seconds);
	printf("day = %s\n", ctime(&seconds));
	tms = gmtime(&seconds);
	printf("tm_year= %d tm_month = %d tm_day = %d tm_sec = %d tm_min = %d \n", 

	  tms->tm_year + 1900, tms->tm_mon + 1, tms->tm_mday, tms->tm_sec, tms->tm_min);

	gettimeofday(&tv, NULL);
	printf("sec = %d  usec= %d\n", tv.tv_sec, tv.tv_usec);

	time_t now;
	struct tm *timenow;
	char strtemp[255];
	now = time(NULL);
	timenow = localtime(&now);
	printf("recent time is : %s \n", asctime(timenow));
	int i = 0;
	clock_t cl1, cl2, cl1_2, cl2_1;
	cl1 = clock();
	cl2 = times(NULL);
	while(i < 100000000)
		i++;
	//sleep(2);
	cl2_1 = times(NULL);
	cl1_2 = clock();
	printf("clock = %ld CLOCKS_PER_SEC= %ld  sysconf(_SC_CLK_TCK)=%ld\n", cl1, CLOCKS_PER_SEC,  sysconf(_SC_CLK_TCK));
	printf("cl1 = %ld cl1_2= %ld cl2= %ld  cl2_1=%ld\n", cl1, cl1_2,  cl2,  cl2_1);


	return 0;
}