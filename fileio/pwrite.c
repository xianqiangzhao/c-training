//pwrite 是 lseek + write 的组合，是原子操作。
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int fd;
	fd = open("tmp.log", O_RDWR | O_CREAT | O_TRUNC);
	if (fd == -1)
		perror("open file error");

	char write_buffer[] = "zhaoxianqiang";
	char write_change[] = "jiahe";
	write(fd, write_buffer, strlen(write_buffer));
	//change xianqiang to jiahe
	pwrite(fd, write_change, strlen(write_change), 4);

	return 0;
}