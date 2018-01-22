#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char const *argv[])
{
	
	struct utsname uts;
	if(uname(&uts) == -1) {
		perror("error");
	}
	printf(" node name %s\n", uts.nodename);
	printf(" system name %s\n", uts.sysname);
	printf(" release   %s\n", uts.release);
	printf(" version   %s\n", uts.version);
	printf(" machine   %s\n", uts.machine);
	#ifdef _GNU_SOURCE
	printf("domain name %s\n", uts.domainname);
	#endif
	return 0;
}