#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	mqd_t mqd;
	struct mq_attr attr;
	int len;
	int prio;
	char buf[10];
	mqd = mq_open(argv[1], O_RDWR);
	mq_getattr(mqd, &attr);
	len = mq_receive(mqd, buf, attr.mq_msgsize, &prio);
	printf("read %d bytes data = %s ", len, buf);
	
	return 0;
}