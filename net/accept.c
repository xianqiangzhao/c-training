#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <sys/wait.h>  
#include <stdio.h>  
#include <string.h> 
#include <unistd.h> 
#define PROCESS_NUM 20
/*
base  https://pureage.info/2015/12/22/thundering-herd.html
*/
int main()  
{  
    int fd = socket(PF_INET, SOCK_STREAM, 0);  
    int connfd;
    int pid;  
    char sendbuff[1024];  
    struct sockaddr_in serveraddr;  
    serveraddr.sin_family = AF_INET;  
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);  
    serveraddr.sin_port = htons(8080);  
    bind(fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));  
    listen(fd, 1024);
    int i,readlen;
    char recvBuff[1024];
    bzero(sendbuff, 1024);
    bzero(recvBuff, 1024);

    for(i = 0; i < PROCESS_NUM; i++)  
    {  
        int pid = fork();  
        if(pid == 0)
        {  
            while(1)
            {  
                connfd = accept(fd, (struct sockaddr*)NULL, NULL);
                
                readlen = read(connfd, recvBuff, sizeof(recvBuff));
                
                recvBuff[readlen] = 0;
                if(write(STDIN_FILENO, recvBuff, readlen)< 0 )
                {
                    perror("write error");
                 }
                sprintf(sendbuff, "process %d accept success!\n", getpid());

                write(STDIN_FILENO, sendbuff, strlen(sendbuff));

                //head
                sprintf(sendbuff, "HTTP/1.0 200 OK\r\n");
 
                //server
                sprintf(sendbuff, "%sServer: ZHAOXIANQIANG V1.0\r\n", sendbuff);
                sprintf(sendbuff, "%sConnection: close\r\n", sendbuff);

                //content-type
                sprintf(sendbuff, "%sContent-Type: text/html\r\n", sendbuff);
 
                sprintf(sendbuff, "%sContent-Length: %d\r\n\r\n", sendbuff, strlen("hi tinyhttpd\r\n"));
                 //content
                sprintf(sendbuff, "%shi tinyhttpd\r\n", sendbuff);  
                if (send(connfd, sendbuff, strlen(sendbuff), 0) < 0 ) {
                    perror("send error");
                }
                close(connfd);


            }  
       }  
    }  
    int status;
    while(wait(&status));
    return 0;  
} 