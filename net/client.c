/* --- client.c --- */
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <signal.h>

static void sig(int sig) {

	int status, pid;
	//pid = wait(&status);
	//printf("exited, pid =%d\n", pid);
	
	// {
	//   if (WIFEXITED(status)) {
	//        printf("exited, status=%d\n", WEXITSTATUS(status));
	//    } else if (WIFSIGNALED(status)) {
	//        printf("killed by signal %d\n", WTERMSIG(status));
	//    } else if (WIFSTOPPED(status)) {
	//        printf("stopped by signal %d\n", WSTOPSIG(status));
	//    } else if (WIFCONTINUED(status)) {
	//        printf("continued\n");
	//    }
	// }

}
int main(int argc, char *argv[])
{ 
	int sockfd = 0, n = 0;
	char recvBuff[1024];
	struct sockaddr_in serv_addr;

	if(argc != 3)
	{
		printf("\n Usage: %s <ip of server>  <port>\n",argv[0]);
		return 1;
	}

	memset(recvBuff, '0',sizeof(recvBuff));
	//signal(SIGCHLD, sig);
	
	int i = 0, pid = 0;
    for (; i < 1 ; i ++){

    	if ((pid = fork()) == 0) {
    		int times = 1, count = 0;
 			for (; count < times; count++) {
	 			if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
				{
					printf("\n Error : Could not create socket \n");
					exit(1);
				}

				memset(&serv_addr, '0', sizeof(serv_addr));
				serv_addr.sin_family = AF_INET;
				serv_addr.sin_port = htons(atoi(argv[2]));
				if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
				{
					printf("\n inet_pton error occured\n");
					return 1;
				}

				if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
				{
					perror("");
 					return 1;
				}
				send(sockfd, "client\n", strlen("client\n"), 0);
				close(sockfd);
				while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
				{
					recvBuff[n] = 0;
					if(write(STDIN_FILENO, recvBuff,n)< 0 )
					{
						printf("\n Error : Fputs error\n");
					}
				}
			 
	 			if(n < 0)
				{
					printf("\n Read error \n");
				}
				if(n == 0) 
				{
					printf("\n server  close\n");
				}
			}
			exit(0);
		}
    }  
    int status;
	while ( (waitpid(-1, &status, WNOHANG) ));
	while(1);
 	return 0;
}