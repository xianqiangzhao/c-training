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
forknum = 2 时
---------------------------------------
pid = 20949 ppid =20304 parent   istack=2
pid = 20950 ppid =20949 parent   istack=4
 child = 20950 pid=20949  ppid =20304 parent   istack=2
	 pid = 20952 ppid =20950 (child)   istack=8
	 child = 20952 pid=20950  ppid =20949 parent   istack=4

pid = 20951 ppid =20949 (child)   istack=4
 child = 20951 pid=20949  ppid =20304 parent   istack=2
---------------------------------------
进程结构
20304(bash)
	20949 
		20950
		  20952
		20951

forknum =1 时
---------------------------------------
pid = 20978 ppid =20977 (child)   istack=4
 child = 20978 pid=20977  ppid =20304 parent   istack=2
pid = 20977 ppid =20304 parent   istack=2
---------------------------------------
进程结构
20304(bash)
	20977 
		20978	
*/

int  istack = 2;
int main(int argc, char const *argv[])
{
	
	 
	pid_t pid;
	int forknum = 4;
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
				exit(0);		 
				break;
			default:
			 
				break;
		}
	}
	while ((child = wait(NULL)) != -1 ) {
		printf("child = %d pid=%d  ppid =%d %s   istack=%d \n", child,getpid(), getppid(),
	  	 (pid == 0 ? "(child)" : "parent"),  istack);
		continue;
	}
	printf("pid = %d ppid =%d %s   istack=%d \n ", getpid(),getppid(),
	  	 (pid == 0 ? "(child)" : "parent"),   istack);
	exit(0);
}