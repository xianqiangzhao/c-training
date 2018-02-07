#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
 在父进程执行wait之前，子进程就已经终止，该子进程的会保留一条记录。
 由init 进程移除。

[root@MiWiFi-R3-srv proc]# ps -ef | grep zombie
root     21184 21002  0 15:51 pts/1    00:00:00 ./zombie
root     21185 21184  0 15:51 pts/1    00:00:00 [zombie] <defunct>
root     21197 21002  0 15:51 pts/1    00:00:00 grep zombie

父进程结束后，子进程的信息会被init 清理掉。

*/

int main(int argc, char const *argv[])
{
	
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		//child 
		printf("i'm child pid= %d exit\n", getpid());
		exit(0);
   	}
   	printf("i'm father pid= %d \n", getpid());
   	sleep(120);

	return 0;
}