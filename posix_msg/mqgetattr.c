#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                       } while (0)
int main(int argc, char   *argv[])
{
	
	mqd_t mqd;
	struct mq_attr attr;
	 attr.mq_maxmsg =30;
	 attr.mq_msgsize = 8192 * 2;
	mqd = mq_open(argv[1], O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, &attr);
	if (mqd == (mqd_t) -1)
       errExit("mq_open");
	//mq_getattr(mqd, &attr);

	printf("mqd_t = %d  max msgs =%d , max bytes/msg =%d currently on queue = %d\n", mqd, attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
 
 	if (mq_unlink(argv[1]) == -1)
        errExit("mq_unlink");
	return 0;
}