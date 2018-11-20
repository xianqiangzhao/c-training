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

 int main(int argc, char const *argv[])
{

 
	void * ptr  = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	printf("ptr = %p\n", ptr);
	munmap((char *)ptr + 100, 128);
	printf("ptr = %p\n", ptr);

 	return 0;
}