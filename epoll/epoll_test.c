#include <sys/types.h>  
#include <sys/socket.h>  
#include <sys/epoll.h>  
#include <netdb.h>  
#include <string.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <sys/wait.h>  
  
#define MAXEVENTS 64
int  
main (int argc, char *argv[])  
{  
    int sfd, s;  
    int efd;  
    struct epoll_event event;  
    struct epoll_event *events; 
    
    efd = epoll_create(MAXEVENTS);  
    if (efd == -1)  
    {  
        perror("epoll_create");  
        abort();  
    }  
 
    /* Buffer where events are returned */  
    events = calloc(MAXEVENTS, sizeof event);
    /* The event loop */
    while (1)  
    {  
        int n;
        n = epoll_wait(efd, events, MAXEVENTS, 1);  
        if (n == 0) {
            printf("%s\n", "epoll_wait"); ;
        }
         
   }    
    return EXIT_SUCCESS;          
 }  