#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	
	pid_t t;

	t = fork();
	
	if (t == 0) {
		// if (setsid() == -1)
		// perror("setsid error");
		if (setpgid(getpid(), 0) == -1) 
			perror("setsid error");
		printf(" child id = %d getpgrp = %d getppid = %d getsid = %d\n", getpid(),getpgrp(), getppid(), getsid(getpid()));
		//sleep(1);
		return (0);
		//sleep(4);
	} else {
		//if (setsid() == -1)
		//perror("setsid error");
		printf(" parent id = %d getpgrp = %d  getppid = %d  getsid = %d\n", getpid(), getpgrp(), getppid(), getsid(getpid()));
	}
	while (waitpid(t, NULL, 0) != t) {	/* wait for first child */
		if (errno != EINTR) {
			break;
		}
	}
	 
	exit(0);
}	