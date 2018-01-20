//apue 67  练习题
//打印文件标识
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void set_fl(int fd, int flag);

int main(int argc, char const *argv[])
{
	int val;
    if (argc != 2)
        perror("usage:a.out <descriptor#>");
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        perror("fcntl error for fd");
        exit(-1);
    }
     switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only\n");
            break;
         case O_WRONLY:
            printf("write only\n");
            break;
         case O_RDWR:
            printf("write read\n");
            break;
        default:
            printf("unknown access mode \n");
            break;
    }
    if (val & O_APPEND)
        printf("append\n");
   if (val & O_NONBLOCK)
        printf("O_NONBLOCK\n");
  if (val & O_SYNC)
        printf("O_SYNC\n");

	exit(0);
}

// set file fl
void set_fl(int fd, int flag) {
	int val;
	fcntl(fd, F_GETFL, 0);
	val |= flag;
	fcntl(fd, F_SETFL, val);
}