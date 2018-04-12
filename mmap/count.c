//gcc  count.c -o  count  -lrt -pthread
 
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>

int *count = 0;
int main(int argc, char const *argv[])
{

	int nloop = atoi(argv[1]);
	sem_t mutex;
	sem_init(&mutex, 1, 1);
	setbuf(stdout, NULL);
	count = mmap(NULL, 1024 * 1024 * 40, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	if (fork() == 0) {
		int i;
		for (i = 0; i < nloop; i++) {//usleep(2);
			//sem_wait(&mutex);
			printf("child count = %d \n" , (*count)++);
			//sem_post(&mutex);
		}
		exit(0);

	} else {
		int i;
		for (i = 0; i < nloop; i++) {//usleep(2);
			//sem_wait(&mutex);
			printf("parent count = %d \n" , (*count)++);
			//sem_post(&mutex);
		}


	}
	sleep(20);
	wait(NULL);
 	return 0;
}