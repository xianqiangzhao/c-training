//gcc  process_mutex.c -o  process_mutex  -lrt -pthread
 
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <pthread.h>

#ifndef _POSIX_THREAD_PROCESS_SHARED
#error "this platform does not supporrt process shared mutex"
#endif 

#define NUM 4
int temp = 0 ;

struct _shared
{
	pthread_mutex_t *sum_mutex;
	int * shared_sum;
}    ;
struct _shared  p_map , *p_map1,* shared_map;
   
int process_fn() {
	int i;			
	for (i = 0; i < 2; i++){
		pthread_mutex_lock(p_map1->sum_mutex); //如果注释掉，shared_sum 的结果将是不正确的。因为父子进程共享的shared_sum
		*(p_map1->shared_sum) += 1;
		pthread_mutex_unlock(p_map1->sum_mutex);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int i , *ip;
 	ip = &i;

	void * pt;
	pthread_mutex_t   mutex;
	int sum = 0;
 	pt = mmap(NULL, sizeof(p_map), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
 	bzero(&p_map, sizeof(p_map));
	p_map.sum_mutex = (pthread_mutex_t * )pt;
	p_map.shared_sum = (int  * )(pt + 4);
	p_map1 = &p_map;
	memcpy(pt, &p_map1, sizeof(p_map));
	//shared_map = &p_map;
	//shared_sum = (int * ) (p_map + 3); //这句打开是结果是20000000 ，父子进程共享这个指针。
	//shared_sum = &temp; //这句打开是结果是10000000 也就是父子进程的 shared_sum 没有共享。
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(p_map.sum_mutex, &attr);
	if (fork() == 0){
		process_fn();
		exit(0);
	}else {
		process_fn();
	}
	wait(NULL);
	printf(" in the end the shared sum: %d  ", *p_map1->shared_sum);
	return 0;
}
