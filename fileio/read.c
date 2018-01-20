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
	fd = open("o.log", O_RDONLY );	
	if (fd == -1) {
		//if (errno != EEXIST)
		perror("open error");
	}
	struct std *p;
	while ((sread = read(fd, &buffer, sizeof(buffer))) > 0 ) {
 		//write(STDOUT_FILENO, buffer.p, 2);
 		p = &buffer;
 		printf("%d  %c\n", p[0], p[0] );
	}
  	exit(0);
}