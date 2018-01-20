#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd;
	fd = open("o.log", O_RDONLY | O_CREAT );
	if (fd == -1) {
		//if (errno != EEXIST)
		perror("open error");
	}
  	exit(0);
}