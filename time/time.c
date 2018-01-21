#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
	return 0;
}