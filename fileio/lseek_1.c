//文件描述符复制后，是否共享写验证
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void set_fl(int fd, int flag);

int main(int argc, char const *argv[])
{
	
	int fd1, fd2, fd3;
	fd1 = open("tmp.log", O_RDWR | O_CREAT | O_TRUNC);
	fd2 = dup(fd1);
	fd3 = open("tmp.log", O_RDWR);
	write(fd1, "Hello,", 6);
	write(fd2, "world,", 6);
	lseek(fd2, 0, SEEK_SET);
	write(fd1, "HELLO,", 6);
	write(fd3, "Gidday", 6); 
	//执行结果 Giddayworld,   
	exit(0);
}
 