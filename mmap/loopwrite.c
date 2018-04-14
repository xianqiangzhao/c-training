//gcc  loopwrite.c  -g  -o  loopwrite  -lrt -pthread

/*
./loopwrite  100000  1 
执行结果
...
pr[8185] = a
pr[8186] = a
pr[8187] = a
pr[8188] = a
pr[8189] = a
pr[8190] = a
pr[8191] = a
Segmentation fault
mmap 分配内存是按照pagesize 分配的。
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>

int main(int argc, char const *argv[])
{

	if (argc != 3) {
		perror("usage: loopwrite <loop> <mmapsize>");
		exit(1);
	}
	char put[30] = "";
	int nloop = atoi(argv[1]);
	int size = atoi(argv[2]);
	char *pr;
  	setbuf(stdout, NULL);
	pr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	int i;
	for (i = 0; i < nloop; i++) {
		pr[i] = 'a';
		snprintf(put,30, "pr[%d] = %c\n" , i, pr[i] );
		write(1, put, 30);
 	}

 	return 0;
}