#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
  	int c;
  	while ((c = getc(stdin)) != EOF)
 		if (putc(c, stdout) == EOF)
 			perror("output error");	 
	 
 	 exit(0);
 	
}
