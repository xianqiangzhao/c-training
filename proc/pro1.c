#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
int
main(void)
{
	pid_t	pid;
	if ((pid = fork()) < 0) {
		perror("fork error");
	} else if (pid == 0) {		/* first child */
		//进程的执行用户修改	 
 		struct passwd *user;
	    user = getpwnam("nobody");	    
	    setuid(user->pw_uid);
		sleep(10);
		printf("second child, parent pid = %ld\n", (long)getppid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid)	/* wait for first child */
		perror("waitpid error");
	printf("%d %d\n",pid,getpid());

	 
	exit(0);
}
