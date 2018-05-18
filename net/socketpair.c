#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <error.h> 
#include <errno.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
/*
base http://blog.51cto.com/liulixiaoyao/533469
*/
#define BUF_SIZE 30 
struct data
{
	char string[20];
	int size;
};
 
int main(){
    int s[2];
    int w,r;
    struct data send_data;
    char * sendstring = "This is a test\n";
    memcpy(&send_data.string, sendstring, strlen(sendstring));
    send_data.size = strlen(sendstring);

    void * buf = (void*)calloc(1 , BUF_SIZE);
    pid_t pid;
    if( socketpair(AF_UNIX,SOCK_STREAM,0,s) == -1 ){ 
            printf("create unnamed socket pair failed:%s\n",strerror(errno) ); 
            exit(-1); 
    } 
    pid = fork();
    int len = sizeof(send_data.size) + send_data.size;
    if (pid > 0){
    	//parent write to pipe
		if( ( w = write(s[1] , &send_data , len) ) == -1 ){ 
	        printf("Write socket error:%s\n",strerror(errno)); 
	        exit(-1); 
		}

    } else if (pid == 0 ) {
    	//child  read
	     if( (r = read(s[0], buf , BUF_SIZE )) == -1){ 
	            printf("Read from socket error:%s\n",strerror(errno) ); 
	            exit(-1); 
	   	 }
	    if (r >0)
	    	printf("read data = %s\n", ((struct data * ) buf)->string);
    } else {
    	perror("fork error");
    	exit(1);
    }
    wait(NULL);
 
 }