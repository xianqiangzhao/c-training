#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>
unsigned long long count;
struct timeval end;

void
checktime(char *str)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (tv.tv_sec >= end.tv_sec && tv.tv_usec >= end.tv_usec) {
		printf("%s count = %lld\n", str, count);
		exit(0);
	}
} 

int main(int argc, char const *argv[])
{	
	printf("current nice = %d \n" ,getpriority(PRIO_PROCESS, 0));
	nice(100);
	gettimeofday(&end, NULL);
	end.tv_sec += 1;
	for(;;) {
		if (++count ==0) {
			perror("error ");
			exit(0);
		}
		checktime("pro");
	} 
}