#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	 
	void *ptr;
 	char buf[10] = "abcdef";
	void *p, *pt;
	p = buf;
	pt = malloc(1024);
	bzero(pt, 1024);
	memcpy(pt, p,sizeof(buf) - 8);
	char *c = (char *)pt;
	*(char *) p = '1';
	
	printf("%c \n" , *c);
	free(pt); 
	return 0;
}