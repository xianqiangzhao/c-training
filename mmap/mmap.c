#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>
/*
利用 mmap 打开文件/tmp/data 
参数1 的内容写入到文件（追加写入）
*/

int main(int argc, char const *argv[])
{
	int fd;
	if (argc < 2)
    {
        fprintf(stderr, "Need at least one argument to write to the file\n");
        exit(EXIT_FAILURE);
    }
    if ((fd = open("data", O_RDWR | O_CREAT)) < 0)
    {
    	printf("%s\n","bad file open");
    	exit(1);
    }
    int len = strlen(argv[1]);
    struct stat _stat;
    if (fstat(fd, &_stat) < 0)
    {
		printf("%s\n","bad file stat");
		exit(1);
    }
     if (lseek(fd, len + _stat.st_size-1, SEEK_SET) == -1)
    {
        close(fd);
        perror("Error calling lseek() to 'stretch' the file");
        exit(EXIT_FAILURE);
    }
    if (write(fd, "a", 1) == -1)
    {
        close(fd);
        perror("Error writing last byte of the file");
        exit(EXIT_FAILURE);
    }

    char *addr = mmap(NULL, len + _stat.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        close(fd);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }
    
	memcpy(addr + _stat.st_size, argv[1], len);
	msync(addr, len + _stat.st_size, MS_SYNC);
    printf("fd = %d    %s\n", fd, addr);
    close(fd);
    munmap(addr, len);

	return 0;
}
