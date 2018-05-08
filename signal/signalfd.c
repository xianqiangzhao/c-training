#include <sys/signalfd.h>  
#include <signal.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>
/*
from 
https://blog.csdn.net/gettogetto/article/details/52487331

*/
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)  
  
int  
main(int argc, char *argv[])  
{  
    sigset_t mask;  
    int sfd;  
    struct signalfd_siginfo fdsi;  
    ssize_t s;  
  
    sigemptyset(&mask);  
    sigaddset(&mask, SIGINT);  
    sigaddset(&mask, SIGQUIT);  
  
    /* 阻塞信号以使得它们不被默认的处理试方式处理 */  
  
    if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1)  
        handle_error("sigprocmask");  
  
    sfd = signalfd(-1, &mask,  SFD_NONBLOCK | SFD_CLOEXEC);// SIGINT or SIGQUIT 信号
    if (sfd == -1)  
        handle_error("signalfd");  
  
    for (;;) {  
        s = read(sfd, &fdsi, sizeof(struct signalfd_siginfo));  
        if ( s == -1 && errno == EAGAIN) {            
            continue;
        }
        if (s != sizeof(struct signalfd_siginfo))  
            handle_error("read1111");  
  
        if (fdsi.ssi_signo == SIGINT) {  
            printf("Got SIGINT\n");  
        } else if (fdsi.ssi_signo == SIGQUIT) {  
            printf("Got SIGQUIT\n");  
            exit(EXIT_SUCCESS);  
        } else {  
            printf("Read unexpected signal\n");  
        }  
    }  
}  