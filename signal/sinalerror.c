// 不可重入函数测试
//在信号处理函数和main 处理过程中，相互影响。导致不正确的执行结果。
 //gcc sinalerror.c -lcrypt  -o sinalerror

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <signal.h>

static char *str2;
static int handled = 0;
static void handler(int sig) {
    crypt(str2, "xx");
    handled++;
    //sleep(20);
    printf("catch sinale %d\n", handled);
}

int main(int argc, char   *argv[])
{
  
  char  *cr1;
  int callNum, mismatch;
  struct sigaction sa;
  if (argc != 3) {
      perror("usage str1 str2 \n");
      exit(1);
  }
  str2 = argv[2];
  cr1 = strdup(crypt(argv[1], "xx"));
  if (cr1 == NULL) {
      perror("crypt error");
      exit(1);
  }
  //sigemptyset(&sa.sa_mask);
  sigfillset(&sa.sa_mask); // 信号处理函数执行时，屏蔽所有信号，除了sigkill sigstop;
  sa.sa_flags = 0;
  sa.sa_handler = handler;
  if (sigaction(SIGINT, &sa, NULL) == -1)  {
      perror("sigaction error");
      exit(1);
  }
 
  //无限循环
  for (callNum = 1, mismatch = 0; ; callNum++) {
    //对参数1 进行加密，同样的加密方式，因为信号处理函数而结果不同。
    if (strcmp(crypt(argv[1], "xx"), cr1) != 0) {
        mismatch++;
        printf("mismatch on call %d (mismatch=%d handled=%d)\n", callNum, mismatch, handled);
    }

  }

  return 0;
}