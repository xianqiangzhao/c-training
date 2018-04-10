#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	mqd_t mqd;
	void *ptr;
	size_t len;
	int prio;
	char buf[10] = "abcdef";
	mqd = mq_open(argv[1], O_CREAT | O_WRONLY);
	mq_send(mqd, buf, 10, 1);

	
	return 0;
}