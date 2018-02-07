#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
 父进程先于子进程结束，子进程就会被init 进程收养。
 形成孤儿进程。
 [root@MiWiFi-R3-srv proc]# ps  -ef | grep orphan
root     21138     1  0 15:45 pts/1    00:00:00 ./orphan
root     21160 21002  0 15:47 pts/1    00:00:00 grep orphan

*/

int main(int argc, char const *argv[])
{
	
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		//child 
		printf("i'm child pid= %d\n", getpid());
		pause();
	}

	printf("i'm father pid= %d exit\n", getpid());

	return 0;
}