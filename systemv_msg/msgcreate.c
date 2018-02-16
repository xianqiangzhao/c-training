#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h> 

#define MSG_R 0400 /* read permission */
#define MSG_W 0200 /* write permission */

#define SVMSG_MODE (MSG_R | MSG_W | MSG_R >>3 | MSG_R >>6)

typedef unsigned long ulong_t;
struct msgbuf
{
    long mtype;
    char mtext[100];
};

int main()
{
    int msqid;
    struct msqid_ds info;
    struct msgbuf buf;
    if((msqid = msgget(IPC_PRIVATE,SVMSG_MODE|IPC_CREAT)) == -1)
    {
        perror("msgget() error");
        exit(-1);
    }
    int i;
    //write
    for (i = 1; i < 11; i++) { 
        buf.mtype = i;
        snprintf(buf.mtext, sizeof(buf.mtext), "buf %d \n", i);
        if(msgsnd(msqid,&buf, sizeof(buf.mtext),0) == -1)
        {
            perror("msgsnd() error");
            exit(-1);
        }
    }
    system("ipcs -q");
    //read这里不会删除该队列中的消息。
    //内核重起或者显示删除一个消息队列时，该消息队列才会真正被删除
    for (i = 1; i < 11; i++) {
        memset(&buf, 0, sizeof(buf));
        msgrcv(msqid, &buf, sizeof(buf.mtext), i, IPC_NOWAIT);
        printf("read: %s", buf.mtext);
        msgctl(msqid,IPC_RMID,NULL);  //删除消息队列
       
    }
    system("ipcs -q");
    exit(0);
}
