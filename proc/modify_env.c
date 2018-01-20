#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern  char **environ;

int main(int argc, char   *argv[])
{
	
	int j;
	char **ep, **p;	
	clearenv();//清除环境变量
	for(p = argv; *p; p++){
		if (putenv(*p) != 0)
			perror("set env error");
	}

	unsetenv("cjx");//清除指定环境变量

	//输出当前环境变量
	for(ep = environ; *ep != NULL; ep++) {
		puts(*ep);
	}
	return 0;
}