#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd;
	ssize_t sread;
 	struct std
	{
		int a;
		char p;
	} buffer;
	buffer.a = 100;
	buffer.p = 'a';
 	fd = open("o.log", O_RDWR | O_CREAT | O_TRUNC);	
	if (fd == -1) {
		//if (errno != EEXIST)
		perror("open error");
	}
	if (write(fd, &buffer, sizeof(buffer)) == -1 ) {
		perror("write error");

 	}
  	exit(0);
}