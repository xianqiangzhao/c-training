#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main(int argc, char const *argv[])
{
	if (argc != 3) {
        fprintf(stderr, "Usage:%s  <write content>  <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
   	char  *w = (char *)argv[1];
  	char  *filename = (char *)argv[2];
  	int  fd;
  	int n;
  	fd = open(filename, O_CREAT|O_RDWR);
  	if (fd < 0)
  		perror("open file error");
  	//printf(" buf size is = %d\n",size);
  	struct stat statbuf;
  	fstat(fd, &statbuf);
 	int filesize;
 	filesize = statbuf.st_size/1024/1024;
 	printf("%d  k\n", filesize);
 	n = strlen(w);
 	while (filesize <= 100) {
 	 	if (write(fd, w, n) != n)
 			perror("write error");
 		fstat(fd, &statbuf);
 		filesize = statbuf.st_size/1024/1024;

 	}
 	 exit(0);
 	
}
