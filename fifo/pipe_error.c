#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
/*
执行结果

caught SIGPIPE
write to pipe error
在向管道写入数据时，至少应该存在某一个进程，
其中管道读端没有被关闭，否则就会出现上述错误（管道断裂,进程收到了SIGPIPE信号，默认动作是进程终止）
*/
static void sig_quit(int signo) {
    printf("caught SIGPIPE\n");
}

main()
{
    int pipe_fd[2];
    pid_t pid;
    char r_buf[4];
    char* w_buf;
    int writenum;
    int cmd;
    signal(SIGPIPE, sig_quit); 
    memset(r_buf,0,sizeof(r_buf));
    if(pipe(pipe_fd)<0)
    {
        printf("pipe create error\n");
        return -1;
    }
     
    if((pid=fork())==0)
    {
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        sleep(10);  
        exit(0);
    }
    else if(pid>0)
    {
    sleep(1);  //等待子进程完成关闭读端的操作
    close(pipe_fd[0]);
    w_buf="111";
    if((writenum=write(pipe_fd[1],w_buf,4))==-1)
        printf("write to pipe error\n");
    else    
        printf("the bytes write to pipe is %d \n", writenum);
     
    close(pipe_fd[1]);
    exit(0);
    }   
}