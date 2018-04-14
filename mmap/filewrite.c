#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>
#define max(x,y) ((x) > (y) ? (x) : (y))
int main(int argc, char const *argv[])
{

	int fd,i;
	char *ptr;
	size_t filesize, mmapsize, pagesize;
	if (argc != 4){
		perror("usage: filewrite <pathname> <filesize> <mmapsize>");
		exit(1);
	}
	filesize = atoi(argv[2]);
	mmapsize = atoi(argv[3]);
	fd = open(argv[1], O_RDWR|O_CREAT | O_TRUNC , S_IRWXU);
	if (fd == -1) {
		perror("open error");
		exit;
	}

	lseek(fd, filesize -1, SEEK_SET);
	write(fd,"a", 1);
    ptr = mmap(NULL, mmapsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    pagesize = sysconf(_SC_PAGESIZE);
	printf("pagesize  = %d\n", pagesize);

	for (i = 0; i < max(filesize, mmapsize); i+= pagesize) {
		printf("ptr[%d] = %c\n", i, ptr[i]);
		ptr[i] = 1;
		printf("ptr[%d] = %c\n", i + pagesize -1, ptr[i+pagesize -1]);
		ptr[i + pagesize -1] = 1;
	}
	printf("ptr[%d] = %c\n", i, ptr[i]);
 
 	return 0;
}