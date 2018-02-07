#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
	
	int i,j;
	long sum;
	for(i = 0;i < 40000; i++) {
		for (j = 0;j < 40000; j++){
			sum += i * j;
		}
	}
	printf("sum = %ld\n", sum);
	return 0;
}