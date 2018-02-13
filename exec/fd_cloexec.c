#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/*
因为stdio out 文件描述符设置了FD_CLOEXEC,
exec函数执行时就会关闭。
执行结果
1关闭（标准输出关闭）ls -l无法将结果显示在标准输出

*/
int main(int argc, char *argv[])
{

    printf("Entering main ...\n");
    int ret = fcntl(1, F_SETFD, FD_CLOEXEC);
    if (ret == -1)
        perror("fcntl error");
    int val;
    val =execlp("ls", "ls","-l", NULL);
    if(val == -1)
        perror("execl error");
    printf("Exiting main ...\n");
    return 0;
}