#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define  RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
int main(int argc, char const *argv[])
{
	
	umask(0);
	creat("foo",RWRWRW);
	umask( S_IRGRP | S_IWUSR | S_IROTH | S_IWOTH);
	creat("bar",RWRWRW);
    printf("S_IRUSR = %d S_IWUSR= %d S_IRGRP= %d S_IWGRP = %d S_IROTH = %d S_IWOTH = %d RWRWRW=%d \n" ,\
    	S_IRUSR, S_IWUSR, S_IRGRP, S_IWGRP  ,S_IROTH, S_IWOTH, RWRWRW);
	exit(0);
}