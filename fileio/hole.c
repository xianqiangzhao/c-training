#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define  RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, char const *argv[])
{
	int fd;
	fd = creat("file.hole", RWRWRW);
	write(fd, buf1, 10);
	lseek(fd, 16384, SEEK_SET);
	write(fd, buf2, 10);

    
	exit(0);
}