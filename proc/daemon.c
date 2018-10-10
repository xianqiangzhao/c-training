#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("pid = %d\n", getpid());
	daemon(0, 1);
	printf("daemon pid = %d\n", getpid());
	while(1) {
		sleep(1);
		printf("%s\n", "waiting");
	}
	return 0;
}