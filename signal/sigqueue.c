#include <sys/types.h>  
#include <sys/unistd.h>  
#include <sys/stat.h>  
#include <sys/wait.h>  
#include <signal.h>  
#include <stdio.h>  
#include <stdlib.h>  
/*
copy from http://blog.csdn.net/c1194758555/article/details/52848114
实时信号会排队，保证每次信号都能被信号处理程序执行。
实施信号时队列方式进行管理的。

*/
#define ERR(msg) { \
    fprintf(stderr,"%s\n",msg); \
    exit(-1); \
}  
  
void print(int sig,siginfo_t *info,void *exits)  
{  
    printf("signal is %d,valur is %d ppid is %d\n",sig,info->si_value.sival_int,info->si_pid);  
  
    if(!info->si_value.sival_int) exit(0);  
}  
  
int main(int argc,char *argv[])  
{  
    pid_t pid;  
    sigset_t set,old_set;  
  
    if((pid = fork()) == 0){
        printf("%d\n",getpid());
        struct sigaction action;  
        if(sigaction(SIGINT,&action,NULL))  
            ERR("get aignal fail");  
        sigemptyset(&set);  
        sigaddset(&set,SIGRTMIN);  
        sigaddset(&set,SIGRTMIN + 1);  
        sigaddset(&set,SIGINT);  
        sigprocmask(SIG_BLOCK,&set,&old_set);  
        action.sa_mask = set;  
        action.sa_flags = SA_SIGINFO;  
        action.sa_sigaction = print;  
        if(sigaction(SIGRTMIN,&action,NULL) || sigaction(SIGRTMIN + 1,&action,NULL) ||
         sigaction(SIGINT,&action,NULL))  
            ERR("sigaction add fial");  
  
        while(1)  
            sigsuspend(&old_set); //用旧的信号代替已屏蔽的新的信号集  
    }  
    else {  
                printf("%d\n",getpid());

        union sigval val;  
        int sta;  
        sleep(1);  
  
        // val.sival_int = 1;  
        // sigqueue(pid,SIGRTMIN + 1,val);  
  
        // val.sival_int = 2;  
        // sigqueue(pid,SIGRTMIN,val);  
  
        // val.sival_int = 5;  
        // sigqueue(pid,SIGRTMIN,val);  
  
        // val.sival_int = 3;
        // sigqueue(pid,SIGINT,val);  
  
        // val.sival_int = 4;  
        // sigqueue(pid,SIGINT,val);  
  
        // val.sival_int = 4;  
        // sigqueue(pid,SIGRTMIN,val);  
  
        wait(&sta);  
  
        printf("child exit ");  
        exit(0);  
    }  
  
}  