//pwrite 是 lseek + write 的组合，是原子操作。
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int fd;
	fd = open("tmp.log", O_RDONLY);
	if (fd == -1)
		perror("open file error");
	char buf[10];
	char *p = "\n";
	//read from 4 
	pread(fd, buf, 10, 4);
	printf("%d %d", strlen(buf), strlen(p));
	write(STDOUT_FILENO, buf,strlen(buf));
	write(STDOUT_FILENO, p, strlen(p)); 
	close(fd);

	return 0;
}