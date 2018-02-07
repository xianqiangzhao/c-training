#include <sys/types.h>  
#include <sys/unistd.h>  
#include <errno.h>  
#include <sys/wait.h>  
#include <signal.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
/*
执行结果
以下是父进程的输出，子进程各睡10秒后退出。
父进程通过wait函数来等待子进程的状态。当没有子进程被监控时，返回-1.退出 while 循环。

child = 3504 pid=3501  ppid =3344 parent   istack=2  status = 0 
child = 3505 pid=3501  ppid =3344 parent   istack=2  status = 0 
child = 3502 pid=3501  ppid =3344 parent   istack=2  status = 0 
child = 3503 pid=3501  ppid =3344 parent   istack=2  status = 0 
pid = 3501 ppid =3344 parent   istack=2 
*/

int  istack = 2;
int main(int argc, char const *argv[])
{
	
	int  status;
	pid_t pid;
	int forknum = 4;//创建子进程的数目
	int child; 
	setbuf(stdout, NULL);
	for(; forknum > 0 ;forknum--) {
		pid = fork();
		switch (pid) {
			case -1:
				perror("error");
				break;
			case 0:			 
				istack *=2;	
				sleep(10);
				exit(0);//子进程在此正常退出。
				break;
			default:
			 
				break;
		}
	}
	while ((child = wait(&status)) != -1 ) {
		printf("child = %d pid=%d  ppid =%d %s   istack=%d  status = %d \n", child,getpid(), getppid(),
	  	 (pid == 0 ? "(child)" : "parent"),  istack, status);
		continue;
	}
	printf("pid = %d ppid =%d %s   istack=%d \n ", getpid(),getppid(),
	  	 (pid == 0 ? "(child)" : "parent"),   istack);
	exit(0);
}