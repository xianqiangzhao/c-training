#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

__thread int num = 1;//线程隔离变量，main 和子线程不会互相影响

void * worker(void * arg) {
	while(1) {
		num = num << 1 + 1; 
		printf("thread:%u  num: %d %p \n", pthread_self(), num, &num);
		sleep(1);
	}
}

int main(int argc, char const *argv[])
{
	
	pthread_t tid;
	int ret;
	int num = 4;
	while(num-- >=0 ) {
		if ((ret = pthread_create(&tid, NULL, worker, NULL)) !=0 ) {
			return 1;
		}
	}
	while(1) {

		num++;
		printf("main: %d %p \n", num, &num);
		sleep(1);
	}
	return 0;
}