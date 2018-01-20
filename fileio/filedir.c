#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	char buf[100];
	if (chdir("/tmp") < 0)
		perror("chdir failed");
	if (getcwd(buf, 100) == NULL )
		perror("getcwd error");
	printf("%s\n", buf);
	exit(0);
}
