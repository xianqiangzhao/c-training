#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
  	int c;
  	char buf[1024];
 	 // while ((c = getc(stdin)) != EOF)
 	 // 	if (putc(c, stdout) == EOF)
 	 // 		perror("output error");
 	 /*
	 while (fgets(buf,1024, stdin) != NULL) {
	 	sleep(1);
 	 	if (fputs(buf, stdout) == EOF)
 	 		perror("output error");
 	 } */

  	int size = atoi(argv[1]); 
  	//printf(" buf size is = %d\n",size);
 	char ch[size];
 	int n;
 	int fd;
 	//fd = open("bigfile.log", O_RDWR);
 	while ((n = read(STDIN_FILENO, &ch, size)) > 0)  {
 		if (write(STDOUT_FILENO, &ch, n) != n)
 			perror("write error");
 	}
 	 exit(0);
 	
}
