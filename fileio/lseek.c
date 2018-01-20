//如果使用追加方式打开文件，是否可以从任意位置读,写
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void set_fl(int fd, int flag);

int main(int argc, char const *argv[])
{
	char *buf  = "abcd";
	char *rbuf = malloc(10*sizeof(char));
    char *wbuf = malloc(100*sizeof(char));

    int fd, dupfd;
    fd = open(argv[1], O_RDWR | O_CREAT);
    dupfd = dup(fd);
    sprintf(wbuf, "first fd =%d second fd =%d\n", fd, dupfd);
    if (fd < 0)
     	perror("open error");
	set_fl(fd, O_APPEND);
	write(fd, wbuf, strlen(wbuf));
    write(dupfd, wbuf, strlen(wbuf));
    lseek(fd, 0,SEEK_SET);
    while (read(fd, rbuf, 1) > 0) {
    	 write(STDOUT_FILENO, rbuf, 1);
    	// ;
    }
    close(fd);
    close(dupfd);
    free(rbuf);
    free(wbuf);
	exit(0);
}

// set file fl
void set_fl(int fd, int flag) {
	int val;
	fcntl(fd, F_GETFL, 0);
	val |= flag;
	fcntl(fd, F_SETFL, val);
}