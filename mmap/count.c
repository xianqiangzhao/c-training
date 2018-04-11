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
	count = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	if (fork() == 0) {
		int i;
		for (i = 0; i < nloop; i++) {sleep(1);
			//sem_wait(&mutex);
			printf("child count = %d \n" , (*count)++);
			//sem_post(&mutex);
		}
		exit(0);

	} else {
		int i;
		for (i = 0; i < nloop; i++) {sleep(1);
			//sem_wait(&mutex);
			printf("parent count = %d \n" , (*count)++);
			//sem_post(&mutex);
		}


	}
	wait(NULL);
 	return 0;
}