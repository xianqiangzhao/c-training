#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern  char **environ;

int main(int argc, char const *argv[])
{
	
	 char **ep;
	 for(ep = environ; *ep != NULL; ep++) {
	 	puts(*ep);

	 }
	return 0;
}