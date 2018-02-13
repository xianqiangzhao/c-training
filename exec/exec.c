#include <unistd.h>
#include <stdio.h>
/*
用exec函数可以把当前进程替换为一个新进程，且新进程与原进程有相同的PID。exec名下是由多个关联函数组成的一个完整系列，

头文件<unistd.h>
extern char **environ; 
原型：
int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg, ..., char * const envp[]);
int execve(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
*/
int main(int argc, char *argv[])
{
	 
	char *envp[]={"PATH=/tmp", "USER=lei", "STATUS=testing", NULL};
	char *argv_execv[]={"echo", "excuted by execv", NULL};
	char *argv_execvp[]={"echo", "executed by execvp", NULL};
	char *argv_execve[]={"env", NULL};
	/*
	if(fork()==0) {
		if(execl("/bin/echo", "echo", "executed by execl", NULL)<0)
			perror("Err on execl");
	}
	if(fork()==0) {
		if(execlp("echo", "echo", "executed by execlp", NULL)<0)
			perror("Err on execlp");
	}
	if(fork()==0) {
		if(execle("/usr/bin/env", "env", NULL, envp)<0)
			perror("Err on execle");
	}
	if(fork()==0) {
		if(execv("/bin/echo", argv_execv)<0)
			perror("Err on execv");
	}
	if(fork()==0) {
		if(execvp("echo", argv_execvp)<0)
			perror("Err on execvp");
	}
	if(fork()==0) {
		if(execve("/usr/bin/env", argv_execve, envp)<0)
			perror("Err on execve");
	}
	*/
	/*
	printf("entering main process---\n");
    if (execl("/bin/ls","ls","-l",NULL) < 0) {
    	perror("execl error\n");
    }
    printf("exiting main process ----\n");
	*/
	if(fork()==0) {
	    char *argv1[] = {"22","zhaoxianqiang1",NULL};
	    if(execvp("echo",argv1) == -1)
	        perror("execl error");
	    printf("exiting main process ----\n");
	}
	if(fork()==0) {
	    if(execve("/usr/bin/env", argv_execve, envp)<0)
			perror("Err on execve");
	}
    return 0;
 
}